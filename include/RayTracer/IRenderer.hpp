/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#ifndef RAYTRACER_IRENDERER_HPP_
#define RAYTRACER_IRENDERER_HPP_

#include "Camera.hpp"
#include "I3dObject.hpp"
#include "Screen.hpp"

namespace RayTracer {
class IRenderer : public I3dObject {
 public:
    virtual ~IRenderer() = default;

    virtual void getCamera() = 0;
    virtual void getScreen() = 0;
    virtual void setCamera(RayTracer::Camera) = 0;
    virtual void setScreen(RayTracer::Screen) = 0;
    // RENDERING
    // PIPELINE
};
}  // namespace RayTracer

#endif  // RAYTRACER_IRENDERER_HPP_
