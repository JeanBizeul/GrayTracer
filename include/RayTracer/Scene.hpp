/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#ifndef RAYTRACER_SCENE_HPP_
#define RAYTRACER_SCENE_HPP_

#include <vector>

#include "Camera.hpp"
#include "ILight.hpp"
#include "IPrimitive.hpp"

class Scene {
 public:
    Scene();
    ~Scene() = default;

    std::vector<RayTracer::IPrimitive> primitives;
    RayTracer::Camera camera;
    Math::Vec<3> Ambient_light;
};

#endif  // RAYTRACER_SCENE_HPP_
