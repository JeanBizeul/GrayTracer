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
    void writeScene(std::unique_ptr<Scene> &toFill);
    void parsePrimitives(const libconfig::Setting &primitivesSetting,
                         std::vector<RayTracer::APrimitive> &primitives);
    void parseCamera(const libconfig::Setting &cameraSetting,
                     RayTracer::Camera &camera);
    void parseAmbient(const libconfig::Setting &ambientSetting,
                      Math::Vec3 &ambient);
    void parseLights(const libconfig::Setting &lightsSetting,
                     std::vector<RayTracer::ILight> &lights);
    libconfig::Config _cfg;
};

namespace libconfig {
class ExtendedConfigException : public libconfig::ConfigException {
 public:
    explicit ExtendedConfigException(std::string msg)
        : libconfig::ConfigException(), _msg(msg) {}

    const char *what() const noexcept {
        return _msg.c_str();
    }

 private:
    std::string _msg;
};
};  // namespace libconfig

#endif  // SRC_PARSING_SCENEPARSER_HPP_
