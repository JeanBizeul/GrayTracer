/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** MaterialFactory
*/

#include "MaterialFactory.hpp"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>

#include "RayTracer/FactoryContext.hpp"
#include "RayTracer/Material.hpp"

#define MATERIAL_FOLDER_PATH "assets/materials/"

Math::Vec3 parseVec3(std::istringstream &iss) {
    double x, y, z;

    iss >> x >> y >> z;
    return Math::Vec3({x, y, z});
}

void parseMtlLine(const std::string &line, RayTracer::Material &material) {
    std::istringstream iss(line);
    std::string label;

    iss >> label;
    if (label == "Kd") {
        material._diffuseColor = parseVec3(iss);
    } else if (label == "Ka") {
        material._ambiantColor = parseVec3(iss);
    } else {
        throw std::runtime_error("unknown label: " + label);
    }
}

static std::unordered_map<std::string, RayTracer::Material> parseMtlFile(
    const std::string filePath) {
    std::unordered_map<std::string, RayTracer::Material> materials;
    std::ifstream file(filePath);
    std::string line;
    RayTracer::Material current("", Math::Vec3(0), Math::Vec3(0));

    if (!file)
        throw std::runtime_error("Could not oppen file " + filePath);
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#')
            continue;

        std::istringstream iss(line);
        std::string label;

        iss >> label;
        if (label == "newmtl") {
            if (!current._name.empty())
                materials.emplace(current._name, current);
            std::string name;
            iss >> name;
            current = RayTracer::Material(name, Math::Vec3(0), Math::Vec3(0));
        } else {
            try {
                parseMtlLine(line, current);
            } catch (std::runtime_error &e) {
                std::cerr << "Error while parsing " + filePath + ": " + e.what()
                          << std::endl;
            }
        }
    }
    return materials;
}

static std::unordered_map<std::string, RayTracer::Material> parseAllMtl() {
    std::filesystem::directory_iterator it(MATERIAL_FOLDER_PATH);
    std::unordered_map<std::string, RayTracer::Material> materials;

    for (auto &file : it) {
        if (file.is_regular_file())
            materials.merge(parseMtlFile(file.path()));
    }
    return materials;
}

namespace RayTracer {

void MaterialFactory::init(std::shared_ptr<RayTracer::FactoryContext> fcx) {
    std::cout << "Loading materials from " + std::string(MATERIAL_FOLDER_PATH) +
                     " : ";
    _materials = parseAllMtl();
    fcx->set<std::unordered_map<std::string, RayTracer::Material>>("materials",
                                                                   _materials);
    std::cout << "OK" << std::endl;
}

std::unique_ptr<RayTracer::Material> MaterialFactory::createObject(
    const libconfig::Setting &settings) {
    try {
        return std::make_unique<RayTracer::Material>(
            _materials.at(settings.lookup("name")));
    } catch (const libconfig::SettingException &e) {
        std::cerr << "Error while creating material: ";
        std::cerr << e.what() << std::endl;
        return nullptr;
    }
}

const std::string &MaterialFactory::getObjectTag() const {
    return _tag;
}

FactoryType MaterialFactory::getType() const {
    return FactoryType::Material;
}

}  // namespace RayTracer

extern "C" {
RayTracer::FactoryReturnType<RayTracer::Material> FactoryEntryPoint() {
    return std::make_unique<RayTracer::MaterialFactory>();
}
}
