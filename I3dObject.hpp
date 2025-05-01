/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#ifndef _3DOBJECT
#define _3DOBJECT

#include "Point.hpp"
#include "Vector.hpp"
#include "Screen.hpp"

class I3dObject {
    public:
        I3dObject();
        ~I3dObject();

    protected:
        double scale;
        Point3D position;
        Vector3D rotation;
};

#endif /* !_3DOBJECT */