/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#ifndef SRC_MAIN_HPP_
#define SRC_MAIN_HPP_

#include <memory>
#include "Render.hpp"

void createRayWindown();
void GeneratePPM(
    /*vector of primitives*/ std::unique_ptr<RayTracer::Sphere> sphere,
    Scene scenario);
void initRender(Scene, bool);

#endif  // SRC_MAIN_HPP_
