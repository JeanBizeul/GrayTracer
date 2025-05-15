/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** MaterialFactory
*/

#ifndef SRC_PLUGINS_FACTORIES_MATERIAL_SRC_MATERIALFACTORY_HPP_
#define SRC_PLUGINS_FACTORIES_MATERIAL_SRC_MATERIALFACTORY_HPP_

#include <unordered_map>
#include <memory>
#include <string>

#include "RayTracer/IFactory.hpp"
#include "RayTracer/Material.hpp"

namespace RayTracer {
class MaterialFactory : public IFactory<RayTracer::Material> {
 public:
    explicit MaterialFactory(const std::string &materialFilePath);
    ~MaterialFactory() = default;

    std::unique_ptr<RayTracer::Material> createObject(
        const libconfig::Setting &settings) final;

    const std::string &getObjectTag() const final;

 private:
    const std::string _tag = "material";
    std::unordered_map<std::string, RayTracer::Material> _materials;
};
}  // namespace RayTracer

#endif  // SRC_PLUGINS_FACTORIES_MATERIAL_SRC_MATERIALFACTORY_HPP_
