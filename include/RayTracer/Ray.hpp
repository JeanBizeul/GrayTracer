/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#ifndef RAYTRACER_RAY_HPP_
#define RAYTRACER_RAY_HPP_
#include "../Math/Point.hpp"
#include "../Math/Vec.hpp"

namespace RayTracer {
class Ray {
 public:
    Ray() = default;

    Ray(Math::Point<3> origin, Math::Vec<3> direction)
        : _origin(origin), _direction(direction) {
    }

    ~Ray() = default;

    Math::Point<3> _origin;
    Math::Vec<3> _direction;
};
}  // namespace RayTracer

#endif  // RAYTRACER_RAY_HPP_
