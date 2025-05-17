/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** FactoryLoader
*/

#ifndef RAYTRACER_FACTORYLOADER_HPP_
#define RAYTRACER_FACTORYLOADER_HPP_

#include <unordered_map>
#include <string>
#include <filesystem>
#include <memory>

#include <libconfig.h++>

#include "FactoryContext.hpp"
#include "IFactory.hpp"
#include "Light.hpp"
#include "APrimitive.hpp"
#include "Material.hpp"
#include "DLLoader.hpp"

namespace RayTracer {
class FactoryLoader {
 public:
    explicit FactoryLoader(const std::string &sharedLibFolder);
    ~FactoryLoader() = default;

    template <typename T>
    std::unique_ptr<T> create(const std::string &tag,
        const libconfig::Setting &settings);

 private:
    std::unordered_map<std::string,
        std::unique_ptr<DLLoader<IFactoryBase>>> _sharedLibLoaders;

    bool loadFactory(const std::filesystem::path &path);

    std::unordered_map<std::string,
        std::unique_ptr<RayTracer::IFactory
            <RayTracer::Light>>> _lights;

    std::unordered_map<std::string,
        std::unique_ptr<RayTracer::IFactory
            <RayTracer::Material>>> _materials;

    std::unordered_map<std::string,
        std::unique_ptr<RayTracer::IFactory
            <RayTracer::APrimitive>>> _primitives;
};
}  // namespace RayTracer

#include "FactoryLoader.tpp"

#endif  // RAYTRACER_FACTORYLOADER_HPP_
