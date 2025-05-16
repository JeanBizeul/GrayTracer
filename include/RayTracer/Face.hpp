/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** Face
*/

#ifndef RAYTRACER_FACE_HPP_
#define RAYTRACER_FACE_HPP_

#include <optional>
#include <tuple>

#include "Math/Vec.hpp"
#include "Impact.hpp"
#include "Ray.hpp"

namespace RayTracer {
class Face {
 public:
    Face() = default;  // placeholder

    ~Face() = default;

    std::optional<Impact> hit(Math::Vec3 obj_pos, Math::Vec3 obj_dir,
                              const RayTracer::Ray &ray) const;

    std::tuple<Math::Vec3, Math::Vec3, Math::Vec3> getWorldVertices(
        const Math::Vec3 &obj_pos, const Math::Vec3 &obj_dir) const;

    const Math::Vec3 &getNormal() const;

    // Material getMaterial() const;

 private:
    Math::Vec3 _position;  // relative to the object
    Math::Vec3 _normal;    // relative to the object
    Math::Vec3 _a;         // relative to the face
    Math::Vec3 _c;         // relative to the face
    Math::Vec3 _b;         // relative to the face
    // Material _material;
};
}  // namespace RayTracer

#endif  // RAYTRACER_FACE_HPP_
