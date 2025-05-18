/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** SphereFactory
*/

#include "SphereFactory.hpp"

#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

#include "Math/Point3.hpp"
#include "Math/Vec3.hpp"
#include "RayTracer/FactoryContext.hpp"
#include "RayTracer/Material.hpp"
#include "Sphere.hpp"

namespace RayTracer {

void SphereFactory::init(std::shared_ptr<RayTracer::FactoryContext> fcx) {
    if (!fcx) {
        throw std::invalid_argument(
            "FactoryContext passed to SphereFactory is null.");
    }
    _fcx = fcx;
}

std::unique_ptr<RayTracer::APrimitive> SphereFactory::createObject(
    const libconfig::Setting &settings) {
    try {
        // Extract position vector values
        const libconfig::Setting &posArray = settings["position"];
        Math::Point3 position({static_cast<double>(posArray[0]),
                               static_cast<double>(posArray[1]),
                               static_cast<double>(posArray[2])});

        // Extract rotation vector values
        const libconfig::Setting &rotArray = settings["rotation"];
        Math::Vec3 rotation({static_cast<double>(rotArray[0]),
                             static_cast<double>(rotArray[1]),
                             static_cast<double>(rotArray[2])});
        double scale = settings["scale"];
        std::cout << "Starting to treating materials\n";
        std::unordered_map<std::string, RayTracer::Material> matMap =
            _fcx->get<std::unordered_map<std::string, RayTracer::Material>>(
                "materials");
        std::string material = settings["material"];
        return std::make_unique<RayTracer::Sphere>(position, rotation,  // here
                                                   matMap.at(material), scale);
    } catch (const libconfig::SettingException &e) {
        std::cerr << "Error while creating sphere: ";
        std::cerr << e.what() << std::endl;
        return nullptr;
    }
}

const std::string &SphereFactory::getObjectTag() const {
    return _tag;
}

FactoryType SphereFactory::getType() const {
    return FactoryType::Primitive;
}

}  // namespace RayTracer

extern "C" {
RayTracer::FactoryReturnType<RayTracer::APrimitive> FactoryEntryPoint() {
    return std::make_unique<RayTracer::SphereFactory>();
}
}
