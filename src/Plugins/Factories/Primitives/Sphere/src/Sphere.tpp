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

namespace RayTracer
{
inline Sphere::Sphere(Math::Point3 center, Math::Vec3 direction, double scale)
    : APrimitive(center, direction, {}, scale)
{
}

inline std::optional<Impact> Sphere::hit(const RayTracer::Ray &ray) const
{
    (void)ray;
    return std::nullopt;
}
}  // namespace RayTracer

#endif /* !SPHERE_TPP_ */
