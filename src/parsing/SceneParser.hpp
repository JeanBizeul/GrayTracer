/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** SceneParser
*/

#ifndef SRC_PARSING_SCENEPARSER_HPP_
#define SRC_PARSING_SCENEPARSER_HPP_

#include <memory>
#include <string>
#include <vector>

#include <libconfig.h++>

#include "RayTracer/Scene.hpp"

class SceneParser {
 public:
    SceneParser() = delete;
    explicit SceneParser(std::string const &filename);
    ~SceneParser();
    std::unique_ptr<Scene> getScene();

 private:
    libconfig::Config cfg;
};

#endif  // SRC_PARSING_SCENEPARSER_HPP_
