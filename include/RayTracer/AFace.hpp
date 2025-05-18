/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#ifndef RAYTRACER_AFACE_HPP_
#define RAYTRACER_AFACE_HPP_
#include <vector>

#include "IFace.hpp"

namespace RayTracer {
template <unsigned int N>
class AFace : public RayTracer::IFace {
 public:
    AFace() = delete;
    ~AFace() = default;

    explicit AFace(std::vector<RayTracer::Segment> segments)
        : _segs(segments) {}

 protected:
    std::array<RayTracer::Segment, N> _segs;
};
}  // namespace RayTracer

#endif  // RAYTRACER_AFACE_HPP_
