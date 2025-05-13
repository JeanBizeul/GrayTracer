/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** Face
*/

#ifndef RAYTRACER_FACE_HPP_
#define RAYTRACER_FACE_HPP_

#include "Math/Point.hpp"
#include "Math/Vec.hpp"
#include "Ray.hpp"

namespace RayTracer {
class Face {
 public:
    Face() = default;  // placeholder

    ~Face() = default;  // placeholder

    bool hit(Math::Vec<3> obj_pos, Math::Vec<3> obj_dir,
             const RayTracer::Ray &ray) const;

    std::tuple<Math::Vec<3>, Math::Vec<3>, Math::Vec<3>> getWorldVertices(
        const Math::Vec<3> &obj_pos, const Math::Vec<3> &obj_dir) const;

    // Material getMaterial() const;

 private:
    Math::Vec<3> _position;   // relative to the object
    Math::Vec<3> _direction;  // relative to the object
    Math::Vec<3> _a;          // relative to the face
    Math::Vec<3> _b;          // relative to the face
    Math::Vec<3> _c;          // relative to the face
    // Material _material;
};
}  // namespace RayTracer

#include "Face.tpp"

#endif  // RAYTRACER_FACE_HPP_
