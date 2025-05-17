/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** FactoryContext
*/

#ifndef RAYTRACER_FACTORYCONTEXT_TPP_
#define RAYTRACER_FACTORYCONTEXT_TPP_

#include <any>
#include <stdexcept>
#include <string>
#include <unordered_map>

namespace RayTracer {
template <typename T>
void FactoryContext::set(const std::string &key, T value) {
    _contextMap[key] = std::make_any<T>(std::move(value));
}

template <typename T>
T &FactoryContext::get(const std::string &key) {
    auto it = _contextMap.find(key);

    if (it == _contextMap.end())
        throw std::runtime_error("Missing key in factory context: " + key);
    return std::any_cast<T &>(it->second);
}

template <typename T>
bool FactoryContext::has(const std::string &key) const {
    auto it = _contextMap.find(key);

    return it != _contextMap.end() && it->second.type() == typeid(T);
}
}  // namespace RayTracer

#endif  // RAYTRACER_FACTORYCONTEXT_TPP_
