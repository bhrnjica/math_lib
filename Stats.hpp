#pragma once

#include <cassert>

#include <cstring>

#include <cmath>

#include <algorithm>

#include "Vector.hpp"

class Stats
{
public:
 
    template < typename Numeric, int COUNT, typename = std::enable_if_t < is_numeric < Numeric >:: value>>
    static auto mean (Numeric (&data) [COUNT] )
    {
        auto result = data[0];
        for (int i = 1; i < COUNT; i++)
        {
            result = result + data[i];
        }
           
        return result/COUNT;
    }

    template < typename Numeric, int COUNT, typename = std::enable_if_t < is_numeric < Numeric >:: value>>
    static auto max (Numeric (&data) [COUNT] )
    {
        auto max = data[0];

        for (int i = 1; i < COUNT; i++)
        {
            if ( max < data[i])

                max = data[i];
        }
           
        return max;
    }

    template < typename Numeric, int COUNT, typename = std::enable_if_t < is_numeric < Numeric >:: value>>
    static auto min (Numeric (&data) [COUNT] )
    {
        auto min = data[0];

        for (int i = 1; i < COUNT; i++)
        {
            if ( min > data[i])

                min = data[i];
        }
           
        return min;
    }

    template < typename Numeric, int COUNT, typename = std::enable_if_t < is_numeric < Numeric >:: value>>
    static auto variance (Numeric (&data) [COUNT] )
    {
        auto m = mean(data);

        auto parSum = (data[0] - m);

        for (int i = 1; i < COUNT; i++)
        {
            auto res = (data[i] - m);

            parSum = parSum + res * res;
        }

        return parSum / (COUNT - 1);
    }

    template < typename Numeric, int COUNT, typename = std::enable_if_t < is_numeric < Numeric >:: value>>
    static auto std (Numeric (&data) [COUNT] )
    {
       auto var = variance(data);

       return sqrt(var);
    }

    template < typename Numeric, int COUNT, typename = std::enable_if_t < is_numeric < Numeric >:: value>>
    static auto median (Numeric (&data) [COUNT] )
    {
       auto temp = new Numeric[COUNT];
       
       memcpy( temp, data, COUNT * sizeof( Numeric ) );

       auto index = COUNT / 2; 

       std::sort(temp, temp + COUNT);

       if(COUNT % 2 == 1)
            return temp[ index ];
        else
        {
            auto v1 = temp[ index -1];
            
            auto v2 = temp[ index +1];

            delete [] temp;

            return (v1 + v2) / 2;

        }
    }
};
