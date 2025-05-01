/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#ifndef POINT
#define POINT

class Point3D {
    public:
        Point3D();
        Point3D(double, double, double);
        ~Point3D() = default;

        double x, y, z;
};

#endif /* !POINT */
