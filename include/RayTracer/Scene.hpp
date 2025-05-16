/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#ifndef RAYTRACER_SCENE_HPP_
#define RAYTRACER_SCENE_HPP_

#include <vector>

#include "APrimitive.hpp"
#include "Camera.hpp"
#include "Light.hpp"

class Scene {
 public:
    Scene() : camera(), lights() {}

    Scene(Math::Point3 screenPos, Math::Vec3 screenSize)
        : camera(screenPos, screenSize), lights() {}

    ~Scene() = default;

    std::vector<RayTracer::APrimitive> primitives;
    RayTracer::Camera camera;
    std::vector<RayTracer::Light> lights;
    Math::Vec3 ambient;
};

#endif  // RAYTRACER_SCENE_HPP_
