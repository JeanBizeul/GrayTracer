/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** render
*/

#define MAX_HEIGHT 700
#define MAX_WIDHT 1000

#include "../include/RayTracer/Scene.hpp"

void initRender()
{
    Scene scenario;
    double u, v;
    //vector of primitives
    //create a sfml window

    for (int i = 0; i != MAX_HEIGHT; i++) {
        for (int j = 0; j != MAX_WIDHT; j++) {
            double u = j;
            double v = i;
            RayTracer::Ray r = scenario.camera.GenerateRay(u, v);
            if (i.hits()) {
                //primitive color
            } else {
                //black
            }

        }
    }
}