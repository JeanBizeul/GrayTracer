/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** FactoryLoader
*/

#ifndef RAYTRACER_FACTORYLOADER_TPP_
#define RAYTRACER_FACTORYLOADER_TPP_

#include <filesystem>
#include <iostream>
#include <iterator>
#include <string>

#include "IFactory.hpp"
#include "DLLoader.hpp"

static std::string extractSharedLibName(const std::string &filename) {
    const std::string prefix = "lib";
    const std::string suffix = ".so";

    if (filename.size() < prefix.size() + suffix.size() + 1) {
        std::cerr << "Incorrect shared library file name '"
            << filename << "': too low character count.\n"
            << "Minimum is 'liba.so'" << std::endl;
        return "";
    }
    if (filename.substr(0, prefix.size()) != prefix) {
        std::cerr << "Cannot find prefix '" + prefix + "' in "
            << filename << std::endl;
        return "";
    }
    if (filename.substr(filename.size() - suffix.size()) != suffix) {
        std::cerr << "Cannot find suffix '" + suffix + "' in "
            << filename << std::endl;
        return "";
    }
    return filename.substr(prefix.size(),
        filename.size() - prefix.size() - suffix.size());
}

namespace RayTracer {
FactoryLoader::FactoryLoader(const std::string &sharedLibFolder) {
    std::filesystem::directory_iterator it(sharedLibFolder);

    std::cout << "[FactoryLoader] Loading shared libraries from: "
        << sharedLibFolder << std::endl;
    for (auto file : it) {
        if (file.is_regular_file()
            && extractSharedLibName(file.path().filename()) != "") {
            if (!loadFactory(file.path())) {
                std::cerr << "Shared file "
                    << file.path().filename()
                    << " could not be loaded !" << std::endl;
            }
        }
    }
}

bool FactoryLoader::loadFactory(const std::filesystem::path &path) {
    std::cout << "[FactoryLoader] Trying to load: "
        << path.filename() << std::endl;
    try {
        std::string name = extractSharedLibName(path.filename());
        _sharedLibLoaders.emplace(name,
            std::make_unique<DLLoader<IFactoryBase>>
            (path, "FactoryEntryPoint"));
        auto factory = _sharedLibLoaders[name]->getInstance();
        std::string tag = factory->getObjectTag();

        std::cout << "[FactoryLoader] Detected type: "
            << static_cast<int>(factory->getType())
            << " with tag: " << tag << std::endl;
        switch (factory->getType()) {
            case FactoryType::Light :
                _lights[tag] = std::unique_ptr<IFactory<Light>>(
                    dynamic_cast<IFactory<Light>*>(factory.release()));
                break;
            case FactoryType::Material :
                _materials[tag] = std::unique_ptr<IFactory<Material>>(
                    dynamic_cast<IFactory<Material>*>(factory.release()));
                break;
            case FactoryType::Primitive :
                _primitives[tag] = std::unique_ptr<IFactory<APrimitive>>(
                    dynamic_cast<IFactory<APrimitive>*>(factory.release()));
                break;
        }
        return true;
    } catch (const DLLoaderError &e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
}

template <typename T>
std::unique_ptr<T> FactoryLoader::create(const std::string &tag,
const libconfig::Setting &settings) {
    std::unordered_map<std::string,
        std::unique_ptr<RayTracer::IFactory<T>>> *map = nullptr;

    std::cout << "[FactoryLoader] Creating instance of type "
        << typeid(T).name() << " with tag: " << tag << std::endl;
    if constexpr (std::is_same_v<T, RayTracer::Light>) {
        map = &_lights;
    } else if constexpr (std::is_same_v<T, RayTracer::Material>) {
        map = &_materials;
    } else if constexpr (std::is_same_v<T, RayTracer::APrimitive>) {
        map = &_primitives;
    } else {
        static_assert(sizeof(T) == 0, "Unsupported factory type for create().");
    }
    auto it = map->find(tag);
    if (it == map->end())
        throw std::runtime_error("Unknown factory tag: " + tag);
    return it->second->createObject(settings);
}

}  // namespace RayTracer

#endif  // RAYTRACER_FACTORYLOADER_TPP_
