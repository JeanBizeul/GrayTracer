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

    virtual void getCamera() = 0;
    virtual void getScreen() = 0;
    virtual void setCamera(Camera) = 0;
    virtual void setScreen(Screen) = 0;
    //RENDERING
    //PIPELINE
};

#endif /* !IRENDERER */
