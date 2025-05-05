/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#ifndef SRC_I3DOBJECT_HPP_
#define SRC_I3DOBJECT_HPP_

#include "Point.hpp"
#include "Screen.hpp"
#include "Vector.hpp"

class I3dObject {
 protected:
    I3dObject();
    ~I3dObject() = default;

 public:
    virtual double getScale() = 0;
    virtual Point3D getPosition() = 0;
    virtual Vector3D getRotation() = 0;
    virtual void setScale(double) = 0;
    virtual void setPosition(Point3D) = 0;
    virtual void setRotation(Vector3D) = 0;
};

#endif  // SRC_I3DOBJECT_HPP_
