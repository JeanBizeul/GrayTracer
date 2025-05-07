/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** header
*/

#ifndef SRC_FACE_HPP_
    #define SRC_FACE_HPP_
    #include <array>

    #include "Segment.hpp"

namespace RayTracer {
template <unsigned int N>
class Face {
 public:
    Face() = delete;
    Face(std::array<RayTracer::Segment, N> segments)
        : _segs(segments) {};
    ~Face() = default;

 private:
    std::array<RayTracer::Segment, N> _segs;
};
}  // namespace RayTracer

#endif  // SRC_FACE_HPP_
