/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#ifndef RAYTRACER_RAY_HPP_
#define RAYTRACER_RAY_HPP_
#include "../Math/Point3.hpp"
#include "../Math/Vec3.hpp"

namespace RayTracer {
class Ray {
 public:
    Ray() = default;

    Ray(Math::Point3 origin, Math::Vec3 direction)
        : _origin(origin), _direction(direction) {
    }

    ~Ray() = default;

    Math::Point3 _origin;
    Math::Vec3 _direction;
};
}  // namespace RayTracer

#endif  // RAYTRACER_RAY_HPP_
