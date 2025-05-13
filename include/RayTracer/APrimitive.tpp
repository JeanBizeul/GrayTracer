/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** Primitive
*/

#ifndef RAYTRACER_APRIMITIVE_TPP_
#define RAYTRACER_APRIMITIVE_TPP_

namespace RayTracer {
APrimitive::APrimitive(Math::Point3 center, Math::Vec3 direction,
    const std::vector<std::shared_ptr<RayTracer::IFace>> &faces,
    double scale)
    : _center(center), _direction(direction), _faces(faces), _scale(scale)
{

}

double APrimitive::getScale() const
{
    return _scale;
}

const Math::Point3 &APrimitive::getPosition() const
{
    return _center;
}

const Math::Vec3 &APrimitive::getRotation() const
{
    return _direction;
}

void APrimitive::setScale(double scale)
{
    _scale = scale;
}

void APrimitive::setPosition
    (const Math::Point3 &center)
{
    _center = center;
}

void APrimitive::setRotation
    (const Math::Vec3 &direction)
{
    _direction = direction;
}

}  // namespace RayTracer

#endif  // RAYTRACER_APRIMITIVE_TPP_
