/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** Sphere
*/

<<<<<<< HEAD:src/lib/Factories/Primitives/Square/src/Sphere.hpp
#ifndef SRC_LIB_FACTORIES_PRIMITIVES_SQUARE_SRC_SPHERE_HPP_
#define SRC_LIB_FACTORIES_PRIMITIVES_SQUARE_SRC_SPHERE_HPP_


#include "../../../../../../include/RayTracer/APrimitive.hpp"
=======

#ifndef SRC_PLUGINS_FACTORIES_PRIMITIVES_SPHERE_SRC_SPHERE_HPP_
#define SRC_PLUGINS_FACTORIES_PRIMITIVES_SPHERE_SRC_SPHERE_HPP_

#include <optional>
#include "Math/Point3.hpp"
#include "Math/Vec3.hpp"
#include "RayTracer/APrimitive.hpp"
#include "RayTracer/Impact.hpp"
>>>>>>> main:src/Plugins/Factories/Primitives/Sphere/src/Sphere.hpp

namespace RayTracer {
class Sphere : public APrimitive {
 public:
    Sphere() = default;
    Sphere(Math::Point3 center, Math::Vec3 direction, double scale = 1);
    ~Sphere() = default;

    std::optional<Impact> hit(const RayTracer::Ray &ray) const final;
};
}  // namespace RayTracer

#include "Sphere.tpp"

#endif  // SRC_PLUGINS_FACTORIES_PRIMITIVES_SPHERE_SRC_SPHERE_HPP_
