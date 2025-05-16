/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#ifndef RAYTRACER_SCREEN_HPP_
#define RAYTRACER_SCREEN_HPP_

#include "AFace.hpp"

namespace RayTracer {
class Screen {
 public:
    Screen(Math::Point3 pos, Math::Vec3 size);
    Screen() = default;
    ~Screen() = default;

    static RayTracer::AFace<4> screen;
    Math::Point3 pointAt(double u, double v);
};
}  // namespace RayTracer
#endif  // RAYTRACER_SCREEN_HPP_
