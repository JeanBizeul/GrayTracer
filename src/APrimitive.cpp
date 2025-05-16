/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** Primitive
*/

#ifndef RAYTRACER_APRIMITIVE_TPP_
#define RAYTRACER_APRIMITIVE_TPP_

#include "RayTracer/APrimitive.hpp"

#include <optional>
#include <vector>
#include <utility>

#include "RayTracer/Face.hpp"
#include "RayTracer/I3dObject.hpp"
#include "RayTracer/Impact.hpp"
#include "Math/Point3.hpp"
#include "Math/Vec3.hpp"

namespace RayTracer {
APrimitive::APrimitive(Math::Point3 center, Math::Vec3 direction,
const std::vector<std::shared_ptr<RayTracer::Face>> &faces,
RayTracer::Material &material,
double scale)
: _center(center),
_direction(direction),
_faces(faces),
_scale(scale),
_material(material) {
}

std::optional<Impact> APrimitive::hit(const RayTracer::Ray &ray) const {
    std::optional<Impact> impact = std::nullopt;
    std::optional<Impact> tmp = std::nullopt;

    for (const auto &face : _faces) {
        if (ray._direction.dot(face->getNormal()) < 0) {
            tmp = face->hit(_center, _direction, ray);
        }
        if (tmp && (!impact || tmp->_distance < impact->_distance)) {
            impact = tmp;
        }
    }
    return impact;
}

double APrimitive::getScale() const {
    return _scale;
}

const Math::Point3 &APrimitive::getPosition() const {
    return _center;
}

const Math::Vec3 &APrimitive::getRotation() const {
    return _direction;
}

const RayTracer::Material &APrimitive::getMaterial() const {
    return _material;
}

void APrimitive::setScale(double scale) {
    _scale = scale;
}

void APrimitive::setPosition(const Math::Point3 &center) {
    _center = center;
}

void APrimitive::setRotation(const Math::Vec3 &direction) {
    _direction = direction;
}

void APrimitive::setMaterial(RayTracer::Material &material) {
    _material = material;
}

void APrimitive::translate(const Math::Vec3 &translation) {
    _center += translation;
}

void APrimitive::rotate(const Math::Vec3 &rotation) {
    _direction += rotation;
}

}  // namespace RayTracer

#endif  // RAYTRACER_APRIMITIVE_TPP_
