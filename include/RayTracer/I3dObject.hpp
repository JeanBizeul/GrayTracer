/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#ifndef RAYTRACER_I3DOBJECT_HPP_
#define RAYTRACER_I3DOBJECT_HPP_

#include "Math/Point3.hpp"
#include "Math/Vec3.hpp"
#include "Ray.hpp"

namespace RayTracer {
class I3dObject {
 public:
    virtual ~I3dObject() = default;

    virtual double getScale() const = 0;
    virtual const Math::Point3 &getPosition() const = 0;
    virtual const Math::Vec3 &getRotation() const = 0;
    virtual void setScale(double scale) = 0;
    virtual void setPosition(const Math::Point3 &center) = 0;
    virtual void setRotation(const Math::Vec3 &direction) = 0;

 protected:
    I3dObject() = default;
};
}  // namespace RayTracer

#endif  // RAYTRACER_I3DOBJECT_HPP_
