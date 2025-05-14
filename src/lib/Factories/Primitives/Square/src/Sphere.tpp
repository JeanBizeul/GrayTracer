/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** Sphere
*/

#ifndef SPHERE_TPP_
#define SPHERE_TPP_
#include <math.h>


namespace RayTracer
{
inline Sphere::Sphere(Math::Point3 center, Math::Vec3 direction, double scale)
    : APrimitive(center, direction, {}, scale)
{
}

inline bool Sphere::hit(const RayTracer::Ray &ray) const
{
    (void)ray;
    return false;
}
}  // namespace RayTracer

#endif /* !SPHERE_TPP_ */
