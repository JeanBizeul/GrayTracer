/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** SphereFactory
*/

#ifndef SPHEREFACTORY_HPP_
#define SPHEREFACTORY_HPP_
#include "RayTracer/IFactory.hpp"
#include "Sphere.hpp"

namespace RayTracer {
class SphereFactory : public IFactory<RayTracer::Sphere> {
 public:
    SphereFactory() = default;
    ~SphereFactory() = default;

    virtual std::unique_ptr<RayTracer::Sphere> createObject(
        libconfig::Setting &settings) final;
    virtual const std::string &getObjectTag() const final;

 private:
    const std::string _tag = "sphere";
};
}  // namespace RayTracer

#endif /* !SPHEREFACTORY_HPP_ */
