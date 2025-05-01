/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#include "I3dObject.hpp"
#include "Camera.hpp"
#include "Screen.hpp"

#ifndef IRENDERER
#define IRENDERER

class IRenderer : public I3dObject {
    public:
        IRenderer();
        ~IRenderer();

    Camera _camera;
    Screen _screen;
    //RENDERING
    //PIPELINE
};

#endif /* !IRENDERER */
