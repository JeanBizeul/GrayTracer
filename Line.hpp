/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#include "Vector.hpp"
#include "Point.hpp"

#ifndef LINE
#define LINE

class Line {
    public:
        Line();
        Line(Point3D, Vector3D);
        ~Line() = default;

        Vector3D _direction;
        Point3D _origin;
};

#endif /* !LINE */
