/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#include "Screen.hpp"
#include "Ray.hpp"

#ifndef RAYTRACER_CAMERA_HPP_
    #define RAYTRACER_CAMERA_HPP_

namespace RayTracer {
class Camera {
    public:
    Camera() = default;
    ~Camera() = default;

    Math::Point<3> origin;
    RayTracer::Screen screen;
    RayTracer::Ray GenerateRay(double u, double v);
    // return ray from the camera to the screen
};
}  // namespace RayTracer

#endif  // RAYTRACER_CAMERA_HPP_
