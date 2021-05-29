#pragma once

#include <cassert>

#include <cstring>

#include "Complex.hpp"

#include "Matrix.hpp"

template <typename Numeric, typename = std::enable_if_t<is_numeric<Numeric>::value>>
class Vector
{
private:
    int count;

    Numeric *elements;

public:
    Vector() : count(0)
    {
        elements = nullptr;
    }

    Vector(int eCount) : Vector(eCount, new Numeric[eCount])
    {
    }

    Vector(int eCount, Numeric *numericArray) : count(eCount), elements(numericArray)
    {
    }

    template <int COUNT>
    Vector(Numeric (&numericArray)[COUNT]) : Vector(COUNT)
    {
        memcpy(elements, &numericArray, count * sizeof(Numeric));
    }

    Vector(Vector &&other) : Vector(other.count, other.elements)
    {
    }

    Vector(Vector &other) : Vector(other.count)
    {
        memcpy(elements, other.elements, count * sizeof(Numeric));
    }

    ~Vector()
    {
        delete[] elements;
    }

    int length() const
    {
        return count;
    }

    const Numeric operator[](int i) const
    {
        return elements[i];
    }

    Numeric operator[](int i)
    {
        return elements[i];
    }

    friend std::ostream &operator<<(std::ostream &os, const Vector &vector)
    {
        for (int i = 0; i < vector.count; i++)
        {
            os << vector[i] << '\t';
        }

        os << std::endl;

        return os;
    }

    template <typename OtherNumeric>
    auto operator+(Vector<OtherNumeric> &other)
    {
        assert(count == other.length());

        using ReturnType = decltype(Numeric() + OtherNumeric());

        Vector<ReturnType> result(count);

        Vector &me = *this;

        for (int i = 0; i < count; i++)
        {
            result[i] = me[i] + other[i];
        }

        return std::move(result);
    }

    template <typename OtherNumeric>
    auto operator-(Vector<OtherNumeric> &other)
    {
        assert(count == other.length());

        using ReturnType = decltype(Numeric() + OtherNumeric());

        Vector<ReturnType> result(count);

        Vector &me = *this;

        for (int i = 0; i < count; i++)
        {
            result[i] = me[i] - other[i];
        }

        return std::move(result);
    }

    template <typename OtherNumeric>
    auto operator * (Vector<OtherNumeric> &other)
    {
        Vector &me = *this;

        return me.Inner(other);
    }

    template <typename OtherNumeric>
    friend auto operator * (const OtherNumeric & scalar, const Vector &vector)
    {
         using ReturnType = decltype( Numeric() * OtherNumeric() );
         Vector<ReturnType> result(vector.count);

        for(int i=0; i< result.length(); i++)
        {
            result[i] = vector.elements[i] * scalar;
        }

        return std::move( result );
    }


    template <typename OtherNumeric>
    auto operator * (OtherNumeric &otherNumeric)
    {
        Vector &me = *this;

        for (int i = 0; i < count; i++)
        {
            elements[i] = elements[i] * otherNumeric;
        }
        return me;
    }

    template <typename OtherNumeric>
    auto Inner(const Vector<OtherNumeric> &other)
    {
        assert(count == other.length());

        using ReturnType = decltype(Numeric() * OtherNumeric());

        ReturnType sum;

        Vector &me = (*this);

        for (int i = 0; i < count; i++)
        {
            auto p = me.elements[i] * other[i];
            sum = sum + p;
        }

        return std::move(sum);
    }

    template <typename OtherNumeric>
    auto Cross(Vector<OtherNumeric> &other)
    {
        assert(count == 3);
        assert(count == other.length());

        using ReturnType = decltype(Numeric() * OtherNumeric());

        Vector<ReturnType> result(count);

        Vector &me = *this;

        for (int l = 0; l < count; l++)
        {
            int i = l;

            int j = i + 1 > 2 ? 0 : i + 1;

            int k = j + 1 > 2 ? 0 : i + 1;

            result[i] = me[j] * other[k] - me[k] * other[j];
        }

        return std::move(result);
    }

    template <typename OtherNumeric>
    auto Outter(Vector<OtherNumeric> &other)
    {

        using ReturnType = decltype(Numeric() * OtherNumeric());

        Vector &me = *this;

        Matrix<ReturnType> result(me.length, other.length);

        for (int i = 0; i < result.getRows(); i++)
        {
            for (int j = 0; j < result.getColumns(); j++)
            {
                result[i][j] = me[i] * other[j];
            }
        }

        return std::move(result);
    }
};
