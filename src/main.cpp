/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** main
*/

#include "main.hpp"

#include <iostream>
#include <memory>
#include <unordered_map>

#include <libconfig.h++>

#include "RayTracer/FactoryLoader.hpp"
#include "parsing/SceneParser.hpp"

int main(int ac, char **av) {
    (void)ac;
    (void)av;

    try {
        // Initialize factory loader
        RayTracer::FactoryLoader fc("./plugins/");

        libconfig::Config cfg;
        cfg.readFile("./tests/test.cfg");

        // Get primitives settings
        libconfig::Setting &primitives = cfg.lookup("scene.primitives");
        libconfig::Setting &sphereSetting = primitives[0];

        std::cout << "BEFORE LOADING SPHERE\n";
        std::unique_ptr<RayTracer::APrimitive> sphere =
            fc.create<RayTracer::APrimitive>("sphere", sphereSetting);

        if (!sphere) {
            throw std::runtime_error("Failed to create sphere");
        }

        std::cout << "---> After parsing" << std::endl;
        SceneParser sceneParser("./tests/test.cfg");
        auto scene_elements = sceneParser.getScene();
        initRender(scene_elements, false);
    } catch (const libconfig::SettingNotFoundException &e) {
        std::cerr << "Config error: " << e.what() << std::endl;
        return 1;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
