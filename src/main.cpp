/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** main
*/

#include "parsing/SceneParser.hpp"
#include "RayTracer/FactoryLoader.hpp"

int main(int ac, char **av) {
    RayTracer::FactoryLoader fc("./plugins/");
    // RayTracer::APrimitive sphere =
    //     fc.create<RayTracer::APrimitive>("sphere", {}); use it like this !
    SceneParser sceneParser("./tests/test.cfg");
    (void)ac;
    (void)av;

    auto scene = sceneParser.getScene();
    return 0;
}
