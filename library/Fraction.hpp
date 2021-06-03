#pragma once



#include <iostream>

#include <concepts>



template< std::integral Integer >
class Fraction
{
    private:

        Integer numerator;

        Integer denominator;



        static Integer gcdUnsigned( Integer m, Integer n )
        {
            auto r = m % n;

            return r ? gcdUnsigned( n, r ) : n;
        }


        static Integer gcd( Integer m, Integer n )
        {
            return m < 0 ? gcdUnsigned( - m, n ) : gcdUnsigned( m, n );
        }


        void reduce()
        {
            auto g = gcd( numerator, denominator );

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


        template< std::integral OtherInteger >
        Fraction( const Fraction< OtherInteger > & other ) : numerator( other.getNumerator() ), denominator( other.getDenominator() )
        {
        }


        Fraction( Integer numerator = 0, Integer denominator = 1 ) :
            numerator( denominator < 0 ? - numerator : numerator ), denominator( denominator < 0 ? - denominator : denominator )
        {
            if( denominator == 0 )
            {
                throw std::runtime_error( std::string( "Divide by zero" ) );
            }

            reduce();
        }


        friend std::ostream & operator <<( std::ostream & output, const Fraction & fraction )
        {
            output << fraction.numerator;

            if( fraction.numerator )
            {
                output << "/" << fraction.denominator;
            }

            return output;
        }


        operator double() const
        {
            return static_cast< double >( numerator ) / denominator;
        }


        template< std::integral OtherInteger >
        auto operator ==( const Fraction< OtherInteger > & other ) const
        {
            return numerator == other.getNumerator() and denominator == other.getDenominator();
        }


        template< std::integral OtherInteger >
        auto operator ==( const OtherInteger & integer ) const
        {
            return * this == Fraction< OtherInteger >( integer );
        }


        template< std::integral OtherInteger >
        auto operator not_eq( const Fraction< OtherInteger > & other ) const
        {
            return not ( * this == other );
        }


        template< std::integral OtherInteger >
        auto operator not_eq( const OtherInteger & integer ) const
        {
            return not ( * this == integer );
        }


        template< std::integral OtherInteger >
        auto operator >( const Fraction< OtherInteger > & other ) const
        {
            return numerator * other.getDenominator() > denominator * other.getNumerator();
        }


        template< std::integral OtherInteger >
        auto operator <( const Fraction< OtherInteger > & other ) const
        {
            return numerator * other.getDenominator() < denominator * other.getNumerator();
        }


        template< std::integral OtherInteger >
        auto operator >=( const Fraction< OtherInteger > & other ) const
        {
            return * this == other or * this > other;
        }


        template< std::integral OtherInteger >
        auto operator <=( const Fraction< OtherInteger > & other ) const
        {
            return * this == other or * this < other;
        }


        auto operator -() const
        {
            return Fraction( -numerator, denominator );
        }


        template< std::integral OtherInteger >
        auto operator +( const Fraction< OtherInteger > & other ) const
        {
            auto n = numerator * other.getDenominator() + denominator * other.getNumerator();

            auto d = denominator * other.getDenominator();

            return Fraction< decltype( n ) >( n, d );
        }


        template< std::integral OtherInteger >
        auto operator +( const OtherInteger & integer ) const
        {
            return * this + Fraction< OtherInteger >( integer );
        }


        template< std::integral OtherInteger >
        friend auto operator +( const OtherInteger & integer, const Fraction & fraction )
        {
            return fraction + integer;
        }


        template< std::integral OtherInteger >
        auto operator -( const Fraction< OtherInteger > & other ) const
        {
            auto n = numerator * other.getDenominator() - denominator * other.getNumerator();

            auto d = denominator * other.getDenominator();

            return Fraction< decltype( n ) >( n, d );
        }


        template< std::integral OtherInteger >
        auto operator -( const OtherInteger & integer ) const
        {
            return * this - Fraction< OtherInteger >( integer );
        }


        template< std::integral OtherInteger >
        friend auto operator -( const OtherInteger & integer, const Fraction & fraction )
        {
            return Fraction< OtherInteger >( integer ) - fraction;
        }


        template< std::integral OtherInteger >
        auto operator *( const Fraction< OtherInteger > & other ) const
        {
            auto n = numerator * other.getNumerator();

            auto d = denominator * other.getDenominator();

            return Fraction< decltype( n ) >( n, d );
        }


        template< std::integral OtherInteger >
        auto operator *( OtherInteger const & integer ) const
        {
            return * this * Fraction< OtherInteger >( integer );
        }


        template< std::integral OtherInteger >
        friend auto operator *( OtherInteger const & integer, const Fraction & fraction )
        {
            return fraction * integer;
        }


        template< std::integral OtherInteger >
        auto operator /( const Fraction< OtherInteger > & other ) const
        {
            auto n = numerator * other.getDenominator();

            auto d = denominator * other.getNumerator();

            return Fraction< decltype( n ) >( n, d );
        }


        template< std::integral OtherInteger >
        auto operator /( OtherInteger const & integer ) const
        {
            return * this / Fraction< OtherInteger >( integer );
        }


        template< std::integral OtherInteger >
        friend auto operator /( OtherInteger const & integer, const Fraction & fraction )
        {
            return Fraction< OtherInteger >( integer ) / fraction;
        }
};



template< typename T >
concept RationalNumber = requires( T x )
{
    { Fraction{ x } } -> std::same_as< T >;
};


template< typename Type >
concept RealNumber = std::integral< Type > or std::floating_point< Type > or RationalNumber< Type >;
