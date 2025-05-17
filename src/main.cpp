/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** main
*/

#include "main.hpp"
#include <memory>
#include <libconfig.h++>

#include "parsing/SceneParser.hpp"
#include "RayTracer/FactoryLoader.hpp"


int main(int ac, char **av) {
    (void)ac;
    (void)av;

    // Create a shared context for factories
    //auto context = std::make_shared<RayTracer::FactoryContext>();
    
    // Initialize factory loader with the context
    RayTracer::FactoryLoader fc("./plugins/");
    libconfig::Config cfg;
    cfg.readFile("./tests/test.cfg");

    libconfig::Setting& primitives = cfg.lookup("scene.primitives");
    libconfig::Setting& sphereSetting = primitives[0];  // Assuming it's a "sphere"

    SceneParser sceneParser("./tests/test.cfg");
    std::unique_ptr<RayTracer::APrimitive> sphere =
        fc.create<RayTracer::APrimitive>("sphere", sphereSetting); //use it like this !
    //auto scene_elements = sceneParser.getScene();
    std::cout << "---> After le parsing" << std::endl;
    //initRender(scene_elements, false);  //  False => Asking for PPM Output
    return 0;
}
