/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#include <array>
#include "Line.hpp"

#ifndef face
#define face

template <unsigned int N>

class Face
{
    std::array<Line, N> _lines;
};

#endif /* !face */
