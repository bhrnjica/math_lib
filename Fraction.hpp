#pragma once

#include <iostream>

#include <numeric> 

#include <type_traits>



using namespace std;



template< typename Integer, typename = std::enable_if_t< std::is_integral< Integer >::value > >
class Fraction
{
    private:

        Integer numerator;

        Integer denominator;


        void reduce()
        {
            auto g = std::gcd( numerator, denominator );

            numerator /= g;

            denominator /= g;
        }



    public:

        const Integer & getNumerator() const
        {
            return numerator;
        }


        const Integer & getDenominator() const
        {
            return denominator;
        }



        Fraction( const Fraction & other ) : numerator( other.numerator ), denominator( other.denominator )
        {
        }


        Fraction( Integer numerator = 0, Integer denominator = 1 ) : numerator( numerator ), denominator( denominator )
        {
            if( denominator == 0 )
            {
                throw runtime_error( std::string( "Divide by zero" ) );
            }

            if( denominator < 0 )
            {
                numerator = - numerator;

                denominator = - denominator;
            }

            reduce();
        }



        friend std::ostream & operator<<( std::ostream & os, const Fraction & f )
        {
            if ( f.getNumerator() == 0)
                os << 0;
            else
                os << f.numerator << "/" << f.denominator;

            return os;
        }



        operator double() const
        {
            return static_cast< double >( numerator ) / denominator;
        }



        auto operator-() const
        {
            return Fraction( -numerator, denominator );
        }



        template< typename OtherInteger, typename = std::enable_if_t< std::is_integral< OtherInteger >::value > >
        auto operator+( const Fraction< OtherInteger > & other ) const
        {
            auto n = numerator * other.getDenominator() + denominator * other.getNumerator();

            auto d = denominator * other.getDenominator();

            return Fraction< decltype( n ) >( n, d );
        }


        template< typename OtherInteger, typename = std::enable_if_t< std::is_integral< OtherInteger >::value > >
        auto operator+( const OtherInteger & integer ) const
        {
            return * this + Fraction< OtherInteger >( integer );
        }


        template< typename OtherInteger, typename = std::enable_if_t< std::is_integral< OtherInteger >::value > >
        friend auto operator+( const OtherInteger & integer, const Fraction & fraction )
        {
            return fraction + integer;
        }



        template< typename OtherInteger, typename = std::enable_if_t< std::is_integral< OtherInteger >::value > >
        auto operator-( const Fraction< OtherInteger > & other ) const
        {
            auto n = numerator * other.getDenominator() - denominator * other.getNumerator();

            auto d = denominator * other.getDenominator();

            return Fraction< decltype( n ) >( n, d );
        }


        template< typename OtherInteger, typename = std::enable_if_t< std::is_integral< OtherInteger >::value > >
        auto operator-( const OtherInteger & integer ) const
        {
            return * this - Fraction< OtherInteger >( integer );
        }


        template< typename OtherInteger, typename = std::enable_if_t< std::is_integral< OtherInteger >::value > >
        friend auto operator-( const OtherInteger & integer, const Fraction & fraction )
        {
            return Fraction< OtherInteger >( integer ) - fraction;
        }



        template< typename OtherInteger, typename = std::enable_if_t< std::is_integral< OtherInteger >::value > >
        auto operator*( const Fraction< OtherInteger > & other ) const
        {
            auto n = numerator * other.getNumerator();

            auto d = denominator * other.getDenominator();

            return Fraction< decltype( n ) >( n, d );
        }


        template< typename OtherInteger, typename = std::enable_if_t< std::is_integral< OtherInteger >::value > >
        auto operator*( OtherInteger const & integer ) const
        {
            return * this * Fraction< OtherInteger >( integer );
        }


        template< typename OtherInteger, typename = std::enable_if_t< std::is_integral< OtherInteger >::value > >
        friend auto operator*( OtherInteger const & integer, const Fraction & fraction )
        {
            return fraction * integer;
        }



        template< typename OtherInteger, typename = std::enable_if_t< std::is_integral< OtherInteger >::value > >
        auto operator/( const Fraction< OtherInteger > & other ) const
        {
            auto n = numerator * other.getDenominator();

            auto d = denominator * other.getNumerator();

            return Fraction< decltype( n ) >( n, d );
        }


        template< typename OtherInteger, typename = std::enable_if_t< std::is_integral< OtherInteger >::value > >
        auto operator/( OtherInteger const & integer ) const
        {
            return * this / Fraction< OtherInteger >( integer );
        }


        template< typename OtherInteger, typename = std::enable_if_t< std::is_integral< OtherInteger >::value > >
        friend auto operator/( OtherInteger const & integer, const Fraction & fraction )
        {
            return Fraction< OtherInteger >( integer ) / fraction;
        }
};
