#pragma once



#include <cmath>

#include <algorithm>


#include "Vector.hpp"



class Stats
{
    public:

        template< Number Numeric, int COUNT >
        static auto mean( Numeric( & data )[ COUNT ] )
        {
            auto result = data[ 0 ];

            for( int i = 1; i < COUNT; i++ )
            {
                result = result + data[ i ];
            }

            return result / COUNT;
        }


        template< Number Numeric, int COUNT >
        static auto max( Numeric( & data ) [ COUNT ] )
        {
            auto max = data[ 0 ];

            for( int i = 1; i < COUNT; i++ )
            {
                if( max < data[ i ] )
                {
                    max = data[ i ];
                }
            }

            return max;
        }


        template< Number Numeric, int COUNT >
        static auto min( Numeric( & data ) [ COUNT ] )
        {
            auto min = data[ 0 ];

            for( int i = 1; i < COUNT; i++ )
            {
                if( min > data[ i ] )
                {
                    min = data[ i ];
                }
            }

            return min;
        }


        template< Number Numeric, int COUNT >
        static auto variance( Numeric( & data ) [ COUNT ] )
        {
            auto m = mean( data );

            auto sum = data[ 0 ] - m;


            for( int i = 1; i < COUNT; i++ )
            {
                auto res = data[ i ] - m;

                sum = sum + res * res;
            }


            return sum / ( COUNT - 1 );
        }


        template< Number Numeric, int COUNT >
        static auto std( Numeric( & data ) [ COUNT ] )
        {
            auto var = variance( data );

            return sqrt( var );
        }


        template< Number Numeric, int COUNT >
        static auto median( Numeric( & data ) [ COUNT ] )
        {
            auto temp = new Numeric[ COUNT ];

            memcpy( temp, data, COUNT * sizeof( Numeric ) );


            auto middle = COUNT / 2;


            std::nth_element( temp, temp + middle, temp + COUNT );


            if( COUNT % 2 )
            {
                return temp[ middle ];
            }
            else
            {
                auto v1 = temp[ middle ];


                auto next = middle + 1;

                std::nth_element( temp, temp + next, temp + COUNT );

                auto v2 = temp[ next ];


                delete [] temp;


                return ( v1 + v2 ) / 2;
            }
        }
};
