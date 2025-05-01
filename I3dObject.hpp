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
    protected:
        I3dObject();
        ~I3dObject() = default;

        virtual double getScale() = 0;
        virtual Point3D getPosition() = 0;
        virtual Vector3D getRotation() = 0;
        virtual void setScale(double) = 0;
        virtual void setPosition(Point3D) = 0;
        virtual void setRotation(Vector3D) = 0;
};

#endif /* !_3DOBJECT */