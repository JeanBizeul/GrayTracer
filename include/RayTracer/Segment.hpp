/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#include "Math/Point.hpp"
#include "Math/Vec.hpp"

#ifndef SRC_SEGMENTHPP_
#define SRC_SEGMENTHPP_

namespace RayTracer{
class Segment {
 public:
    Segment() : _p1(0), _p2(0) {};
    Segment(Math::Point<3> p1, Math::Point<3> p2)
        : _p1(p1), _p2(p2) {};
    ~Segment() = default;

    Math::Point<3> _p1;
    Math::Point<3> _p2;
};
}  // namespace RayTracer

#endif  // SRC_SEGMENTHPP_
