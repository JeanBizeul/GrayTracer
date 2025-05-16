/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** PlaneFactory
*/

#include "PlaneFactory.hpp"

#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

#include "Math/Point3.hpp"
#include "Math/Vec3.hpp"
#include "RayTracer/FactoryContext.hpp"
#include "RayTracer/Material.hpp"

namespace RayTracer {

void PlaneFactory::init(std::shared_ptr<RayTracer::FactoryContext> fcx) {
    _fcx = fcx;
}

std::unique_ptr<RayTracer::Plane> PlaneFactory::createObject(
    const libconfig::Setting &settings) {
    try {
        auto position = Math::Point3(settings["position"]);
        auto rotation = Math::Vec3(settings["rotation"]);
        double scale = settings["scale"];
        std::unordered_map<std::string, RayTracer::Material> matMap =
            _fcx->get<std::unordered_map<std::string, RayTracer::Material>>(
                "materials");
        std::string material = settings["material"];

        return std::make_unique<RayTracer::Plane>(position, rotation,
                                                  matMap.at(material), scale);
    } catch (const libconfig::SettingException &e) {
        std::cerr << "Error while creating plane: ";
        std::cerr << e.what() << std::endl;
        return nullptr;
    }
}

const std::string &PlaneFactory::getObjectTag() const {
    return _tag;
}
}  // namespace RayTracer

extern "C" {
RayTracer::FactoryReturnType<RayTracer::Plane> FactoryEntryPoint() {
    return std::make_unique<RayTracer::PlaneFactory>();
}
}
