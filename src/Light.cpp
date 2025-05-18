/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** Light
*/

#include "RayTracer/Light.hpp"

#include <cmath>
#include <optional>

#include "Math/Point3.hpp"
#include "Math/Vec3.hpp"

namespace RayTracer {
const std::optional<LightInfo> Light::hit(Math::Point3 _impact,
                                          Math::Vec3 _faceNormal) const {
    Math::Vec3 dir = (_impact - _position).normalize();

    if (dir.dot(_faceNormal) >= 0)  // Prend les lumières du sens inverse??
        return std::nullopt;

    double angle = _direction.dot(dir);
    double theta = std::cos(_angle * M_PI / 180.0);

    if (angle >= theta)
        return _LightInfo;
    else
        return std::nullopt;
}
}  // namespace RayTracer
