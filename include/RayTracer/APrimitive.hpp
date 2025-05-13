/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#include <vector>
#include <memory>

#include "../Math/Point3.hpp"
#include "../Math/Vec3.hpp"

#include "I3dObject.hpp"
#include "IFace.hpp"

#ifndef RAYTRACER_APRIMITIVE_HPP_
#define RAYTRACER_APRIMITIVE_HPP_

namespace RayTracer {
class APrimitive : public RayTracer::I3dObject {
 public:
    APrimitive() = default;
    APrimitive(Math::Point3 center, Math::Vec3 direction,
               const std::vector<std::shared_ptr<RayTracer::IFace>> &faces,
               double scale = 1);
    ~APrimitive() = default;

    virtual bool hit(const RayTracer::Ray &ray) const = 0;

    double getScale() const final;
    const Math::Point3 &getPosition() const final;
    const Math::Vec3 &getRotation() const final;
    void setScale(double scale) final;
    void setPosition(const Math::Point3 &center) final;
    void setRotation(const Math::Vec3 &direction) final;

 protected:
    Math::Point3 _center;
    Math::Vec3 _direction;
    std::vector<std::shared_ptr<RayTracer::IFace>> _faces;
    double _scale;
};
}  // namespace RayTracer

#include "APrimitive.tpp"

#endif  // RAYTRACER_APRIMITIVE_HPP_
