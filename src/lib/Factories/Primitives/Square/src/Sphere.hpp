/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** Sphere
*/

#ifndef SPHERE_HPP_
#define SPHERE_HPP_
#include "RayTracer/APrimitive.hpp"

namespace RayTracer {
class Sphere : public APrimitive {
 public:
    Sphere() = default;
    Sphere(Math::Point<3> center, Math::Vec<3> direction, double scale = 1);
    ~Sphere() = default;

    virtual bool hit(const RayTracer::Ray &ray) const final;
};
}  // namespace RayTracer

#include "Sphere.tpp"

#endif /* !SPHERE_HPP_ */
