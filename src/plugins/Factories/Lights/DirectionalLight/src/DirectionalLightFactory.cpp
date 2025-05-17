/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** DirectionalLightFactory
*/

#include "DirectionalLightFactory.hpp"

#include <memory>
#include <iostream>

#include <libconfig.h++>

#include "RayTracer/Light.hpp"

namespace RayTracer {

std::unique_ptr<RayTracer::Light> DirectionalLightFactory::createObject(
    const libconfig::Setting &settings) {
    try {
        auto position = Math::Vec3(settings["position"]);
        auto rotation = Math::Vec3(settings["rotation"]);
        auto color = Math::Vec3(settings["color"]);
        double brightness = settings["range"];
        double angle = settings["angle"];

        return std::make_unique<RayTracer::Light>(position, rotation, angle,
            RayTracer::LightInfo(color, brightness));
    } catch (const libconfig::SettingException &e) {
        std::cerr << "Error while creating directional light: ";
        std::cerr << e.what() << std::endl;
        return nullptr;
    }
}

const std::string &DirectionalLightFactory::getObjectTag() const {
    return _tag;
}

FactoryType DirectionalLightFactory::getType() const {
    return FactoryType::Light;
}

}  // namespace RayTracer

extern "C" {
RayTracer::FactoryReturnType<RayTracer::Light> FactoryEntryPoint() {
    return std::make_unique<RayTracer::DirectionalLightFactory>();
}
}
