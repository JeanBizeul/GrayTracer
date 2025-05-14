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

static void errorThrow(const std::string &msg) {
    throw libconfig::ExtendedConfigException(msg);
}

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
        errorThrow("\"scene\" isn't the only element at root");
    const libconfig::Setting &sceneSetting = root["scene"];
    if (sceneSetting.getLength() != 4 ||
        sceneSetting.getType() != libconfig::Setting::TypeGroup)
        errorThrow(
            "\"scene\" must have 4 elements: \"primitives\", \"cameras\", "
            "\"lights\" and \"background\"");
    const libconfig::Setting &primitivesSetting = sceneSetting["primitives"];
    parsePrimitives(primitivesSetting);
    const libconfig::Setting &camerasSetting = sceneSetting["camera"];
    parseCamera(camerasSetting);
    const libconfig::Setting &ambientSetting = sceneSetting["ambient"];
    const libconfig::Setting &lightsSetting = sceneSetting["lights"];
}

void SceneParser::parseCamera(const libconfig::Setting &cameraSetting) {
    if (cameraSetting.getType() != libconfig::Setting::TypeGroup)
        errorThrow("\"camera\" must be a group");
    if (cameraSetting.getLength() != 3)
        errorThrow(
            "\"camera\" must have 3 elements: \"position\", "
            "\"rotation\" and \"fov\"");
    const libconfig::Setting &positionSetting = cameraSetting["position"];
    if (positionSetting.getType() != libconfig::Setting::TypeArray ||
        positionSetting.getLength() != 3)
        errorThrow(
            "\"position\" must be an array of 3 elements: \"[x, y, z]\"");
    const libconfig::Setting &rotationSetting = cameraSetting["rotation"];
    if (rotationSetting.getType() != libconfig::Setting::TypeArray ||
        rotationSetting.getLength() != 3)
        errorThrow(
            "\"rotation\" must be an array of 3 elements: \"[x, y, z]\"");
    const libconfig::Setting &fovSetting = cameraSetting["fov"];
    if (fovSetting.getType() != libconfig::Setting::TypeFloat)
        errorThrow("\"fov\" must be a float");
    float fov;
    if (!cameraSetting.lookupValue("fov", fov) || fov <= 0.0 || fov >= 180.0) {
        std::cout << fov << std::endl;
        errorThrow("\"fov\" must be between 0 and 180");
    }
}

static void parseSinglePrimitive(const libconfig::Setting &primitiveSetting) {
    const libconfig::Setting &nameSetting = primitiveSetting["name"];
    if (nameSetting.getType() != libconfig::Setting::TypeString)
        errorThrow("\"name\" must be a string");
    const libconfig::Setting &positionSetting = primitiveSetting["position"];
    if (positionSetting.getType() != libconfig::Setting::TypeArray ||
        positionSetting.getLength() != 3)
        errorThrow(
            "\"position\" must be an array of 3 elements: \"[x, y, z]\"");
    const libconfig::Setting &rotationSetting = primitiveSetting["rotation"];
    if (rotationSetting.getType() != libconfig::Setting::TypeArray ||
        rotationSetting.getLength() != 3) {
        errorThrow(
            "\"rotation\" must be an array of 3 elements: \"[x, y, z]\"");
    }
    if (primitiveSetting.getLength() == 4) {
        const libconfig::Setting &materialSetting =
            primitiveSetting["material"];
        if (materialSetting.getType() != libconfig::Setting::TypeString)
            errorThrow("\"material\" must be a string");
        std::string materialPath = materialSetting.c_str();
        if (materialPath.size() < 4 ||
            materialPath.substr(materialPath.size() - 4) != ".mtl")
            errorThrow("\"material\" path must end with \".mtl\"");
        if (access(materialPath.c_str(), F_OK) == -1)
            errorThrow("\"material\" must be a valid filepath");
    }
}

void SceneParser::parsePrimitives(const libconfig::Setting &primitivesSetting) {
    if (primitivesSetting.getType() != libconfig::Setting::TypeList)
        errorThrow("\"primitives\" must be a list of primitives");
    for (int i = 0; i < primitivesSetting.getLength(); ++i) {
        const libconfig::Setting &primitiveSetting = primitivesSetting[i];
        if (primitiveSetting.getType() != libconfig::Setting::TypeGroup)
            errorThrow("Primitive must be a group");
        if (primitiveSetting.getLength() > 4)
            errorThrow(
                "Primitive must have a maximum of 4 elements: \"name\", "
                "\"position\", \"rotation\" and \"material\"");
        parseSinglePrimitive(primitiveSetting);
    }
}
