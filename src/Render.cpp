/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** render
*/

#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <memory>
#include <optional>
#include <utility>
#include <vector>

#include <SFML/Graphics/Color.hpp>
#define MAX_HEIGHT 700
#define MAX_WIDHT 1000
#include "Math/Vec4.hpp"
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

std::vector<Math::Vec4> &Render::getPixels(void) {
    return Pixels;
}

std::optional<std::reference_wrapper<RayTracer::APrimitive>>
lookingForTheClosestHit(std::vector<RayTracer::APrimitive> &primitive,
                        RayTracer::Ray ray) {
    std::vector<std::reference_wrapper<RayTracer::APrimitive>> _hitByRay;
    std::optional<std::reference_wrapper<RayTracer::APrimitive>> closest =
        std::nullopt;

    for (auto &i : primitive) {
        if (i.hit(ray)) {
            _hitByRay.push_back(i);
            std::cout << "A hit occured\n";
        }
    }

    if (_hitByRay.empty()) {
        std::cout << "Its empty\n";
        return closest;
    }

    for (auto &y : _hitByRay) {
        if (!closest.has_value()) {
            closest = y;
        } else {
            // Compare distances from the ray hit
            auto closest_hit = closest->get().hit(ray);
            auto current_hit = y.get().hit(ray);

            if (closest_hit && current_hit &&
                closest_hit->_distance > current_hit->_distance) {
                closest = y;
            }
        }
    }
    std::cout << "found it" << std::endl;
    return closest;
}

void Render::GeneratePPM() {
    _PPMFile.open("Output.ppm");
    if (_PPMFile.fail()) {
        std::cerr << "Error while opening PPM file";
        return;
    }
    _PPMFile << "P4" << std::endl;
    _PPMFile << MAX_WIDHT << " " << MAX_HEIGHT << std::endl;
    _PPMFile << "255" << std::endl;
    _PPMFile << std::endl;
    for (auto i : Pixels)
        _PPMFile << i[0] << " " << i[1] << " " << i[2] << " " << i[3]
                 << std::endl;
    _PPMFile.close();
}

// void Render::createRayWindow(/*color, */) {
//     sf::RenderWindow window(sf::VideoMode(MAX_WIDHT, MAX_HEIGHT),
//     "RayTracer"); sf::Image buffer(MAX_WIDHT, MAX_HEIGHT, sf::Color(0, 0,
//     0)); sf::Sprite bufferSprite(buffer); //à revoir
//
//     while (window.isOpen()) {
//         sf::Event event;
//         while (window.pollEvent(event)) {
//             if (event.type == sf::Event::Closed)
//                 window.close();
//         }
//         window.clear(sf::Color::Black);
//         // buffer.SetPixel(z, y, sf::Color(r, g, b));
//
//         // window.draw(bufferSprite);
//
//         window.display();
//     }
//     // Color& pixel = framebuffer[y * width + x] => hot to access the color
// }

void Render::StoreColor(Math::Vec4 &color) {
    Pixels.push_back(color);
}

void initRender(std::unique_ptr<RayTracer::Scene> &scenario, bool DisplayMode) {
    Render render;
    std::optional<std::reference_wrapper<RayTracer::APrimitive>>
        ClosestPrimitive;
    render.getPixels().resize(MAX_WIDHT * MAX_HEIGHT);
    Math::Vec4 Color;
    auto defaultColor = Math::Vec4({0.0, 0.0, 0.0, 0.0});

    for (int i = 0; i != MAX_HEIGHT; i++) {
        for (int j = 0; j != MAX_WIDHT; j++) {
            double u = j;
            double v = i;
            RayTracer::Ray r = scenario->camera.GenerateRay(u, v);
            ClosestPrimitive = lookingForTheClosestHit(scenario->primitives, r);
            if (ClosestPrimitive.has_value()) {
                for (auto Light : scenario->lights) {  // All lights
                    if (Light
                            .hit(ClosestPrimitive.value()
                                     .get()
                                     .hit(r)
                                     .value()
                                     ._point,
                                 ClosestPrimitive.value()
                                     .get()
                                     .hit(r)
                                     .value()
                                     ._normal)
                            .has_value()) {
                        // color =  calcul pour affichier la lumière
                        render.StoreColor(Color);
                    }
                    continue;
                }
            }
            render.StoreColor(defaultColor);
            continue;
        }
    }
    render.GeneratePPM();
    (void)DisplayMode;
    // if (DisplayMode)
    // render.createRayWindow();
}
