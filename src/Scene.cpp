/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** Scene implementation
*/

#include "../include/RayTracer/Scene.hpp"

Scene::Scene()
    : camera(Math::Point3(), RayTracer::Screen(Math::Point3(), Math::Vec<3>())),
      Ambient_light() {
}
