/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#include "Face.hpp"

#ifndef SRC_SCREEN_HPP_
#define SRC_SCREEN_HPP_

class Screen {
 public:
    Screen();
    ~Screen() = default;

    static Face<4> screen;
};

#endif  // SRC_SCREEN_HPP_
