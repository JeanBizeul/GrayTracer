/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#ifndef VECTOR
#define VECTOR

class Vector3D {
    public:
        Vector3D();
        Vector3D(double, double, double);
        ~Vector3D() = default;
    int dot(Vector3D other);
    int lenght();
    

    double x, y, z;
};

#endif /* !VECTOR */
