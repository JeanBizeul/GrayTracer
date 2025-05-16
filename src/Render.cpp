/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** render
*/

#include <cstddef>
#include <cstdio>
#include <iostream>
#include <vector>
#define MAX_HEIGHT 700
#define MAX_WIDHT 1000

#include "Render.hpp"

std::ofstream &Render::getPPM(void) {
    return _PPMFile;
}

sf::RenderWindow &Render::GetWindow(void) {
    return win;
}

sf::Texture &Render::getTexture(void) {
    return texture;
}

sf::Sprite &Render::getSprite(void) {
    return sprite;
}

std::optional<RayTracer::APrimitive> lookingForTheClosestHit(
    std::vector<RayTracer::APrimitive> primitive, RayTracer::Ray ray) {
    std::vector<RayTracer::APrimitive> _hitByRay;
    std::optional<RayTracer::APrimitive> closest = std::nullopt;
    bool set = false;

    for (auto &i : primitive) {
        if (i.hit(ray))
            _hitByRay.push_back(i);  // All primitives hit by the ray
    }
    if (_hitByRay.empty()) return closest;
    for (auto y : _hitByRay) {
        if (!set) {
            closest = y;
            set = true;
        }
        if (closest.value().hit(ray)->_distance >
            y.hit(ray)->_distance)  // looking for the closest hit directly here
            closest = y;
    }
    return closest;
}

void Render::GeneratePPM(/*color*/) {
    static bool set = false;
    if (!set) {
        _PPMFile.open("Output.ppm");
        if (_PPMFile.fail()) {
            std::cerr << "Error while opening PPM file";
            return;
        }

        _PPMFile << "P3" << std::endl;
        _PPMFile << MAX_WIDHT << " " << MAX_HEIGHT << std::endl;
        _PPMFile << "255" << std::endl;
        _PPMFile << std::endl;
        _PPMFile << std::endl;
    }
    // PPMFile << (...) << std::endl
}

void Render::createRayWindow(/*color, */ double x, double y) {
    sf::RenderWindow window(sf::VideoMode(MAX_WIDHT, MAX_HEIGHT), "RayTracer");
    //  sf::Image buffer(MAX_WIDHT, MAX_HEIGHT, sf::Color(0, 0, 0));
    //  sf::Sprite bufferSprite(buffer); à revoir

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }
        window.clear(sf::Color::Black);
        // buffer.SetPixel(z, y, sf::Color(r, g, b));

        // window.draw(bufferSprite);

        window.display();
    }
}

void initRender(
    Scene scenario,
    bool DisplayMode) {
    Render render;
    std::vector<RayTracer::APrimitive> list;
    std::optional<RayTracer::APrimitive> ClosestPrimitive;

    for (int i = 0; i != MAX_HEIGHT; i++) {
        for (int j = 0; j != MAX_WIDHT; j++) {
            double u = j;
            double v = i;
            RayTracer::Ray r = scenario.camera.GenerateRay(u, v);
            ClosestPrimitive = lookingForTheClosestHit(scenario.primitives, r);
            if (ClosestPrimitive.has_value()) {
                // Light
                if (DisplayMode) {
                    render.createRayWindow(/*color,*/ u, v);
                } else {
                    render.GeneratePPM(/*color*/);
                }
            }
            continue;
        }
    }
    if (!DisplayMode) render.getPPM().close();
}
