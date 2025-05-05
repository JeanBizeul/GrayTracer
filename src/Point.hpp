/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#ifndef SRC_POINT_HPP_
#define SRC_POINT_HPP_

class Point3D {
 public:
    Point3D();
    Point3D(double, double, double);
    ~Point3D() = default;

    double x, y, z;
};

#endif  // SRC_POINT_HPP_
