/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#ifndef scene
#define scene

#include <vector>
#include "ILight.hpp"
#include "Camera.hpp"
#include "IPrimitive.hpp"

class Scene {
     public:
        Scene();
        ~Scene() = default;

    std::vector<RayTracer::IPrimitive> primitives;
    std::vector<RayTracer::Camera> cameras;
    std::vector<RayTracer::ILight> lights;
};

#endif /* !scene */
