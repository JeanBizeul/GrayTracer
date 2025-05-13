/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#include "Ray.hpp"
#include "Screen.hpp"

#ifndef RAYTRACER_CAMERA_HPP_
#define RAYTRACER_CAMERA_HPP_

namespace RayTracer {
class Camera {
 public:
    Camera() = default;

    Camera(Math::Point<3> screenPos, Math::Vec<3> screenSize)
        : origin(), screen(screenPos, screenSize) {}

    ~Camera() = default;

    Math::Point<3> origin;
    RayTracer::Screen screen;
    RayTracer::Ray GenerateRay(double u, double v);
    // return ray from the camera to the screen
};
}  // namespace RayTracer

#endif  // RAYTRACER_CAMERA_HPP_
