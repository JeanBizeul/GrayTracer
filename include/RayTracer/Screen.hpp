/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#include "Face.hpp"

#ifndef RAYTRACER_SCREEN_HPP_
#define RAYTRACER_SCREEN_HPP_

namespace RayTracer {
class Screen {
 public:
    Screen(Math::Point<3> pos, Math::Vec3 size);
    ~Screen() = default;

    static RayTracer::Face<4> screen;
};
}  // namespace RayTracer

#endif  // RAYTRACER_SCREEN_HPP_
