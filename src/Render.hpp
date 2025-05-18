/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#ifndef SRC_RENDER_HPP_
#define SRC_RENDER_HPP_

#include <cstddef>
#include <fstream>
#include <iostream>
#include <memory>
#include <optional>
#include <ostream>
#include <utility>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window.hpp>

#include "DLLoader.hpp"
#include "RayTracer/I3dObject.hpp"
#include "RayTracer/Scene.hpp"

class Render {
 public:
    Render() {}
    ~Render() = default;

    // Methods
    void createRayWindow(/*color, */ double, double);
    void GeneratePPM(/*color*/);
    void StoreColor();
    // Getters
    std::ofstream &getPPM(void);
    sf::RenderWindow &GetWindow(void);
    sf::Texture &getTexture(void);
    sf::Sprite &getSprite(void);
    std::vector<RayTracer::vec4> &getPixels(void);

 private:
    std::ofstream _PPMFile;
    sf::RenderWindow win;
    sf::Texture texture;
    sf::Sprite sprite;
    std::vector<RayTracer::vec4> Pixels;
};

void initRender(RayTracer::Scene, bool);
#endif  // SRC_RENDER_HPP_
