/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** point
*/

#ifndef MATH_POINT_HPP_
#define MATH_POINT_HPP_
#include <array>
#include <cstddef>

#include "Vec.hpp"

namespace Math {
template <std::size_t N>
class Point {
 public:
    Point();
    explicit Point(double val);
    explicit Point(std::array<double, N> vals);

    ~Point() = default;

    Point<N> operator+(const Vec<N> &vector) const;
    Point<N> operator-(const Vec<N> &vector) const;
    Point<N> operator+(const Point<N> &Point) const;
    Point<N> operator-(const Point<N> &Point) const;

    void operator+=(const Vec<N> &vector);
    void operator-=(const Vec<N> &vector);

    template <std::size_t P>
    double &get();
    double &operator[](std::size_t index);

    double &x();
    double &y();
    double &z();
    double &w();

    double &r();
    double &g();
    double &b();
    double &a();

    double &u();
    double &v();

 private:
    std::array<double, N> _arr;
};
}  // namespace Math

#include "Point.tpp"
#endif  // MATH_POINT_HPP_
