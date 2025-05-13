/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#include "AFace.hpp"

#ifndef RAYTRACER_SCREEN_HPP_
#define RAYTRACER_SCREEN_HPP_

namespace RayTracer {
class Screen {
 public:
    Screen() = default;
    Screen(Math::Point<3> pos, Math::Vec<3> size);
    ~Screen() = default;

    static RayTracer::AFace<4> screen;
};
}  // namespace RayTracer

#endif  // RAYTRACER_SCREEN_HPP_
