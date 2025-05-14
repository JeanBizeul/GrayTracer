/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/


#ifndef RAYTRACER_ILIGHT_HPP_
#define RAYTRACER_ILIGHT_HPP_

#include "I3dObject.hpp"

namespace RayTracer {
class ILight : public RayTracer::I3dObject {
 public:
    ILight();
    ~ILight();

    // COLOR
    virtual Math::Vec<4> getColor() = 0;
    virtual void setColor(Math::Vec<4> Color) = 0;
    // BEAM ANGLE
    virtual double getBeamAngle() = 0;
    virtual void setBeamColor(double angle) = 0;
    // INTENSITY
    virtual double getIntesity() = 0;
    virtual void setIntesity(double intensity) = 0;
};
}  // namespace RayTracer

#endif  // RAYTRACER_ILIGHT_HPP_
