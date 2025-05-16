/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** Plane
*/

#include <math.h>

#include <optional>

#include "Math/Point3.hpp"
#include "Math/Vec3.hpp"
#include "Plane.hpp"
#include "RayTracer/APrimitive.hpp"
#include "RayTracer/Impact.hpp"

namespace RayTracer {
Plane::Plane(Math::Point3 center, Math::Vec3 direction,
             RayTracer::Material &material, double scale)
    : APrimitive(center, direction, {}, material, scale) {}

std::optional<Impact> Plane::hit(const RayTracer::Ray &ray) const {
    (void)ray;
    return std::nullopt;
}
}  // namespace RayTracer
