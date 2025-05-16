/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** Plane
*/

#ifndef SRC_PLUGINS_FACTORIES_PRIMITIVES_PLANE_SRC_PLANE_HPP_
#define SRC_PLUGINS_FACTORIES_PRIMITIVES_PLANE_SRC_PLANE_HPP_

#include <optional>

#include "Math/Point3.hpp"
#include "Math/Vec3.hpp"
#include "RayTracer/APrimitive.hpp"
#include "RayTracer/Impact.hpp"
#include "RayTracer/Material.hpp"

namespace RayTracer {
class Plane : public APrimitive {
 public:
    Plane() = default;
    Plane(Math::Point3 center, Math::Vec3 direction,
          RayTracer::Material &material, double scale = 1);
    ~Plane() = default;

    std::optional<Impact> hit(const RayTracer::Ray &ray) const final;
};
}  // namespace RayTracer

#endif  // SRC_PLUGINS_FACTORIES_PRIMITIVES_PLANE_SRC_PLANE_HPP_
