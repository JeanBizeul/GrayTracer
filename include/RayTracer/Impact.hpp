/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** Impact
*/

#ifndef RAYTRACER_IMPACT_HPP_
#define RAYTRACER_IMPACT_HPP_

#include "Math/Point3.hpp"
#include "Math/Vec3.hpp"

namespace RayTracer {
class Impact {
 public:
    Impact(Math::Point3 point, Math::Vec3 normal, double distance)
        : _point(point), _normal(normal), _distance(distance) {
    }

    Math::Point3 _point;
    Math::Vec3 _normal;
    double _distance;
};
}  // namespace RayTracer

#endif // RAYTRACER_IMPACT_HPP_
