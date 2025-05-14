/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** Sphere
*/

#ifndef SPHERE_TPP_
#define SPHERE_TPP_
#include <math.h>

#include "Math/Point3.hpp"
#include "Math/Vec3.hpp"
#include "RayTracer/APrimitive.hpp"

namespace RayTracer
{
Sphere::Sphere(Math::Point3 center, Math::Vec3 direction, double scale)
    : APrimitive(center, direction, {}, scale)
{
}

bool Sphere::hit(const RayTracer::Ray &ray) const
{
    (void)ray;
    return false;
}
}  // namespace RayTracer

#endif /* !SPHERE_TPP_ */
