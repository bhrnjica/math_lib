#pragma once

#include <iostream>

#include "Fraction.hpp"

#include <type_traits>

template< typename Type >
struct is_fraction
{
    static constexpr bool value = false;
};


template< typename Integer >
struct is_fraction< Fraction< Integer > >
{
    static constexpr bool value = true;
};

template< typename Type >
struct is_numeric
{
    static constexpr bool value = std::is_arithmetic< Type >::value or is_fraction< Type >::value;
};

using namespace std;


template < typename T, typename = std::enable_if_t<is_numeric< T >::value >>

class Complex
{
    T real;
    T img;

public:

    Complex( T r = 0, T i = 0 ) : real ( r), img ( i )
    {

    }

    Complex( const Complex & other ) : real( other.real ), img( other.img )
    {

    }

    friend std::ostream &operator<<( std::ostream &os, const Complex &c )
    {
        if(c.GetReal() == 0)
        {
            if(c.GetImaginary() == 0)
            {
                os << "0";
            }
            else
            {
                os << c.img << "i";
            }

        }
        else if (c.GetImaginary() == 0)
        {
            if(c.GetReal() == 0)
            {
                os << "0";
            }
            else
            {
                os << c.GetReal();
            }
        }
        else
            os << "(" << c.real << "+" << c.img << "i )";
        return os;
    }

public:

    const T& GetReal( ) const
    {
        return real;
    }

    const T& GetImaginary( ) const
    {
        return img;
    }

public:
        template < typename Numeric, typename = std::enable_if_t<is_numeric< Numeric >::value >>

        auto operator + ( const Complex < Numeric > & other ) const
        {
            auto realpart = real + other.GetReal();

            auto imgpart = img + other.GetImaginary();

            return Complex < decltype ( realpart ) > ( realpart , imgpart );

        }


        template < typename Numeric, typename = std::enable_if_t<is_numeric< Numeric >::value >>

        auto operator + ( const Numeric & number ) const
        {
            auto realpart = real + number;

            return Complex < decltype ( realpart ) > ( realpart , img );
        }


        template < typename Numeric, typename = std::enable_if_t<is_numeric< Numeric >::value >>

        friend auto operator + ( const Numeric & number, const Complex & complex )
        {
            return complex + number;
        }

public:

        template < typename Numeric, typename = std::enable_if_t<is_numeric< Numeric >::value >>

        auto operator - ( const Complex < Numeric > & other ) const
        {
            auto realpart = real - other.GetReal();

            auto imgpart = img - other.GetImaginary();

            return Complex < decltype ( realpart ) > ( realpart , imgpart );

        }


        template < typename Numeric, typename = std::enable_if_t<is_numeric< Numeric >::value >>

        auto operator - ( const Numeric & number ) const
        {
            auto realpart = real - number;

            return Complex < decltype ( realpart ) > ( realpart , img );
        }


        template < typename Numeric, typename = std::enable_if_t<is_numeric< Numeric >::value >>

        friend auto operator - ( const Numeric & number, const Complex & complex )
        {
            return complex - number;
        }

public:

        template < typename Numeric, typename = std::enable_if_t<is_numeric< Numeric >::value >>

        auto operator * ( const Complex < Numeric > & other ) const
        {
            auto realpart = real * other.GetReal() - img * other.GetImaginary();

            auto imgpart = real * other.GetImaginary() + img * other.GetReal();

            return Complex < decltype ( realpart ) > ( realpart , imgpart );

        }


        template < typename Numeric, typename = std::enable_if_t<is_numeric< Numeric >::value >>

        auto operator * ( const Numeric & number ) const
        {
            auto realpart = real * number;

            auto imgpart = img * number;

            return Complex < decltype ( realpart ) > ( realpart , imgpart );
        }


        template < typename Numeric, typename = std::enable_if_t<is_numeric< Numeric >::value >>

        friend auto operator * ( const Numeric & number, const Complex & complex )
        {
            return complex * number;
        }

public:

        template < typename Numeric, typename = std::enable_if_t<is_numeric< Numeric >::value >>

        auto operator / ( const Complex < Numeric > & other ) const
        {
            auto denominator = other.GetReal() * other.GetReal() + other.GetImaginary() * other.GetImaginary();

            auto realpart = ( real * other.GetReal() + img * other.GetImaginary() ) / denominator;

            auto imgpart = ( img * other.GetReal() - real * other.GetImaginary() ) / denominator;

            return Complex < decltype ( realpart ) > ( realpart , imgpart );

        }


        template < typename Numeric, typename = std::enable_if_t<is_numeric< Numeric >::value >>

        auto operator / ( const Numeric & number ) const
        {
            auto realpart = real / number;

            auto imgpart = img / number;

            return Complex < decltype ( realpart ) > ( realpart , imgpart );
        }


        template < typename Numeric, typename = std::enable_if_t<is_numeric< Numeric >::value >>

        friend auto operator / ( const Numeric & number, const Complex & complex )
        {
            auto realpart = number / complex.GetReal();

            auto imgpart = number / complex.GetImaginary();

            return Complex < decltype ( realpart ) > ( realpart , imgpart );
        }


};



