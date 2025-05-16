/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** file
*/

#include "RayTracer/Camera.hpp"

RayTracer::Camera::Camera(Math::Point3 origin, RayTracer::Screen screen)
    : _origin(origin), _screen(screen) {
}

RayTracer::Ray RayTracer::Camera::GenerateRay(double u, double v) {
    // Create direction vector using array constructor
    return RayTracer::Ray(_origin,
                          Math::Vec3(std::array<double, 3>{u, v, -1.0}));
}
