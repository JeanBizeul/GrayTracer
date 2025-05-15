/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** FactoryContext
*/

#ifndef RAYTRACER_FACTORYCONTEXT_HPP_
#define RAYTRACER_FACTORYCONTEXT_HPP_

#include <string>
#include <unordered_map>
#include <any>

namespace RayTracer {
class FactoryContext {
 public:
    template <typename T>
    void set(const std::string &key, T value);

    template <typename T>
    T &get(const std::string &key);

    template <typename T>
    bool has(const std::string &key) const;
 private:
    std::unordered_map<std::string, std::any> _contextMap;
};
}  // namespace RayTracer

#include "FactoryContext.tpp"

#endif  // RAYTRACER_FACTORYCONTEXT_HPP_
