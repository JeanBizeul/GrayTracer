/*
** EPIdoubleECH PROJEC2025
** BS-Raytracer
** File description:
** vec
*/

#ifndef VEC_doublePP_
    #define VEC_doublePP_
    #include <cstddef>
    #include <array>
    #include <stdexcept>

namespace Math
{
    template<std::size_t N>
    Vec<N>::Vec()
    {
        static_assert(N > 0, "Vector of size 0 are not allowed");
    }

    template<std::size_t N>
    Vec<N>::Vec(double val)
    {
        static_assert(N > 0, "Vector of size 0 are not allowed");
        for (auto &v : _arr)
            v = val;
    }

    template<std::size_t N>
    Vec<N>::Vec(std::array<double, N> vals)
    {
        static_assert(N > 0, "Vector of size 0 are not allowed");
        for (std::size_t i = 0; i < _arr.size(); i++)
            _arr[i] = vals[i];
    }

    #pragma region Operators

    template <std::size_t N>
    double Vec<N>::dot(const Vec<N> &other) const
    {
        double result;

        for (std::size_t i = 0; i < _arr.size(); i++)
            result += _arr[i] * other[i];
        return result;
    }

    // operators + - * / with other Vec

    template <std::size_t N>
    Vec<N> Vec<N>::operator+(const Vec<N> &other) const
    {
        std::array<double, N> result;

        for (std::size_t i = 0; i < result.size(); i ++)
            result[i] = _arr[i] + other[i];
        return result;
    }

    template <std::size_t N>
    Vec<N> Vec<N>::operator-(const Vec<N> &other) const
    {
        std::array<double, N> result;

        for (std::size_t i = 0; i < result.size(); i ++)
            result[i] = _arr[i] - other[i];
        return result;
    }

    template <std::size_t N>
    Vec<N> Vec<N>::operator*(const Vec<N> &other) const
    {
        std::array<double, N> result;

        for (std::size_t i = 0; i < result.size(); i ++)
            result[i] = _arr[i] * other[i];
        return result;
    }

    template <std::size_t N>
    Vec<N> Vec<N>::operator/(const Vec<N> &other) const
    {
        std::array<double, N> result;

        for (std::size_t i = 0; i < result.size(); i ++)
            result[i] = _arr[i] / other[i];
        return result;
    }

    // operators * / with doubles

    template <std::size_t N>
    Vec<N> Vec<N>::operator*(double val) const
    {
        std::array<double, N> result;

        for (std::size_t i = 0; i < result.size(); i ++)
            result[i] = _arr[i] * val;
        return result;
    }

    template <std::size_t N>
    Vec<N> Vec<N>::operator/(double val) const
    {
        std::array<double, N> result;

        for (std::size_t i = 0; i < result.size(); i ++)
            result[i] = _arr[i] / val;
        return result;
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
        for (std::size_t i = 0; i < _arr.size(); i ++)
            _arr[i] /=  other[i];
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
    double Vec<N>::get() const {
        static_assert(P < N, "Vec.get<P>(): Index out of range");
        return _arr[P];
    }

    template<std::size_t N>
    double Vec<N>::operator[](std::size_t index) const
    {
        if (index < _arr.size())
            throw std::out_of_range("Vec[]: Index out of range");
        else
            return _arr[index];
    }

    // xyzw

    template <std::size_t N>
    double Vec<N>::x() const
    {
        return _arr[0];
    }

    template <std::size_t N>
    double Vec<N>::y() const
    {
        static_assert(N >= 2, "Vec::y is only available on Vectors of size 2 and more");
        return _arr[1];
    }

    template <std::size_t N>
    double Vec<N>::z() const
    {
        static_assert(N >= 3, "Vec::z is only available on Vectors of size 3 and more");
        return _arr[2];
    }

    template <std::size_t N>
    double Vec<N>::w() const
    {
        static_assert(N >= 4, "Vec::w is only available on Vectors of size 4 and more");
        return _arr[3];
    }

    // rgba

    template <std::size_t N>
    double Vec<N>::r() const
    {
        return _arr[0];
    }

    template <std::size_t N>
    double Vec<N>::g() const
    {
        static_assert(N >= 2, "Vec::g is only available on Vectors of size 2 and more");
        return _arr[1];
    }

    template <std::size_t N>
    double Vec<N>::b() const
    {
        static_assert(N >= 3, "Vec::b is only available on Vectors of size 3 and more");
        return _arr[2];
    }

    template <std::size_t N>
    double Vec<N>::a() const
    {
        static_assert(N >= 4, "Vec::a is only available on Vectors of size 4 and more");
        return _arr[3];
    }

    // uv

    template <std::size_t N>
    double Vec<N>::u() const
    {
        return _arr[0];
    }

    template <std::size_t N>
    double Vec<N>::v() const
    {
        static_assert(N >= 2, "Vec::v is only available on Vectors of size 2 and more");
        return _arr[1];
    }

    #pragma endregion Getters Setters
}

#endif /* !VEC_doublePP_ */
