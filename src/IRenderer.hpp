/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#include "Camera.hpp"
#include "I3dObject.hpp"
#include "Screen.hpp"

#ifndef SRC_IRENDERER_HPP_
#define SRC_IRENDERER_HPP_

class IRenderer : public I3dObject {
 public:
    IRenderer();
    ~IRenderer();

    virtual void getCamera() = 0;
    virtual void getScreen() = 0;
    virtual void setCamera(Camera) = 0;
    virtual void setScreen(Screen) = 0;
    // RENDERING
    // PIPELINE
};

#endif  // SRC_IRENDERER_HPP_
