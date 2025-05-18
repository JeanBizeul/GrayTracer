/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#ifndef RAYTRACER_CAMERA_HPP_
#define RAYTRACER_CAMERA_HPP_

#include "Ray.hpp"
#include "Screen.hpp"

namespace RayTracer {
class Camera {
 public:
    Camera() = default;

    Camera(Math::Point3 screenPos, Math::Vec3 screenSize)
        : origin(), _screen(screenPos, screenSize) {}

    ~Camera() = default;

    Math::Point3 origin;
    Math::Vec3 _size;
    RayTracer::Screen _screen;
    RayTracer::Ray GenerateRay(double u, double v);
};
};  // namespace RayTracer

#endif  // RAYTRACER_CAMERA_HPP_
