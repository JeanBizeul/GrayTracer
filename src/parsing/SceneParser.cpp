/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** SceneParser
*/

#include "SceneParser.hpp"

#include <iostream>
#include <memory>
#include <string>

#include <libconfig.h++>

SceneParser::SceneParser(std::string const &filename) : cfg() {
    try {
        std::cout << "Reading configuration file: " << filename << std::endl;
        cfg.readFile(filename.c_str());
    } catch (const libconfig::FileIOException &fioex) {
        std::cerr << "I/O error while reading file: " << fioex.what()
                  << std::endl;
        std::exit(84);
    } catch (const libconfig::ParseException &pex) {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
                  << " - " << pex.getError() << std::endl;
        std::exit(84);
    } catch (const libconfig::ConfigException &pex) {
        std::cerr << "Error in configuration file: " << pex.what() << std::endl;
        std::exit(84);
    }
}

SceneParser::~SceneParser() {
}

std::unique_ptr<Scene> SceneParser::getScene() {
    return std::make_unique<Scene>();
}
