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

namespace RayTracer {
class IRenderer : public I3dObject {
 public:
    IRenderer();
    ~IRenderer();

    virtual void getCamera() = 0;
    virtual void getScreen() = 0;
    virtual void setCamera(RayTracer::Camera) = 0;
    virtual void setScreen(RayTracer::Screen) = 0;
    // RENDERING
    // PIPELINE
};
}  // namespace RayTracer

#endif  // SRC_IRENDERER_HPP_
