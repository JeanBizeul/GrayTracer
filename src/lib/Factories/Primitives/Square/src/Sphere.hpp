/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** Sphere
*/

#ifndef SRC_LIB_FACTORIES_PRIMITIVES_SQUARE_SRC_SPHERE_HPP_
#define SRC_LIB_FACTORIES_PRIMITIVES_SQUARE_SRC_SPHERE_HPP_

#include "../../../../../../include/RayTracer/APrimitive.hpp"

namespace RayTracer {
class Sphere : public APrimitive {
 public:
    Sphere() = default;
    Sphere(Math::Point<3> center, Math::Vec<3> direction, double scale = 1);
    ~Sphere() = default;

    bool hit(const RayTracer::Ray &ray) const final;
};
}  // namespace RayTracer

#include "Sphere.tpp"

#endif  // SRC_LIB_FACTORIES_PRIMITIVES_SQUARE_SRC_SPHERE_HPP_
