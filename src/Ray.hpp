/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#include "I3dObject.hpp"

#ifndef SRC_RAY_HPP_
#define SRC_RAY_HPP_

class Ray {
 public:
    Ray();
    Ray(Point3D, Vector3D);
    ~Ray() = default;
    Point3D _origin;
    Vector3D _direction;
};

#endif  // SRC_RAY_HPP_
