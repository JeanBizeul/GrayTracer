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

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window.hpp>

#include "Plugins/Factories/Primitives/Sphere/src/Sphere.hpp"
#include "RayTracer/DLLoader.hpp"
#include "RayTracer/I3dObject.hpp"
#include "RayTracer/Scene.hpp"

class Render {
 public:
    Render() = default;
    ~Render() = default;

    // Methods
    void createRayWindow(/*color, */ double, double);
    void GeneratePPM(/*color*/);

    // Getters
    std::ofstream &getPPM(void);
    sf::RenderWindow &GetWindow(void);
    sf::Texture &getTexture(void);
    sf::Sprite &getSprite(void);

 private:
    std::ofstream _PPMFile;
    sf::RenderWindow win;
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif  // SRC_RENDER_HPP_
