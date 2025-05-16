/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** Sphere
*/

#ifndef SPHERE_TPP_
#define SPHERE_TPP_
#include <math.h>

#include <optional>

#include "Math/Point3.hpp"
#include "Math/Vec3.hpp"
#include "RayTracer/APrimitive.hpp"
#include "RayTracer/Impact.hpp"

namespace RayTracer {
Sphere::Sphere(Math::Point3 center, Math::Vec3 direction,
    RayTracer::Material &material, double scale)
    : APrimitive(center, direction, {}, material, scale)
{
}

std::optional<Impact> Sphere::hit(const RayTracer::Ray &ray) const {
    (void)ray;
    return std::nullopt;
}
}  // namespace RayTracer

#endif /* !SPHERE_TPP_ */
