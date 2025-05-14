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
    Camera(Math::Point3 origin, RayTracer::Screen screen);
    ~Camera() = default;

    Math::Point3 _origin;
    RayTracer::Screen _screen;
    RayTracer::Ray GenerateRay(double u, double v);
};

// return ray from the camera to the screen
};  // namespace RayTracer
    // namespace RayTracer

#endif  // RAYTRACER_CAMERA_HPP_
