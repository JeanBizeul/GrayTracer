/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** IFactory
*/

#ifndef IFACTORY_HPP_
#define IFACTORY_HPP_
#include <libconfig.h++>
#include <memory>

namespace RayTracer {
template <typename T>
class IFactory {
 public:
    virtual ~IFactory() = default;

    virtual std::unique_ptr<T> createObject(libconfig::Setting &settings) = 0;
    virtual const std::string &getObjectTag() const = 0;
};

template <typename T>
using FactoryEntryPoint = std::unique_ptr<RayTracer::IFactory<T>> (*)();
}  // namespace RayTracer

#endif /* !IFACTORY_HPP_ */
