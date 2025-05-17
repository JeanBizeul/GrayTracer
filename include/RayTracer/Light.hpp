/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** Light
*/

#ifndef RAYTRACER_LIGHT_HPP_
#define RAYTRACER_LIGHT_HPP_

#include <optional>

#include "Math/Point3.hpp"
#include "Math/Vec3.hpp"

namespace RayTracer {
class LightInfo {
 public:
    LightInfo(Math::Point3 color, double intensity)
        : _color(color), _intensity(intensity) {}

    Math::Point3 _color;
    double _intensity;
};

class Light {
 public:
    Light(Math::Point3 position, Math::Vec3 direction, double angle,
          LightInfo lightInfo)
        : _LightInfo(lightInfo),
          _position(position),
          _direction(direction),
          _angle(angle) {}

    const std::optional<LightInfo> hit(Math::Point3 _impact,
                                       Math::Vec3 _faceNormal) const;

 private:
    Math::Point3 _position;
    Math::Vec3 _direction;
    double _angle;

    LightInfo _LightInfo;
};
}  // namespace RayTracer

#endif  // RAYTRACER_LIGHT_HPP_
