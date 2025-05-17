/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** main
*/

#include "main.hpp"
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
    RayTracer::FactoryLoader fc("./plugins/");
    //RayTracer::APrimitive sphere =
    //    fc.create<RayTracer::APrimitive>("sphere", {}); use it like this !
    SceneParser sceneParser("./tests/test.cfg");
    (void)ac;
    (void)av;

    auto scene_elements = sceneParser.getScene();
    initRender(scene_elements, false);  //  False => Asking for PPM Output
    return 0;
}
