/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** main
*/

#include "main.hpp"

#include "Render.hpp"

void SceneLoader(Scene &scene_elements) {  // For testing purposes
    Math::Point3 origin({0, 0, 0});
    Math::Vec3 screenSize({2.0, 2.0, 0.0});
    Math::Point3 screenPos({0.0, 0.0, -1.0});
    RayTracer::Screen screen(screenPos, screenSize);
    RayTracer::Camera(origin, screen);

    // First sphere - left side
    Math::Point3 center1({-2.0, 1.0, -5.0});
    Math::Vec3 direction1({0.0, 45.0, 30.0});
    RayTracer::Sphere sphere1(center1, direction1);

    // Second sphere - right side
    Math::Point3 center2({2.0, 1.0, -5.0});
    Math::Vec3 direction2({0.0, -45.0, 30.0});
    RayTracer::Sphere sphere2(center2, direction2);

    // Add both spheres to scene
    scene_elements.primitives.push_back(sphere1);
    scene_elements.primitives.push_back(sphere2);
}

int main(int ac, char **av) {
    Scene scene_elements;

    SceneLoader(scene_elements);
    initRender(scene_elements, false);  //  False => Asking for PPM Output
    return 0;
}
