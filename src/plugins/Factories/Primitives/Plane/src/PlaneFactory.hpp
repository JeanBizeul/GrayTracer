/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** PlaneFactory
*/

#ifndef SRC_PLUGINS_FACTORIES_PRIMITIVES_PLANE_SRC_PLANEFACTORY_HPP_
#define SRC_PLUGINS_FACTORIES_PRIMITIVES_PLANE_SRC_PLANEFACTORY_HPP_
#include <memory>
#include <string>

#include "Plane.hpp"
#include "RayTracer/FactoryContext.hpp"
#include "RayTracer/IFactory.hpp"

namespace RayTracer {
class PlaneFactory : public IFactory<RayTracer::Plane> {
 public:
    explicit PlaneFactory() = default;
    ~PlaneFactory() = default;

    void init(std::shared_ptr<RayTracer::FactoryContext> fcx) final;
    std::unique_ptr<RayTracer::Plane> createObject(
        const libconfig::Setting &settings) final;
    const std::string &getObjectTag() const final;

 private:
    const std::string _tag = "plane";
    std::shared_ptr<RayTracer::FactoryContext> _fcx;
};
}  // namespace RayTracer

#endif  // SRC_PLUGINS_FACTORIES_PRIMITIVES_PLANE_SRC_PLANEFACTORY_HPP_
