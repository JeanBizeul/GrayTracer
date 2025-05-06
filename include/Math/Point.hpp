/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** point
*/

#ifndef POINT_HPP_
    #define POINT_HPP_
    #include <cstddef>
    #include <array>

    #include "Vec.hpp"

namespace Math
{
    template<std::size_t N>
    class Point
    {
        public:
            Point();
            Point(double val);
            Point(std::array<double, N> vals);

            ~Point() = default;

            Point<N> operator+(const Vec<N> &vector) const;
            Point<N> operator-(const Vec<N> &vector) const;
            Point<N> operator+(const Point<N> &Point) const;
            Point<N> operator-(const Point<N> &Point) const;

            void operator+=(const Vec<N> &vector);
            void operator-=(const Vec<N> &vector);

            template<std::size_t P>
            double get() const;
            double operator[](std::size_t index) const;

            double x() const;
            double y() const;
            double z() const;
            double w() const;

            double r() const;
            double g() const;
            double b() const;
            double a() const;

            double u() const;
            double v() const;
        private:
            std::array<double, N> _arr;
    };
}

#include "Point.tpp"
#endif /* !POINT_HPP_ */
