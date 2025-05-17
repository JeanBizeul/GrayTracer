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

/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** main
*/

#include "Render.hpp"
#include "parsing/SceneParser.hpp"
#include "main.hpp"


int main(int ac, char **av) {
    (void)ac;
    (void)av;

    RayTracer::FactoryLoader fc("./plugins/");
    libconfig::Config cfg;
    cfg.readFile("./tests/test.cfg");

    libconfig::Setting& primitives = cfg.lookup("scene.primitives");
    libconfig::Setting& sphereSetting = primitives[0];  // Assuming it's a "sphere"

    std::unique_ptr<RayTracer::APrimitive> sphere =
        fc.create<RayTracer::APrimitive>("sphere", sphereSetting); //use it like this !
    //SceneParser sceneParser("./tests/test.cfg");
    //auto scene_elements = sceneParser.getScene();
    std::cout << "---> After le parsing" << std::endl;
    //initRender(scene_elements, false);  //  False => Asking for PPM Output
    return 0;
}

//int main(int ac, char **av) {
//    (void)ac;
//    (void)av;
//
//    try {
//        // Create shared context for factories
//        auto context = std::make_shared<RayTracer::FactoryContext>();
//
//        // Load factories
//        libconfig::Config cfg;
//        cfg.readFile("./tests/test.cfg");
//        
//        libconfig::Setting& primitives = cfg.lookup("scene.primitives");
//        libconfig::Setting& sphereSetting = primitives[0];  // Assuming it's a "sphere"
//        
//        RayTracer::FactoryLoader fc("./plugins/");
//        std::unique_ptr<RayTracer::APrimitive> sphere =
//        fc.create<RayTracer::APrimitive>("sphere", sphereSetting); //use it like this ! //segfault here
//        // Parse scene
//        SceneParser sceneParser("./tests/test.cfg");
//        auto scene_elements = sceneParser.getScene();
//        
//        std::cout << "---> After parsing" << std::endl;
//        //initRender(scene_elements, false);  //  False => Asking for PPM Output
//        
//        return 0;
//    } catch (const libconfig::FileIOException &e) {
//        std::cerr << "Error reading config file: " << e.what() << std::endl;
//        return 84;
//    } catch (const libconfig::ParseException &e) {
//        std::cerr << "Parse error in config file: " << e.what() << std::endl;
//        return 84;
//    } catch (const std::exception &e) {
//        std::cerr << "Error: " << e.what() << std::endl;
//        return 84;
//    }
//}
