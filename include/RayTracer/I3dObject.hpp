/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#ifndef RAYTRACER_I3DOBJECT_HPP_
    #define RAYTRACER_I3DOBJECT_HPP_
    #include "Math/Point.hpp"
    #include "Math/Vec.hpp"

namespace RayTracer {
class I3dObject {
 public:
    I3dObject() = delete;
    virtual Math::Point<3> getPosition() = 0;
    virtual Math::Vec<3> getRotation() = 0;
    virtual void setScale(double) = 0;
    virtual void setPosition(Math::Point<3>) = 0;
    virtual void setRotation(Math::Vec<3>) = 0;
    virtual double getScale() = 0;

 protected:
    ~I3dObject() = default;
};
}  // namespace RayTracer

#endif  // RAYTRACER_I3DOBJECT_HPP_
