/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#include <array>

#include "Line.hpp"

#ifndef SRC_FACE_HPP_
#define SRC_FACE_HPP_

template <unsigned int N>

class Face {
    std::array<Line, N> _lines;
};

#endif  // SRC_FACE_HPP_
