/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** DirectionalLightFactory
*/

#ifndef SRC_PLUGINS_FACTORIES_LIGHTS_DIRECTIONALLIGHT_SRC_DIRECTIONALLIGHTFACTORY_HPP_
#define SRC_PLUGINS_FACTORIES_LIGHTS_DIRECTIONALLIGHT_SRC_DIRECTIONALLIGHTFACTORY_HPP_

#include <string>
#include <memory>

#include <libconfig.h++>

#include "RayTracer/IFactory.hpp"
#include "RayTracer/FactoryContext.hpp"
#include "RayTracer/Light.hpp"

namespace RayTracer {
class DirectionalLightFactory : public IFactory<RayTracer::Light> {
 public:
    DirectionalLightFactory() = default;
    ~DirectionalLightFactory() = default;

    std::unique_ptr<RayTracer::Light> createObject(
        const libconfig::Setting &settings) final;

    const std::string &getObjectTag() const final;
    FactoryType getType() const final;
 private:
    std::string _tag = "directional light";
};
}  // namespace RayTracer

#endif  // SRC_PLUGINS_FACTORIES_LIGHTS_DIRECTIONALLIGHT_SRC_DIRECTIONALLIGHTFACTORY_HPP_
