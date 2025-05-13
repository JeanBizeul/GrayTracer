/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** SphereFactory
*/

#ifndef SRC_LIB_FACTORIES_PRIMITIVES_SQUARE_SRC_SPHEREFACTORY_HPP_
#define SRC_LIB_FACTORIES_PRIMITIVES_SQUARE_SRC_SPHEREFACTORY_HPP_
#include <memory>
#include <string>

#include "../../../../../../include/RayTracer/IFactory.hpp"
#include "Sphere.hpp"

namespace RayTracer {
class SphereFactory : public IFactory<RayTracer::Sphere> {
 public:
    SphereFactory() = default;
    ~SphereFactory() = default;

    std::unique_ptr<RayTracer::Sphere> createObject(
        libconfig::Setting &settings) final;
    const std::string &getObjectTag() const final;

 private:
    const std::string _tag = "sphere";
};
}  // namespace RayTracer

#endif  // SRC_LIB_FACTORIES_PRIMITIVES_SQUARE_SRC_SPHEREFACTORY_HPP_
