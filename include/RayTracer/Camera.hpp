/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#include "Screen.hpp"
#include "Ray.hpp"

#ifndef SRC_CAMERA_HPP_
#define SRC_CAMERA_HPP_

namespace RayTracer {
class Camera {
 public:
   Camera() = default;
   ~Camera() = default;

   Math::Point<3> origin;
   RayTracer::Screen screen;
   RayTracer::Ray GenerateRay(double u, double v);  // return ray from the camera to the screen
};
}  // namespace RayTracer

#endif  // SRC_CAMERA_HPP_
