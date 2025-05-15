/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** Face
*/

#ifndef RAYTRACER_FACE_TPP_
#define RAYTRACER_FACE_TPP_

#define EPSILON 1e-6f

#include "../include/RayTracer/Face.hpp"

#include <cmath>
#include <optional>
#include <tuple>

#include "../include/Math/Vec.hpp"
#include "../include/RayTracer/Impact.hpp"
#include "../include/RayTracer/Ray.hpp"

namespace RayTracer {

Math::Vec3 rotateVec(const Math::Vec3 &v, const Math::Vec3 &rotation_deg) {
    double rx = rotation_deg[0] * M_PI / 180.0;
    double ry = rotation_deg[1] * M_PI / 180.0;
    double rz = rotation_deg[2] * M_PI / 180.0;

    Math::Vec3 xRot({v[0], std::cos(rx) * v[1] - std::sin(rx) * v[2],
                     std::sin(rx) * v[1] + std::cos(rx) * v[2]});

    Math::Vec3 yRot({std::cos(ry) * xRot[0] + std::sin(ry) * xRot[2], xRot[1],
                     -std::sin(ry) * xRot[0] + std::cos(ry) * xRot[2]});

    Math::Vec3 zRot({std::cos(rz) * yRot[0] - std::sin(rz) * yRot[1],
                     std::sin(rz) * yRot[0] + std::cos(rz) * yRot[1], yRot[2]});

    return zRot;
}

std::tuple<Math::Vec3, Math::Vec3, Math::Vec3> Face::getWorldVertices(
    const Math::Vec3 &obj_pos, const Math::Vec3 &obj_dir) const {
    Math::Vec3 total_rotation = obj_dir + _normal;
    Math::Vec3 base_pos = obj_pos + _position;

    Math::Vec3 v0 = base_pos + rotateVec(_a, total_rotation);
    Math::Vec3 v1 = base_pos + rotateVec(_b, total_rotation);
    Math::Vec3 v2 = base_pos + rotateVec(_c, total_rotation);

    return {v0, v1, v2};
}

std::optional<Impact> Face::hit(Math::Vec3 obj_pos, Math::Vec3 obj_dir,
                                const RayTracer::Ray &ray) const {
    auto[v0, v1, v2] = getWorldVertices(obj_pos, obj_dir);

    Math::Vec3 edge1 = v1 - v0;
    Math::Vec3 edge2 = v2 - v0;
    Math::Vec3 h = ray._direction.cross(edge2);
    double a = edge1.dot(h);

    if (a > -EPSILON && a < EPSILON) return std::nullopt;

    double f = 1.0 / a;
    Math::Vec3 s = ray._origin - v0;
    double u = f * s.dot(h);

    if (u < 0.0 || u > 1.0) return std::nullopt;

    Math::Vec3 q = s.cross(edge1);
    double v = f * ray._direction.dot(q);

    if (v < 0.0 || u + v > 1.0) return std::nullopt;

    double t = f * edge2.dot(q);

    if (t > EPSILON)
        return std::make_optional<Impact>(ray._origin + ray._direction * t,
                                          _normal, t);

    return std::nullopt;
}

const Math::Vec3 &Face::getNormal() const {
    return _normal;
}

}  // namespace RayTracer

#endif  // RAYTRACER_FACE_TPP_
