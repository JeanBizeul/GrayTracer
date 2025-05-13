/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** render
*/

#include <iostream>
#define MAX_HEIGHT 700
#define MAX_WIDHT 1000

#include "../include/RayTracer/Scene.hpp"
#include <SFML/Window.hpp>

bool lookingForAHit(std::vector<RayTracer::IPrimitive> primit, RayTracer::Ray ray, bool *hit)
{
    for (auto &i: primit) {
        if (i.hit(ray))
            return true;  //struct
    }
    return false;
}

void GeneratePPM() //Generate PPM Output
{
    std::cout << "P3" << std::endl;
    std::cout << MAX_WIDHT << " " << MAX_HEIGHT << std::endl;
    std::cout << "255" << std::endl;

    //Read the 2D Vector of the struct
}

void createRayWindown()
{
    bool set = false;
    sf::Window window(sf::VideoMode(MAX_WIDHT, MAX_HEIGHT), "RayTracer");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (!set) {
            //draw image
            set = true;
        }
    }
}

void initRender(bool DisplayMode) //get the infos if PPM the call PPM if not sfml
{
    Scene scenario;
    double u, v;
    std::vector<RayTracer::IPrimitive> primitives;
    bool hit;

    for (int i = 0; i != MAX_HEIGHT; i++) {
        for (int j = 0; j != MAX_WIDHT; j++) {
            double u = j;
            double v = i;
            RayTracer::Ray r = scenario.camera.GenerateRay(u, v);
            lookingForAHit(primitives, r, &hit);
            if (hit) {
                //primitive
            } else {
                std::cout << "0 0 0" << std::endl; //black
            }
        }
    }
    if (DisplayMode) {
        createRayWindown();
    } else {
        GeneratePPM();
    }
}