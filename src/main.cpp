/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** main
*/

#include "main.hpp"

#include "parsing/SceneParser.hpp"

int main(int ac, char **av) {
    SceneParser sceneParser("./tests/test.cfg");
    (void)ac;
    (void)av;

    auto scene = sceneParser.getScene();
    return 0;
}
