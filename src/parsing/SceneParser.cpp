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
#include <vector>

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
    parsePrimitives(primitivesSetting, toFill->primitives);
    const libconfig::Setting &camerasSetting = sceneSetting["camera"];
    parseCamera(camerasSetting, toFill->camera);
    const libconfig::Setting &ambientSetting = sceneSetting["ambient"];
    parseAmbient(ambientSetting, toFill->ambient);
    const libconfig::Setting &lightsSetting = sceneSetting["lights"];
    parseLights(lightsSetting, toFill->lights);
}

static void parseCoordinates(const libconfig::Setting &setting, Math::Vec3 &vec,
                             const std::string &name) {
    if (setting.getType() != libconfig::Setting::TypeArray ||
        setting.getLength() != 3)
        errorThrow("\"" + name +
                   "\" must be an array of 3 elements: \"[x, y, z]\"");
    vec.x() = static_cast<int>(setting[0]);
    vec.y() = static_cast<int>(setting[1]);
    vec.z() = static_cast<int>(setting[2]);
}

static void parseRgb(const libconfig::Setting &setting, Math::Vec3 &vec,
                     const std::string &name) {
    if (setting.getType() != libconfig::Setting::TypeArray ||
        setting.getLength() != 3)
        errorThrow("\"" + name +
                   "\" must be an array of 3 elements: \"[r, g, b]\"");
    int r = setting[0], g = setting[1], b = setting[2];
    if (r < 0 || r > 255)
        errorThrow("\"" + name + "[0]\" must be between 0 and 255");
    if (g < 0 || g > 255)
        errorThrow("\"" + name + "[1]\" must be between 0 and 255");
    if (b < 0 || b > 255)
        errorThrow("\"" + name + "[2]\" must be between 0 and 255");
    vec.r() = r;
    vec.g() = g;
    vec.b() = b;
}

static void parseSingleLight(const libconfig::Setting &lightSetting) {
    if (lightSetting.getType() != libconfig::Setting::TypeGroup)
        errorThrow("Light must be a group");
    // Parsing done by the factories
}

void SceneParser::parseLights(const libconfig::Setting &lightsSetting,
                              std::vector<RayTracer::ILight> &lights) {
    if (lightsSetting.getType() != libconfig::Setting::TypeList)
        errorThrow("\"lights\" must be a list of lights");
    for (int i = 0; i < lightsSetting.getLength(); ++i) {
        const libconfig::Setting &lightSetting = lightsSetting[i];
        parseSingleLight(lightSetting);
    }
}

void SceneParser::parseAmbient(const libconfig::Setting &ambientSetting,
                               Math::Vec3 &ambient) {
    parseRgb(ambientSetting, ambient, "ambient");
}

void SceneParser::parseCamera(const libconfig::Setting &cameraSetting,
                              RayTracer::Camera &camera) {
    if (cameraSetting.getType() != libconfig::Setting::TypeGroup)
        errorThrow("\"camera\" must be a group");
    if (cameraSetting.getLength() != 3)
        errorThrow(
            "\"camera\" must have 3 elements: \"position\", "
            "\"rotation\" and \"fov\"");
    const libconfig::Setting &positionSetting = cameraSetting["position"];
    Math::Vec3 position;
    parseCoordinates(positionSetting, position, "position");
    camera.origin = position;
    const libconfig::Setting &rotationSetting = cameraSetting["rotation"];
    Math::Vec3 rotation;
    parseCoordinates(rotationSetting, rotation, "rotation");
    const libconfig::Setting &fovSetting = cameraSetting["fov"];
    if (fovSetting.getType() != libconfig::Setting::TypeFloat)
        errorThrow("\"fov\" must be a float");
    float fov = cameraSetting["fov"];
    if (fov <= 0.0 || fov >= 180.0)
        errorThrow("\"fov\" must be between 0 and 180");
}

static void parseSinglePrimitive(const libconfig::Setting &primitiveSetting) {
    if (primitiveSetting.getType() != libconfig::Setting::TypeGroup)
        errorThrow("Primitive must be a group");
    // Parsing done by the factories
}

void SceneParser::parsePrimitives(
    const libconfig::Setting &primitivesSetting,
    std::vector<RayTracer::APrimitive> &primitives) {
    if (primitivesSetting.getType() != libconfig::Setting::TypeList)
        errorThrow("\"primitives\" must be a list of primitives");
    for (int i = 0; i < primitivesSetting.getLength(); ++i) {
        const libconfig::Setting &primitiveSetting = primitivesSetting[i];
        parseSinglePrimitive(primitiveSetting);
    }
}
