/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** SphereFactory
*/

#ifndef SRC_PLUGINS_FACTORIES_PRIMITIVES_SPHERE_SRC_SPHEREFACTORY_HPP_
#define SRC_PLUGINS_FACTORIES_PRIMITIVES_SPHERE_SRC_SPHEREFACTORY_HPP_
#include <memory>
#include <string>

#include "Sphere.hpp"
#include "RayTracer/IFactory.hpp"
#include "RayTracer/FactoryContext.hpp"

namespace RayTracer {
class SphereFactory : public IFactory<RayTracer::Sphere> {
 public:
    explicit SphereFactory() = default;
    ~SphereFactory() = default;

    void init(std::shared_ptr<RayTracer::FactoryContext> fcx) final;
    std::unique_ptr<RayTracer::Sphere> createObject(
        const libconfig::Setting &settings) final;
    const std::string &getObjectTag() const final;

 private:
    const std::string _tag = "sphere";
    std::shared_ptr<RayTracer::FactoryContext> _fcx;
};
}  // namespace RayTracer

#endif  // SRC_PLUGINS_FACTORIES_PRIMITIVES_SPHERE_SRC_SPHEREFACTORY_HPP_
