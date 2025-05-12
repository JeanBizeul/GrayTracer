/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** IFace
*/

#ifndef IFACE_HPP_
#define IFACE_HPP_
#include <vector>

#include "Ray.hpp"
#include "Segment.hpp"

namespace RayTracer {
class IFace {
 public:
    IFace() = delete;
    virtual ~IFace() = default;

    virtual bool hit(const RayTracer::Ray &ray) const = 0;
};
}  // namespace RayTracer

#endif /* !IFACE_HPP_ */
