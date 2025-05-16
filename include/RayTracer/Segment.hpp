/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#include "Math/Point3.hpp"
#include "Math/Vec3.hpp"

#ifndef RAYTRACER_SEGMENT_HPP_
#define RAYTRACER_SEGMENT_HPP_

namespace RayTracer {
class Segment {
 public:
    Segment() = default;

    Segment(Math::Point3 p1, Math::Point3 p2) : _p1(p1), _p2(p2) {}

    ~Segment() = default;

    Math::Point3 _p1;
    Math::Point3 _p2;
};
}  // namespace RayTracer

#endif  // RAYTRACER_SEGMENT_HPP_
