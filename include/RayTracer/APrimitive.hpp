/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#include <memory>
#include <vector>

#include "I3dObject.hpp"
#include "IFace.hpp"
#include "Math/Point.hpp"

#ifndef RAYTRACER_APRIMITIVE_HPP_
#define RAYTRACER_APRIMITIVE_HPP_

namespace RayTracer {
class APrimitive : public RayTracer::I3dObject {
 public:
    APrimitive() = default;
    APrimitive(Math::Point<3> center, Math::Vec<3> direction,
               const std::vector<std::shared_ptr<RayTracer::IFace>> &faces,
               double scale = 1);
    ~APrimitive() = default;

    virtual bool hit(const RayTracer::Ray &ray) const = 0;

    double getScale() const final;
    const Math::Point<3> &getPosition() const final;
    const Math::Vec<3> &getRotation() const final;
    void setScale(double scale) final;
    void setPosition(const Math::Point<3> &center) final;
    void setRotation(const Math::Vec<3> &direction) final;

 protected:
    Math::Point<3> _center;
    Math::Vec<3> _direction;
    std::vector<std::shared_ptr<RayTracer::IFace>> _faces;
    double _scale;
};
}  // namespace RayTracer

#include "APrimitive.tpp"

#endif  // RAYTRACER_APRIMITIVE_HPP_
