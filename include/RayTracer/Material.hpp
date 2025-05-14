/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** Material
*/

#ifndef RAYTRACER_MATERIAL_HPP_
#define RAYTRACER_MATERIAL_HPP_

#include <string>

#include "Math/Vec3.hpp"

namespace RayTracer
{
class Material
{
 public:
    Material() = delete;
    Material(const std::string &name,
        Math::Vec3 ambiantColor,
        Math::Vec3 diffuseColor)
        : _name(name),
        _ambiantColor(ambiantColor),
        _diffuseColor(diffuseColor)
        {};
    ~Material() = default;

    const std::string _name;
    const Math::Vec3 _ambiantColor;
    const Math::Vec3 _diffuseColor;
};

}  // namespace RayTracer

#endif  // RAYTRACER_MATERIAL_HPP_
