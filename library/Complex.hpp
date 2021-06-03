#pragma once



#include "Fraction.hpp"



template< RealNumber Real >
class Complex
{
    private:

        Real real;

        Real imaginary;


    public:

        const Real & getReal() const
        {
            return real;
        }


        const Real & getImaginary() const
        {
            return imaginary;
        }


        Complex( const Complex & other ) : real( other.real ), imaginary( other.imaginary )
        {
        }


        Complex( Real real = Real{}, Real imaginary = Real{} ) : real( real ), imaginary( imaginary )
        {
        }


        friend std::ostream & operator <<( std::ostream & os, const Complex & complex )
        {
            auto & real = complex.getReal();

            auto & imaginary = complex.getImaginary();

            bool realNonZero = real not_eq 0;

            bool imaginaryNonZero = imaginary not_eq 0;


            if( realNonZero )
            {
                os << real;

                if( imaginaryNonZero )
                {
                    if( imaginary < 0 )
                    {
                        os << " - ";

                        if( imaginary not_eq 1 )
                        {
                            os << - imaginary << " * ";
                        }

                        os << "i";
                    }
                    else
                    {
                        os << " + ";

                        if( imaginary not_eq 1 )
                        {
                            os << imaginary << " * ";
                        }

                        os << "i";
                    }
                }
            }
            else
            {
                os << imaginary;

                if( imaginaryNonZero )
                {
                    if( imaginary not_eq 1 )
                    {
                        os << imaginary << " * ";
                    }

                    os << "i";
                }
            }


            return os;
        }



        auto operator -() const
        {
            return Complex( -real, -imaginary );
        }


        template< RealNumber OtherReal >
        auto operator +( const Complex< OtherReal > & other ) const
        {
            auto realResult = real + other.getReal();

            auto imaginaryResult = imaginary + other.getImaginary();

            return Complex< decltype( realResult ) >( realResult, imaginaryResult );
        }


        template< RealNumber OtherReal >
        auto operator +( const OtherReal & numeric ) const
        {
            return * this + Complex< OtherReal >( numeric );
        }


        template< RealNumber OtherReal >
        friend auto operator +( const OtherReal & numeric, const Complex & complex )
        {
            return complex + numeric;
        }


        template< RealNumber OtherReal >
        auto operator -( const Complex< OtherReal > & other ) const
        {
            auto realResult = real - other.getReal();

            auto imaginaryResult = imaginary - other.getImaginary();

            return Complex< decltype( realResult ) >( realResult, imaginaryResult );
        }


        template< RealNumber OtherReal >
        auto operator -( const OtherReal & numeric ) const
        {
            return * this - Complex< OtherReal >( numeric );
        }


        template< RealNumber OtherReal >
        friend auto operator -( const OtherReal & numeric, const Complex & complex )
        {
            return Complex< OtherReal >( numeric ) - complex;
        }


        template< RealNumber OtherReal >
        auto operator *( const Complex< OtherReal > & other ) const
        {
            auto realResult = real * other.getReal() - imaginary * other.getImaginary();

            auto imaginaryResult = real * other.getImaginary() + imaginary * other.getReal();

            return Complex< decltype( realResult ) >( realResult, imaginaryResult );
        }


        template< RealNumber OtherReal >
        auto operator *( OtherReal const & numeric ) const
        {
            return * this * Complex< OtherReal >( numeric );
        }


        template< RealNumber OtherReal >
        friend auto operator *( OtherReal const & numeric, const Complex & complex )
        {
            return complex * numeric;
        }


        template< RealNumber OtherReal >
        auto operator /( const Complex< OtherReal > & other ) const
        {
            auto realNumerator = real * other.getReal() + imaginary * other.getImaginary();

            auto imaginaryNumerator = imaginary * other.getReal() - real * other.getImaginary();

            auto denominator = other.getReal() * other.getReal() + other.getImaginary() * other.getImaginary();


            using NumeratorType = decltype( realNumerator );

            if constexpr( std::is_integral_v< NumeratorType > )
            {
                using ReturnType = Fraction< NumeratorType >;

                return Complex( ReturnType( realNumerator, denominator ), ReturnType( imaginaryNumerator, denominator ) );
            }
            else
            {
                return Complex< NumeratorType >( realNumerator / denominator, imaginaryNumerator / denominator );
            }
        }


        template< RealNumber OtherReal >
        auto operator /( OtherReal const & numeric ) const
        {
            return * this / Complex< OtherReal >( numeric );
        }


        template< RealNumber OtherReal >
        friend auto operator /( OtherReal const & numeric, const Complex & complex )
        {
            return Complex< OtherReal >( numeric ) / complex;
        }


        template< RealNumber OtherReal >
        auto operator ==( const Complex< OtherReal > & other ) const
        {
            return real == other.getReal() and imaginary == other.getImaginary();
        }


        template< RealNumber OtherReal >
        auto operator ==( const OtherReal & integer ) const
        {
            return * this == Complex< OtherReal >( integer );
        }


        template< RealNumber OtherReal >
        auto operator not_eq( const Complex< OtherReal > & other ) const
        {
            return not ( * this == other );
        }


        template< RealNumber OtherReal >
        auto operator not_eq( const OtherReal & integer ) const
        {
            return not ( * this == integer );
        }


        template< RealNumber OtherReal >
        auto operator >=( const Complex< OtherReal > & other ) const
        {
            return real >= other.getReal();
        }


        template< RealNumber OtherReal >
        auto operator >( const Complex< OtherReal > & other ) const
        {
           return real > other.getReal();

        }


        template< RealNumber OtherReal >
        auto operator <( const Complex< OtherReal > & other ) const
        {
            return real < other.getReal();
        }


        template< RealNumber OtherReal >
        auto operator <=( const Complex< OtherReal > & other ) const
        {
            return real <= other.getReal();
        }
};



template< typename T >
concept ComplexNumber = requires( T x )
{
    { Complex{ x } } -> std::same_as< T >;
};


template< typename Type >
concept Number = RealNumber< Type > or ComplexNumber< Type >;

