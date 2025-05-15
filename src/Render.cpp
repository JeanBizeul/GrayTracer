/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** render
*/

#define MAX_HEIGHT 700
#define MAX_WIDHT 1000

#include <cstddef>
#include <optional>
#include "Render.hpp"
#include <iostream>
#include <vector>

std::optional<RayTracer::APrimitive> lookingForTheClosestHit(std::vector<RayTracer::APrimitive> primitive, RayTracer::Ray ray)
{
    std::vector<RayTracer::APrimitive> _hitByRay;
    std::optional<RayTracer::APrimitive> closest = std::nullopt;
    bool set = false;

    for (auto &i: primitive) {
        if (i.hit(ray))
            _hitByRay.push_back(i); // All primitives hit by the ray
    }
    if (_hitByRay.empty())
        return closest;
    for (auto y :_hitByRay) {
        if (!set) {
            closest = y;
            set = true;
        }
        if (closest.value().hit(ray)->_distance > y.hit(ray)->_distance) // looking for the closest hit directly here
            closest = y;
    }
    return closest;
}

void GeneratePPM(Scene scenario)
{
    //Create a file if it doesn't exist in append Mode
        //std::cout << "P3" << std::endl;
        //std::cout << MAX_WIDHT << " " << MAX_HEIGHT << std::endl;
        //std::cout << "255" << std::endl;
    std::vector<RayTracer::APrimitive> list;
    std::optional<RayTracer::APrimitive> ClosestPrimitive;

    //// Read the 2D Vector of the struct
    for (int i = 0; i != MAX_HEIGHT; i++) {
        for (int j = 0; j != MAX_WIDHT; j++) {
            double u = j;
            double v = i;
            RayTracer::Ray r = scenario.camera.GenerateRay(u, v);
            ClosestPrimitive = lookingForTheClosestHit(scenario.primitives, r);
            if (ClosestPrimitive.has_value()) {

            }
            continue;
            //if (->hit(r)) {
            //    std::cout << "Hit a primitive" << std::endl;
            //    // primitive
            //} else {
            //    std::cout << "0 0 0" << std::endl;  // black
            //}
        }
    }
}

void createRayWindown() {
    bool set = false;
    sf::Window window(sf::VideoMode(MAX_WIDHT, MAX_HEIGHT), "RayTracer");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }
        if (!set) {
            // draw image
            set = true;
        }
    }
}

void initRender(
    Scene scenario, bool DisplayMode) {  // get the infos if PPM the call PPM if not sfml
    if (DisplayMode) {
        createRayWindown();
    } else {
        GeneratePPM(scenario);
    }
}
