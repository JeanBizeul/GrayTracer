/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#include "Face.hpp"

#ifndef SCREEN
#define SCREEN

class Screen {
    public:
        Screen();
        ~Screen() = default;

    static Face<4> screen;
};

#endif /* !SCREEN */
