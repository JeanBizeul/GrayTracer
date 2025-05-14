/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** render
*/

#define MAX_HEIGHT 700
#define MAX_WIDHT 1000

#include "Render.hpp"


// bool lookingForAHit(std::vector<RayTracer::I3dObject> primit, RayTracer::Ray
// ray, bool *hit)
//{
//     for (auto &i: primit) {
//         if (i.hit(ray))
//             return true;  //struct
//     }
//     return false;
// }

void GeneratePPM(/*vector of primitives*/std::vector<std::unique_ptr<RayTracer::APrimitive>> primitives, Scene scenario) {
    std::cout << "P3" << std::endl;
    std::cout << MAX_WIDHT << " " << MAX_HEIGHT << std::endl;
    std::cout << "255" << std::endl;

    // Read the 2D Vector of the struct
        for (int i = 0; i != MAX_HEIGHT; i++) {
        for (int j = 0; j != MAX_WIDHT; j++) {
            double u = j;
            double v = i;
            RayTracer::Ray r = scenario.camera.GenerateRay(u, v);
            //lookingForAHit(primitives, r, &hit);
            if (primitives[0]->hit(r)) {
                std::cout << "Hit a primitive" << std::endl;
                // primitive
            } else {
                std::cout << "0 0 0" << std::endl;  // black
            }
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
    bool DisplayMode) { // get the infos if PPM the call PPM if not sfml
    Scene scenario;
    std::unique_ptr<RayTracer::Sphere> sphere;
    std::unique_ptr<RayTracer::IFactory<RayTracer::Sphere>> factory_element;
    std::unique_ptr<DLLoader<RayTracer::IFactory<RayTracer::Sphere>>>
        factory_loader;

    libconfig::Config cfg;
    cfg.readFile("file.conf");
    libconfig::Setting &file = cfg.lookup("scene");

    factory_loader =
        std::make_unique<DLLoader<RayTracer::IFactory<RayTracer::Sphere>>>(
            "libspherefactory.so");
    auto instance = factory_loader->getInstance();
    if (instance->getObjectTag() == "sphere")  {
        factory_element = std::move(instance);
        sphere = factory_element->createObject(file);
    }

    //std::vector<std::unique_ptr<RayTracer::APrimitive>> primitives; // appeller les factories
    // std::vector<std::unique_ptr<nts::IComponent>>&
    //primitives.push_back(std::move(sphere));
    //bool hit;

    if (DisplayMode) {
        createRayWindown();
    } else {
        //GeneratePPM(primitives, scenario);
    }
}
