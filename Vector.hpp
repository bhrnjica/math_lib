#pragma once


#include <cassert>

#include <cstring>

#include "Complex.hpp"

#include "Matrix.hpp"



template< Number Numeric >
class Vector
{
    private:

        int count;

        Numeric * elements;


    public:

        Vector() : count( 0 )
        {
            elements = nullptr;
        }


        Vector( int count ) : Vector( count, new Numeric[ count ] )
        {
        }


        Vector( int count, Numeric * numericArray ) : count( count ), elements( numericArray )
        {
        }


        template< int COUNT >
        Vector( Numeric( & numericArray )[ COUNT ] ) : Vector( COUNT )
        {
            memcpy( elements, & numericArray, count * sizeof( Numeric ) );
        }


        Vector( Vector && other ) : Vector( other.count, other.elements )
        {
        }


        Vector( Vector & other ) : Vector( other.count )
        {
            memcpy( elements, other.elements, count * sizeof( Numeric ) );
        }


        ~Vector()
        {
            delete[] elements;
        }


        int length() const
        {
            return count;
        }


        const Numeric operator[]( int i ) const
        {
            return elements[ i ];
        }


        Numeric operator[]( int i )
        {
            return elements[ i ];
        }


        friend std::ostream & operator <<( std::ostream & os, const Vector & vector )
        {
            for( int i = 0; i < vector.count; i++ )
            {
                os << vector[ i ] << '\t';
            }


            return os;
        }


        template< Number OtherNumeric >
        auto operator +( Vector< OtherNumeric > & other ) const
        {
            assert( count == other.length() );


            using ReturnType = decltype( Numeric() + OtherNumeric() );


            Vector< ReturnType > result( count );

            for( int i = 0; i < count; i++ )
            {
                result[ i ] = elements[ i ] + other[ i ];
            }


            return std::move( result );
        }


        template< Number OtherNumeric >
        auto operator -( Vector< OtherNumeric > & other ) const
        {
            assert( count == other.length() );


            using ReturnType = decltype( Numeric() + OtherNumeric() );


            Vector< ReturnType > result( count );

            for( int i = 0; i < count; i++ )
            {
                result[ i ] = elements[ i ] - other[ i ];
            }


            return std::move( result );
        }


        template< Number OtherNumeric >
        auto operator *( Vector< OtherNumeric > & other ) const
        {
            return inner( other );
        }


        template< Number OtherNumeric >
        friend auto operator *( const OtherNumeric & scalar, const Vector & vector )
        {
            using ReturnType = decltype( Numeric() * OtherNumeric() );


            Vector< ReturnType > result( vector.count );

            for( int i = 0; i < result.length(); i++ )
            {
                result[ i ] = vector.elements[ i ] * scalar;
            }


            return std::move( result );
        }


        template< Number OtherNumeric >
        auto operator *( OtherNumeric & otherNumeric ) const
        {
            using ReturnType = decltype( Numeric() * OtherNumeric() );


            Vector< ReturnType > result( count );


            for( int i = 0; i < count; i++ )
            {
                result[ i ] = elements[ i ] * otherNumeric;
            }


            return std::move( result );
        }


        template< Number OtherNumeric >
        auto inner( const Vector< OtherNumeric > & other ) const
        {
            assert( count == other.length() );


            using ReturnType = decltype( Numeric() * OtherNumeric() );


            ReturnType sum;

            for( int i = 0; i < count; i++ )
            {
                sum = sum + elements[ i ] * other[ i ];
            }


            return std::move( sum );
        }


        template< Number OtherNumeric >
        auto cross( Vector< OtherNumeric > & other ) const
        {
            assert( count == other.length() );


            using ReturnType = decltype( Numeric() * OtherNumeric() );


            Vector< ReturnType > result( count );

            for( int i = 0; i < count; i++ )
            {
                int j = i + 1 > 2 ? 0 : i + 1;

                int k = j + 1 > 2 ? 0 : i + 1;

                result[ i ] = elements[ j ] * other[ k ] - elements[ k ] * other[ j ];
            }


            return std::move( result );
        }


        template< Number OtherNumeric >
        auto outer( Vector< OtherNumeric > & other ) const
        {
            using ReturnType = decltype( Numeric() * OtherNumeric() );


            Matrix< ReturnType > result( count, other.length() );

            for( int i = 0; i < result.getRows(); i++ )
            {
                for( int j = 0; j < result.getColumns(); j++ )
                {
                    result[ i ][ j ] = elements[ i ] * other[ j ];
                }
            }


            return std::move( result );
        }
};
