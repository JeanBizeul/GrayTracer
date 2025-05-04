/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#include "I3dObject.hpp"

#ifndef ray
#define ray

class Ray {
    public:
        Ray();
        Ray(Point3D, Vector3D);
        ~Ray() = default;
        Point3D _origin;
        Vector3D _direction;
};

#endif /* !ray */
