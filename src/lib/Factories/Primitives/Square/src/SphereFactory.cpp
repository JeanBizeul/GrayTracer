/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** SphereFactory
*/

#include "SphereFactory.hpp"

#include <iostream>

namespace RayTracer {
std::unique_ptr<RayTracer::Sphere> SphereFactory::createObject(
    libconfig::Setting &settings) {
    try {
        auto position = Math::Point<3>(settings["position"]);
        auto rotation = Math::Vec<3>(settings["rotation"]);
        double scale = settings["scale"];

        return std::make_unique<RayTracer::Sphere>(position, rotation, scale);
    } catch (const libconfig::SettingException &e) {
        std::cerr << "Error while creating sphere: ";
        std::cerr << e.what() << std::endl;
        return nullptr;
    }
}

const std::string &SphereFactory::getObjectTag() const {
    return _tag;
}
}  // namespace RayTracer

extern "C"
{
    RayTracer::FactoryReturnType<RayTracer::Sphere> FactoryEntryPoint()
    {
        return std::make_unique<RayTracer::SphereFactory>();
    }
}
