/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** IFace
*/

#ifndef RAYTRACER_IFACE_HPP_
#define RAYTRACER_IFACE_HPP_
#include <vector>

#include "Ray.hpp"
#include "Segment.hpp"

namespace RayTracer {
class IFace {
 public:
    IFace() = delete;
    virtual ~IFace() = default;
};
}  // namespace RayTracer

#endif  // RAYTRACER_IFACE_HPP_
