/*
** EPITECH PROJEC2025
** BS-Raytracer
** File description:
** vec
*/

#ifndef MATH_VEC_TPP_
    #define MATH_VEC_TPP_
    #include <cstddef>
    #include <array>
    #include <stdexcept>
    #include <math.h>

namespace Math
{
template<std::size_t N>
Vec<N>::Vec()
{
    static_assert(N > 0, "Vector of size 0 are not allowed");
    _arr.fill(0.0f);
}

template<std::size_t N>
Vec<N>::Vec(double val)
{
    static_assert(N > 0, "Vector of size 0 are not allowed");
    _arr.fill(val);
}

template<std::size_t N>
Vec<N>::Vec(std::array<double, N> vals)
{
    static_assert(N > 0, "Vector of size 0 are not allowed");
    _arr = vals;
}

#pragma region Computing

template <std::size_t N>
double Vec<N>::dot(const Vec<N> &other) const
{
    double result = 0.0f;
    
    for (std::size_t i = 0; i < _arr.size(); i++)
    result += _arr[i] * other[i];
    return result;
}

template <std::size_t N>
double Vec<N>::lenght() const
{
    double sum = 0.0f;

    for (double val : _arr)
        sum += val * val;
    return std::sqrt(sum);
}

template <std::size_t N>
Vec<N> Vec<N>::normalize() const
{
    double len = lenght();

    if (len == 0.0)
        throw std::invalid_argument("Cannot normalize a zero-lenght vector");
    return *this / len;
}

#pragma endregion Computing

#pragma region Operators

// operators + - * / with other Vec

template <std::size_t N>
Vec<N> Vec<N>::operator+(const Vec<N> &other) const
{
    std::array<double, N> result;

    for (std::size_t i = 0; i < result.size(); i ++)
        result[i] = _arr[i] + other[i];
    return vec<N>(result);
}

template <std::size_t N>
Vec<N> Vec<N>::operator-(const Vec<N> &other) const
{
    std::array<double, N> result;

    for (std::size_t i = 0; i < result.size(); i ++)
        result[i] = _arr[i] - other[i];
    return vec<N>(result);
}

template <std::size_t N>
Vec<N> Vec<N>::operator*(const Vec<N> &other) const
{
    std::array<double, N> result;

    for (std::size_t i = 0; i < result.size(); i ++)
        result[i] = _arr[i] * other[i];
    return vec<N>(result);
}

template <std::size_t N>
Vec<N> Vec<N>::operator/(const Vec<N> &other) const
{
    std::array<double, N> result;

    for (std::size_t i = 0; i < result.size(); i ++) {
        if (other[i] == 0)
            throw std::invalid_argument("Division by zero");
        result[i] = _arr[i] / other[i];
    }
    return vec<N>(result);
}

// operators * / with doubles

template <std::size_t N>
Vec<N> Vec<N>::operator*(double val) const
{
    std::array<double, N> result;

    for (std::size_t i = 0; i < result.size(); i ++)
        result[i] = _arr[i] * val;
    return vec<N>(result);
}

template <std::size_t N>
Vec<N> Vec<N>::operator/(double val) const
{
    std::array<double, N> result;

    if (val == 0)
        throw std::invalid_argument("Division by zero");
    for (std::size_t i = 0; i < result.size(); i ++)
        result[i] = _arr[i] / val;
    return vec<N>(result);
}

// operators += -= *= /= with other Vec

template <std::size_t N>
void Vec<N>::operator+=(const Vec<N> &other)
{
    for (std::size_t i = 0; i < _arr.size(); i ++)
        _arr[i] += other[i];
}

template <std::size_t N>
void Vec<N>::operator-=(const Vec<N> &other)
{
    for (std::size_t i = 0; i < _arr.size(); i ++)
        _arr[i] -= other[i];
}

template <std::size_t N>
void Vec<N>::operator*=(const Vec<N> &other)
{
    for (std::size_t i = 0; i < _arr.size(); i ++)
        _arr[i] *= other[i];
}

template <std::size_t N>
void Vec<N>::operator/=(const Vec<N> &other)
{
    for (std::size_t i = 0; i < _arr.size(); i ++) {
        if (other[i] == 0)
            throw std::invalid_argument("Division by zero");
        _arr[i] /= other[i];
    }
}

// operators *= /= with doubles

template <std::size_t N>
void Vec<N>::operator*=(double val)
{
    for (auto &v : _arr)
        v *= val;
}

template <std::size_t N>
void Vec<N>::operator/=(double val)
{
    for (auto &v : _arr)
        v /= val;
}

#pragma endregion Operators

#pragma region Getters Setters

template<std::size_t N>
template<std::size_t P>
double &Vec<N>::get() {
    static_assert(P < N, "Vec.get<P>(): Index out of range");
    return _arr[P];
}

template<std::size_t N>
double &Vec<N>::operator[](std::size_t index)
{
    if (index >= _arr.size())
        throw std::out_of_range("Vec[]: Index out of range");
    else
        return _arr[index];
}

// xyzw

template <std::size_t N>
double &Vec<N>::x()
{
    return _arr[0];
}

template <std::size_t N>
double &Vec<N>::y()
{
    static_assert(N >= 2, "Vec::y() is only available on Vectors of size 2 and more");
    return _arr[1];
}

template <std::size_t N>
double &Vec<N>::z()
{
    static_assert(N >= 3, "Vec::z() is only available on Vectors of size 3 and more");
    return _arr[2];
}

template <std::size_t N>
double &Vec<N>::w()
{
    static_assert(N >= 4, "Vec::w() is only available on Vectors of size 4 and more");
    return _arr[3];
}



template <std::size_t N>
double Vec<N>::x() const
{
    return _arr[0];
}

template <std::size_t N>
double Vec<N>::y() const
{
    static_assert(N >= 2, "Vec::y() is only available on Vectors of size 2 and more");
    return _arr[1];
}

template <std::size_t N>
double Vec<N>::z() const
{
    static_assert(N >= 3, "Vec::z() is only available on Vectors of size 3 and more");
    return _arr[2];
}

template <std::size_t N>
double Vec<N>::w() const
{
    static_assert(N >= 4, "Vec::w() is only available on Vectors of size 4 and more");
    return _arr[3];
}

// rgba

template <std::size_t N>
double &Vec<N>::r()
{
    return _arr[0];
}

template <std::size_t N>
double &Vec<N>::g()
{
    static_assert(N >= 2, "Vec::g() is only available on Vectors of size 2 and more");
    return _arr[1];
}

template <std::size_t N>
double &Vec<N>::b()
{
    static_assert(N >= 3, "Vec::b() is only available on Vectors of size 3 and more");
    return _arr[2];
}

template <std::size_t N>
double &Vec<N>::a()
{
    static_assert(N >= 4, "Vec::a() is only available on Vectors of size 4 and more");
    return _arr[3];
}


template <std::size_t N>
double Vec<N>::r() const
{
    return _arr[0];
}

template <std::size_t N>
double Vec<N>::g() const
{
    static_assert(N >= 2, "Vec::g() is only available on Vectors of size 2 and more");
    return _arr[1];
}

template <std::size_t N>
double Vec<N>::b() const
{
    static_assert(N >= 3, "Vec::b() is only available on Vectors of size 3 and more");
    return _arr[2];
}

template <std::size_t N>
double Vec<N>::a() const
{
    static_assert(N >= 4, "Vec::a() is only available on Vectors of size 4 and more");
    return _arr[3];
}

// uv

template <std::size_t N>
double &Vec<N>::u()
{
    return _arr[0];
}

template <std::size_t N>
double &Vec<N>::v()
{
    static_assert(N >= 2, "Vec::v() is only available on Vectors of size 2 and more");
    return _arr[1];
}


template <std::size_t N>
double Vec<N>::u() const
{
    return _arr[0];
}

template <std::size_t N>
double Vec<N>::v() const
{
    static_assert(N >= 2, "Vec::v() is only available on Vectors of size 2 and more");
    return _arr[1];
}

#pragma endregion Getters Setters
}  // namespace Math

#endif  // MATH_VEC_TPP_
