/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** file
*/

#include "RayTracer/Camera.hpp"

RayTracer::Ray RayTracer::Camera::GenerateRay(double u, double v) {
    // Create direction vector using array constructor
    _scre
    return RayTracer::Ray(origin,
                        Math::Vec3(std::array<double, 3>{u, v, -1.0}));
}
