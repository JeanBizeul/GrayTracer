/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#ifndef SRC_VECTOR_HPP_
#define SRC_VECTOR_HPP_

class Vector3D {
 public:
    Vector3D();
    Vector3D(double, double, double);
    ~Vector3D() = default;
    int dot(Vector3D other);
    int lenght();

    double x, y, z;
};

#endif  // SRC_VECTOR_HPP_
