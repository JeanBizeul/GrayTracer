/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#include "I3dObject.hpp"
#include "Ray.hpp"

#ifndef CAMERA
#define CAMERA

class Camera {
    public:
    Camera();
    ~Camera() = default;

    Point3D origin;
    Screen screen;
    Ray GenerateRay(double u, double v); //return ray from the camera to the screen
};

#endif /* !CAMERA */
