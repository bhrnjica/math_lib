#pragma once



#include <iostream>

#include <type_traits>



template< typename Integer, typename = std::enable_if_t< std::is_integral< Integer >::value > >
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


        template< typename OtherInteger >
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



        friend std::ostream & operator<<( std::ostream & output, const Fraction & fraction )
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



        template< typename OtherInteger, typename = std::enable_if_t< std::is_integral< OtherInteger >::value > >
        auto operator==( const Fraction< OtherInteger > & other ) const
        {
            return numerator == other.getNumerator() and denominator == other.getDenominator();
        }



        template< typename OtherInteger, typename = std::enable_if_t< std::is_integral< OtherInteger >::value > >
        auto operator==( const OtherInteger & integer ) const
        {
            return * this == Fraction< OtherInteger >( integer );
        }



        template< typename OtherInteger, typename = std::enable_if_t< std::is_integral< OtherInteger >::value > >
        auto operator not_eq( const Fraction< OtherInteger > & other ) const
        {
            return not ( * this == other );
        }



        template< typename OtherInteger, typename = std::enable_if_t< std::is_integral< OtherInteger >::value > >
        auto operator not_eq( const OtherInteger & integer ) const
        {
            return not ( * this == integer );
        }


        template< typename OtherInteger, typename = std::enable_if_t< std::is_integral< OtherInteger >::value > >
        auto operator >= ( const Fraction< OtherInteger > & other ) const
        {
            if( *this == other )

                return true;
            else
                return (* this > other);
        }


        template< typename OtherInteger, typename = std::enable_if_t< std::is_integral< OtherInteger >::value > >
        auto operator > ( const Fraction< OtherInteger > & other ) const
        {
            auto num1 = numerator;
            auto num2 = other.getNumerator();
            auto den1 =  denominator;
            auto den2 =  other.getDenominator();

            if(num1 == num2)
            {
                return den1 < den2;
            }
            else if(den1 == den2)
            {
                return num1 > num2;
            }
            else
            {
                return (num1 * den2) > (num2 * den1);
            }

        }


        template< typename OtherInteger, typename = std::enable_if_t< std::is_integral< OtherInteger >::value > >
        auto operator < ( const Fraction< OtherInteger > & other ) const
        {
            return not (* this > other);
        }


        template< typename OtherInteger, typename = std::enable_if_t< std::is_integral< OtherInteger >::value > >
        auto operator <= ( const Fraction< OtherInteger > & other ) const
        {
            if( *this == other )

                return true;
            else
                return not (* this > other);
        }


        auto operator-() const
        {
            return Fraction( -numerator, denominator );
        }



        template< typename OtherInteger >
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



        template< typename OtherInteger >
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



        template< typename OtherInteger >
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



        template< typename OtherInteger >
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
