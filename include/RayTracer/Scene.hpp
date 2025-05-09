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

class Scene {
    public:
        Scene();
        ~Scene() = default;

    //std::vector<> primitives;
    std::vector<RayTracer::Camera> cameras;
    std::vector<RayTracer::ILight> lights;
};

#endif /* !scene */
