/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#include "AFace.hpp"
#include "IFace.hpp"

#ifndef RAYTRACER_SCREEN_HPP_
#define RAYTRACER_SCREEN_HPP_

namespace RayTracer {
class Screen {
 public:
    Screen(Math::Point<3> pos, Math::Vec<3> size);
    ~Screen() = default;

    static RayTracer::AFace<4> screen;
    Math::Point<3> pointAt(double u, double v);
    }; // namespace RayTracer
}
#endif  // RAYTRACER_SCREEN_HPP_
