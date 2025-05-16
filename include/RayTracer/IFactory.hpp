/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** IFactory
*/

#ifndef RAYTRACER_IFACTORY_HPP_
#define RAYTRACER_IFACTORY_HPP_

#include <memory>
#include <string>

#include <libconfig.h++>

#include "FactoryContext.hpp"

namespace RayTracer {
template <typename T>
class IFactory {
 public:
    virtual ~IFactory() = default;

    virtual void init(std::shared_ptr<FactoryContext> ctx) {}
    virtual std::unique_ptr<T>
    createObject(const libconfig::Setting &settings) = 0;
    virtual const std::string &getObjectTag() const = 0;
};

template <typename T>
using FactoryReturnType = std::unique_ptr<RayTracer::IFactory<T>>;
}  // namespace RayTracer

#endif  // RAYTRACER_IFACTORY_HPP_
