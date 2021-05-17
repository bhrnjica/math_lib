#pragma once

#include <iostream>

#include <vector>

#include <numeric> 

#include "Complex.hpp"

#include <type_traits>



template< typename Type >
struct is_complex
{
    static constexpr bool value = false;
};


template< typename Numeric >
struct is_complex< Complex< Numeric > >
{
    static constexpr bool value = true;
};

template< typename Type >
struct is_number
{
    static constexpr bool value = is_numeric< Type >::value or is_complex< Type >::value;
};

using namespace std;



template < typename T, typename = std::enable_if_t < is_number < T >::value >>
class Matrix
{

private:
    	T** elements; 
        int cols;
        int rows;

public:
        Matrix(int rowcount = 0, int colcount = 0) : rows(rowcount), cols(colcount)
        {
            T** elements = new T* [rows];

            for(int i = 0; i < rows; ++i)
            {
                elements[i] =  new T [cols];

                for (int j = 0; j < cols; ++j)
                {
                    elements[i][j] =  0;
                }
            }
        }

        Matrix( const Matrix & other ) : rows( other.rows ), cols( other.cols )
        {
            T** elements = new T* [rows];

            for(int i = 0; i < rows; ++i)
            {
                elements[i] =  new T [cols];

                for (int j = 0; j < cols; ++j)
                {
                    elements[i][j] =  other.elements[i][j];
                }
            }  
        }

        Matrix( const Matrix && other ) : rows( std::move(other.rows) ), cols( std::move( other.cols ) ), elements( std::move ( other.elements))
        {
           
        }

        ~Matrix()
        {
           for (int i = 0; i < rows ; ++i )
           {
                delete [] elements[i];
           }

           delete [] elements;
        }

        friend std::ostream & operator << ( std::ostream & os, const Matrix & m )
        {
            os<<"|  ";
            for(int i = 0; i < m.rows; ++i)
            {
                for(int j = 0; j < m.cols; ++j)
                {
                    os << m.elements[i][j] <<"  ";
                }
                os<<"|";
                os<<endl<<"|  ";
            }
            os<<"\b\b\b\b ";

            return os;
        }

};