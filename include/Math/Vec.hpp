/*
** EPITECH PROJECT, 2025
** BS-Raytracer
** File description:
** vec
*/

#ifndef MATH_VEC_HPP_
    #define MATH_VEC_HPP_
    #include <cstddef>
    #include <array>

namespace Math {
template<std::size_t N>
class Vec {
 public:
    Vec();
    explicit Vec(double val);
    explicit Vec(std::array<double, N> vals);

    ~Vec() = default;

    double dot(const Vec<N> &other) const;

    Vec<N> operator+(const Vec<N> &other) const;
    Vec<N> operator-(const Vec<N> &other) const;
    Vec<N> operator*(const Vec<N> &other) const;
    Vec<N> operator/(const Vec<N> &other) const;

    Vec<N> operator*(double val) const;
    Vec<N> operator/(double val) const;

    void operator+=(const Vec<N> &other);
    void operator-=(const Vec<N> &other);
    void operator*=(const Vec<N> &other);
    void operator/=(const Vec<N> &other);

    void operator*=(double val);
    void operator/=(double val);

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
}  // namespace Math

#include "Vec.tpp"
#endif  // MATH_VEC_HPP_
