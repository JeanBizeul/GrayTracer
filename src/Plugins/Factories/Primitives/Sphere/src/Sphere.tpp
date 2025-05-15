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

<<<<<<< HEAD:src/lib/Factories/Primitives/Square/src/Sphere.tpp
=======
#include "Math/Point3.hpp"
#include "Math/Vec3.hpp"
#include "RayTracer/APrimitive.hpp"
#include "RayTracer/Impact.hpp"
>>>>>>> main:src/Plugins/Factories/Primitives/Sphere/src/Sphere.tpp

namespace RayTracer
{
inline Sphere::Sphere(Math::Point3 center, Math::Vec3 direction, double scale)
    : APrimitive(center, direction, {}, scale)
{
}

<<<<<<< HEAD:src/lib/Factories/Primitives/Square/src/Sphere.tpp
inline bool Sphere::hit(const RayTracer::Ray &ray) const
=======
std::optional<Impact> Sphere::hit(const RayTracer::Ray &ray) const
>>>>>>> main:src/Plugins/Factories/Primitives/Sphere/src/Sphere.tpp
{
    (void)ray;
    return std::nullopt;
}
}  // namespace RayTracer

#endif /* !SPHERE_TPP_ */
