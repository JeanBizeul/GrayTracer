/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** DirectionalLightFactory
*/

#ifndef SRC_PLUGINS_FACTORIES_LIGHT_SRC_LIGHTFACTORY_HPP_
#define SRC_PLUGINS_FACTORIES_LIGHT_SRC_LIGHTFACTORY_HPP_

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
 private:
    std::string _tag = "directional light";
};
}

#endif  // SRC_PLUGINS_FACTORIES_LIGHT_SRC_LIGHTFACTORY_HPP_
