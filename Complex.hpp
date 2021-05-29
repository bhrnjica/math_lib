#pragma once



#include "Fraction.hpp"



template< typename Type >
struct is_real
{
    static constexpr bool value = std::is_arithmetic< Type >::value or is_fraction< Type >::value;
};



template< typename ParameterType >
struct DivisionType
{
    using Type = ParameterType;
};


template<>
struct DivisionType< uint8_t >
{
    using Type = Fraction< uint8_t >;
};

template<>
struct DivisionType< uint16_t >
{
    using Type = Fraction< uint16_t >;
};

template<>
struct DivisionType< uint32_t >
{
    using Type = Fraction< uint32_t >;
};

template<>
struct DivisionType< uint64_t >
{
    using Type = Fraction< uint64_t >;
};

template<>
struct DivisionType< int8_t >
{
    using Type = Fraction< int8_t >;
};

template<>
struct DivisionType< int16_t >
{
    using Type = Fraction< int16_t >;
};

template<>
struct DivisionType< int32_t >
{
    using Type = Fraction< int32_t >;
};

template<>
struct DivisionType< int64_t >
{
    using Type = Fraction< int64_t >;
};




template< typename Numeric, typename = std::enable_if_t< is_real< Numeric >::value > >
class Complex
{
    private:

        Numeric real;

        Numeric imaginary;


    public:

        const Numeric & getReal() const
        {
            return real;
        }


        const Numeric & getImaginary() const
        {
            return imaginary;
        }



        Complex( const Complex & other ) : real( other.real ), imaginary( other.imaginary )
        {
        }


        Complex( Numeric real = Numeric{}, Numeric imaginary = Numeric{} ) : real( real ), imaginary( imaginary )
        {
        }



        friend std::ostream & operator<<( std::ostream & os, const Complex & complex )
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



        auto operator-() const
        {
            return Complex( -real, -imaginary );
        }



        template< typename OtherNumeric >
        auto operator+( const Complex< OtherNumeric > & other ) const
        {
            auto realResult = real + other.getReal();

            auto imaginaryResult = imaginary + other.getImaginary();

            return Complex< decltype( realResult ) >( realResult, imaginaryResult );
        }


        template< typename OtherNumeric, typename = std::enable_if_t< is_real< OtherNumeric >::value > >
        auto operator+( const OtherNumeric & numeric ) const
        {
            return * this + Complex< OtherNumeric >( numeric );
        }


        template< typename OtherNumeric, typename = std::enable_if_t< is_real< OtherNumeric >::value > >
        friend auto operator+( const OtherNumeric & numeric, const Complex & complex )
        {
            return complex + numeric;
        }


        template< typename OtherNumeric >
        auto operator-( const Complex< OtherNumeric > & other ) const
        {
            auto realResult = real - other.getReal();

            auto imaginaryResult = imaginary - other.getImaginary();

            return Complex< decltype( realResult ) >( realResult, imaginaryResult );
        }


        template< typename OtherNumeric, typename = std::enable_if_t< is_real< OtherNumeric >::value > >
        auto operator-( const OtherNumeric & numeric ) const
        {
            return * this - Complex< OtherNumeric >( numeric );
        }


        template< typename OtherNumeric, typename = std::enable_if_t< is_real< OtherNumeric >::value > >
        friend auto operator-( const OtherNumeric & numeric, const Complex & complex )
        {
            return Complex< OtherNumeric >( numeric ) - complex;
        }



        template< typename OtherNumeric >
        auto operator*( const Complex< OtherNumeric > & other ) const
        {
            auto realResult = real * other.getReal() - imaginary * other.getImaginary();

            auto imaginaryResult = real * other.getImaginary() + imaginary * other.getReal();

            return Complex< decltype( realResult ) >( realResult, imaginaryResult );
        }


        template< typename OtherNumeric, typename = std::enable_if_t< is_real< OtherNumeric >::value > >
        auto operator*( OtherNumeric const & numeric ) const
        {
            return * this * Complex< OtherNumeric >( numeric );
        }


        template< typename OtherNumeric, typename = std::enable_if_t< is_real< OtherNumeric >::value > >
        friend auto operator*( OtherNumeric const & numeric, const Complex & complex )
        {
            return complex * numeric;
        }



        template< typename OtherNumeric >
        auto operator/( const Complex< OtherNumeric > & other ) const
        {
            auto realNumerator = real * other.getReal() + imaginary * other.getImaginary();

            auto imaginaryNumerator = imaginary * other.getReal() - real * other.getImaginary();

            auto denominator = other.getReal() * other.getReal() + other.getImaginary() * other.getImaginary();


            using Type = typename DivisionType< decltype( realNumerator ) >::Type;


            auto realResult = ( Type ) realNumerator / ( Type ) denominator;

            auto imaginaryResult = ( Type ) imaginaryNumerator / ( Type ) denominator;


            return Complex< decltype( realResult ) >( realResult, imaginaryResult );
        }


        template< typename OtherNumeric, typename = std::enable_if_t< is_real< OtherNumeric >::value > >
        auto operator/( OtherNumeric const & numeric ) const
        {
            return * this / Complex< OtherNumeric >( numeric );
        }


        template< typename OtherNumeric, typename = std::enable_if_t< is_real< OtherNumeric >::value > >
        friend auto operator/( OtherNumeric const & numeric, const Complex & complex )
        {
            return Complex< OtherNumeric >( numeric ) / complex;
        }


        template< typename OtherNumeric, typename = std::enable_if_t< std::is_integral< OtherNumeric >::value > >
        auto operator==( const Complex< OtherNumeric > & other ) const
        {
            return real == other.getReal() and imaginary == other.getImaginary();
        }



        template< typename OtherNumeric, typename = std::enable_if_t< std::is_integral< OtherNumeric >::value > >
        auto operator==( const OtherNumeric & integer ) const
        {
            return * this == Complex< OtherNumeric >( integer );
        }



        template< typename OtherNumeric, typename = std::enable_if_t< std::is_integral< OtherNumeric >::value > >
        auto operator not_eq( const Complex< OtherNumeric > & other ) const
        {
            return not ( * this == other );
        }



        template< typename OtherNumeric, typename = std::enable_if_t< std::is_integral< OtherNumeric >::value > >
        auto operator not_eq( const OtherNumeric & integer ) const
        {
            return not ( * this == integer );
        }


        template< typename OtherNumeric, typename = std::enable_if_t< std::is_integral< OtherNumeric >::value > >
        auto operator >= ( const Complex< OtherNumeric > & other ) const
        {
            return (real >= other.getReal());
        }


        template< typename OtherNumeric, typename = std::enable_if_t< std::is_integral< OtherNumeric >::value > >
        auto operator > ( const Complex< OtherNumeric > & other ) const
        {
           return (real > other.getReal());
            
        }


        template< typename OtherNumeric, typename = std::enable_if_t< std::is_integral< OtherNumeric >::value > >
        auto operator < ( const Complex< OtherNumeric > & other ) const
        {
            return (real < other.getReal());
        }


        template< typename OtherNumeric, typename = std::enable_if_t< std::is_integral< OtherNumeric >::value > >
        auto operator <= ( const Complex< OtherNumeric > & other ) const
        {
            return (real <= other.getReal());
        }

};



template< typename Type >
struct is_complex
{
    static constexpr bool value = false;
};


template< typename Type >
struct is_complex< Complex< Type > >
{
    static constexpr bool value = true;
};
