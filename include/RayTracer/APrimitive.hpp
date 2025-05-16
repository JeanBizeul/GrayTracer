/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#include <memory>
#include <vector>

#include "Face.hpp"
#include "I3dObject.hpp"
#include "Math/Point3.hpp"
#include "Math/Vec3.hpp"
#include "Ray.hpp"

#ifndef RAYTRACER_APRIMITIVE_HPP_
#define RAYTRACER_APRIMITIVE_HPP_

namespace RayTracer {
class APrimitive : public RayTracer::I3dObject {
 public:
    APrimitive() = default;
    APrimitive(Math::Point3 center, Math::Vec3 direction,
               const std::vector<std::shared_ptr<RayTracer::Face>> &faces,
               double scale = 1);
    ~APrimitive() = default;

    virtual std::optional<Impact> hit(const RayTracer::Ray &ray) const;

    double getScale() const final;
    const Math::Point3 &getPosition() const final;
    const Math::Vec3 &getRotation() const final;
    void setScale(double scale) final;
    void setPosition(const Math::Point3 &center) final;
    void setRotation(const Math::Vec3 &direction) final;

    void translate(const Math::Vec3 &translation);
    void rotate(const Math::Vec3 &rotation);

 protected:
    Math::Point3 _center;
    Math::Vec3 _direction;
    std::vector<std::shared_ptr<RayTracer::Face>> _faces;
    double _scale;
};
}  // namespace RayTracer

#endif  // RAYTRACER_APRIMITIVE_HPP_
