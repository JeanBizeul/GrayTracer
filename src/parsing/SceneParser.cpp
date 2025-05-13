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

SceneParser::SceneParser(std::string const &filename) : _cfg() {
    try {
        std::cout << "Reading configuration file: " << filename << std::endl;
        _cfg.readFile(filename.c_str());
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
    std::cout << "Configuration file read successfully." << std::endl;
}

SceneParser::~SceneParser() {}

std::unique_ptr<Scene> SceneParser::getScene() {
    std::unique_ptr<Scene> scene = std::make_unique<Scene>();

    std::cout << "Parsing scene..." << std::endl;
    try {
        this->writeScene(scene);
    } catch (const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "Setting not found: " << nfex.getPath() << std::endl;
        std::exit(84);
    } catch (const libconfig::ConfigException &pex) {
        std::cerr << "Error in configuration file: " << pex.what() << std::endl;
        std::exit(84);
    }
    std::cout << "Scene parsed successfully." << std::endl;
    return scene;
}

void SceneParser::writeScene(std::unique_ptr<Scene> &toFill) {
    const libconfig::Setting &root = _cfg.getRoot();
    if (root.getLength() > 1)
        throw libconfig::ExtendedConfigException(
            "\"scene\" isn't the only element at root");
    const libconfig::Setting &sceneSetting = root["scene"];
    if (sceneSetting.getLength() != 4 ||
        sceneSetting.getType() != libconfig::Setting::TypeGroup)
        throw libconfig::ExtendedConfigException(
            "\"scene\" must have 4 elements: \"primitives\", \"cameras\", "
            "\"lights\" and \"background\"");
    const libconfig::Setting &primitivesSetting = sceneSetting["primitives"];
    const libconfig::Setting &camerasSetting = sceneSetting["camera"];
    const libconfig::Setting &ambientSetting = sceneSetting["ambient"];
    const libconfig::Setting &lightsSetting = sceneSetting["lights"];
}
