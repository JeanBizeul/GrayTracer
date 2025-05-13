/*
** EPITECH PROJECT, 2025
** GrayTracer
** File description:
** point
*/

#ifndef MATH_POINT_TPP_
    #define MATH_POINT_TPP_
    #include <cstddef>
    #include <array>

    #include "Vec.hpp"

namespace Math
{
template<std::size_t N>
Point<N>::Point()
{
    static_assert(N > 0, "Point with 0 dimensions are not allowed");
}

template<std::size_t N>
Point<N>::Point(double val)
{
    static_assert(N > 0, "Point with 0 dimensions are not allowed");
    for (auto &v : _arr)
        v = val;
}

template<std::size_t N>
Point<N>::Point(std::array<double, N> vals)
{
    static_assert(N > 0, "Point with 0 dimensions are not allowed");
    for (std::size_t i = 0; i < _arr.size(); i++)
        _arr[i] = vals[i];
}

#pragma region Operators

// operators + - with other vec

template <std::size_t N>
Point<N> Point<N>::operator+(const Vec<N> &other) const
{
    std::array<double, N> result;

    for (std::size_t i = 0; i < result.size(); i ++)
        result[i] = _arr[i] + other[i];
    return result;
}

template <std::size_t N>
Point<N> Point<N>::operator-(const Vec<N> &other) const
{
    std::array<double, N> result;

    for (std::size_t i = 0; i < result.size(); i ++)
        result[i] = _arr[i] - other[i];
    return result;
}

// operators + - with other point

template <std::size_t N>
Point<N> Point<N>::operator+(const Point<N> &other) const
{
    std::array<double, N> result;

    for (std::size_t i = 0; i < result.size(); i ++)
        result[i] = _arr[i] + other[i];
    return result;
}

template <std::size_t N>
Point<N> Point<N>::operator-(const Point<N> &other) const
{
    std::array<double, N> result;

    for (std::size_t i = 0; i < result.size(); i ++)
        result[i] = _arr[i] - other[i];
    return result;
}

// operators += -= with other vec

template <std::size_t N>
void Point<N>::operator+=(const Vec<N> &other)
{
    for (std::size_t i = 0; i < _arr.size(); i ++)
        _arr[i] += other[i];
}

template <std::size_t N>
void Point<N>::operator-=(const Vec<N> &other)
{
    for (std::size_t i = 0; i < _arr.size(); i ++)
        _arr[i] -= other[i];
}

#pragma endregion Operators

#pragma region Getters Setters

template<std::size_t N>
template<std::size_t P>
double Point<N>::get() const {
    static_assert(P < N, "point.get<P>(): Index out of range");
    return _arr[P];
}

template<std::size_t N>
double Point<N>::operator[](std::size_t index) const
{
    if (index < _arr.size())
        throw std::out_of_range("point[]: Index out of range");
    else
        return _arr[index];
}

// xyzw

template <std::size_t N>
double Point<N>::x() const
{
    return _arr[0];
}

template <std::size_t N>
double Point<N>::y() const
{
    static_assert(N >= 2,
        "point::y is only available on point with 2 dimensions and more");
    return _arr[1];
}

template <std::size_t N>
double Point<N>::z() const
{
    static_assert(N >= 3,
        "point::z is only available on point with 3 dimensions and more");
    return _arr[2];
}

template <std::size_t N>
double Point<N>::w() const
{
    static_assert(N >= 4,
        "point::w is only available on point with 4 dimensions and more");
    return _arr[3];
}

// rgba

template <std::size_t N>
double Point<N>::r() const
{
    return _arr[0];
}

template <std::size_t N>
double Point<N>::g() const
{
    static_assert(N >= 2,
        "point::g is only available on point with 2 dimensions and more");
    return _arr[1];
}

template <std::size_t N>
double Point<N>::b() const
{
    static_assert(N >= 3,
        "point::b is only available on point with 3 dimensions and more");
    return _arr[2];
}

template <std::size_t N>
double Point<N>::a() const
{
    static_assert(N >= 4,
        "point::a is only available on point with 4 dimensions and more");
    return _arr[3];
}

// uv

template <std::size_t N>
double Point<N>::u() const
{
    return _arr[0];
}

template <std::size_t N>
double Point<N>::v() const
{
    static_assert(N >= 2,
        "point::v is only available on point with 2 dimensions and more");
    return _arr[1];
}

#pragma endregion Getters Setters
}  // namespace Math

#endif // MATH_POINT_TPP_

