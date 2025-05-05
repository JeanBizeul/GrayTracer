/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#include "Point.hpp"
#include "Vector.hpp"

#ifndef SRC_LINE_HPP_
#define SRC_LINE_HPP_

class Line {
 public:
    Line();
    Line(Point3D, Vector3D);
    ~Line() = default;

    Vector3D _direction;
    Point3D _origin;
};

#endif  // SRC_LINE_HPP_
