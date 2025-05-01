/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#include "Line.hpp"

#ifndef face
#define face

class Face {
    public:
        Face();
        ~Face() = default;

    Line Upper;
    Line Bottom;
    Line Left;
    Line Right;
};

#endif /* !face */
