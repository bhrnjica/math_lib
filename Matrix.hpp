#pragma once



#include <cassert>

#include <cstring>

template< typename Type >
struct is_numeric
{
    static constexpr bool value = is_real< Type >::value or is_complex< Type >::value;
};

template< typename Numeric, typename = std::enable_if_t< is_numeric< Numeric >::value > >
class Matrix
{
    private:

        int rows;

        int columns;


        Numeric * elements;


    public:

        int getRows() const
        {
            return rows;
        }


        int getColumns() const
        {
            return columns;
        }


        const Numeric * operator[]( int i ) const
        {
            return & elements[ i * columns ];

        }


        Numeric * operator[]( int i )
        {
            return & elements[ i * columns ];

        }


        friend std::ostream & operator<<( std::ostream & os, const Matrix & matrix )
        {
            for( int i = 0; i < matrix.rows; i++ )
            {
                for( int j = 0; j < matrix.columns; j++ )
                {
                    os << matrix[ i ][ j ] << '\t';
                }

                os << std::endl;
            }

            return os;
        }


        template< typename OtherNumeric >
        auto operator+( Matrix< OtherNumeric > & other )
        {
            assert( rows == other.getRows() and columns == other.getColumns() );


            using ReturnType = decltype( Numeric() + OtherNumeric() );

            Matrix< ReturnType > result( rows, columns );


            Matrix & me = * this;

            for( int i = 0; i < rows; i++ )
            {
                for( int j = 0; j < columns; j++ )
                {
                    result[ i ][ j ] = me[ i ][ j ] + other[ i ][ j ];
                }
            }


            return std::move( result );
        }


        template< typename OtherNumeric >
        auto operator-( Matrix< OtherNumeric > & other )
        {
            assert( rows == other.getRows() and columns == other.getColumns() );


            using ReturnType = decltype( Numeric() - OtherNumeric() );

            Matrix< ReturnType > result( rows, columns );


            Matrix & me = * this;

            for( int i = 0; i < rows; i++ )
            {
                for( int j = 0; j < columns; j++ )
                {
                    result[ i ][ j ] = me[ i ][ j ] - other[ i ][ j ];
                }
            }


            return std::move( result );
        }


        template< typename OtherNumeric >
        auto operator*( Matrix< OtherNumeric > & other )
        {
            assert( columns == other.getRows() );


            using ReturnType = decltype( Numeric() * OtherNumeric() + Numeric() * OtherNumeric() );

            Matrix< ReturnType > result( rows, other.getColumns() );


            Matrix & me = * this;

            for( int i = 0; i < rows; i++ )
            {
                for( int j = 0; j < other.getColumns(); j++ )
                {
                    auto & cell = result[ i ][ j ];

                    cell = {};

                    for( int k = 0; k < columns; k++ )
                    {
                        cell = cell + me[ i ][ k ] * other[ k ][ j ];
                    }
                }
            }


            return std::move( result );
        }


        Matrix() : rows( 0 ), columns( 0 )
        {
            elements = nullptr;
        }



        Matrix( int rows, int columns, Numeric * numeric ) : rows( rows ), columns( columns ), elements( numeric )
        {
        }


        Matrix( int rows, int columns ) : Matrix( rows, columns, new Numeric[ rows * columns ] )
        {
        }


        Matrix( int rows, int columns, Numeric ** numeric ) : Matrix( rows, columns )
        {
            for( int i = 0; i < rows; i++ )
            {
                for( int j = 0; j < columns; j++ )
                {
                    elements[ i ][ j ] = numeric[ i ][ j ];
                }
            }
        }


        template< int COLUMNS >
        Matrix( int rows, Numeric ( * numericArray )[ COLUMNS ] ) : Matrix( rows, COLUMNS, & numericArray[ 0 ][ 0 ] )
        {
        }


        template< int LENGTH >
        Matrix( int rows, Numeric ( & numericArray )[ LENGTH ] ) : Matrix( rows, LENGTH / rows )
        {
            assert( LENGTH % rows == 0 );

            memcpy( elements, & numericArray, sizeof( numericArray ) );
        }


        template< int ROWS, int COLUMNS >
        Matrix( Numeric ( & numericArray )[ ROWS ][ COLUMNS ] ) : Matrix( ROWS, COLUMNS )
        {
            memcpy( elements, & numericArray, sizeof( numericArray ) );
        }


        Matrix( Matrix && other ) : Matrix( other.rows, other.columns, other.elements )
        {
            new( & other ) Matrix();
        }


        Matrix( Matrix & other ) : Matrix( other.rows, other.columns )
        {
            memcpy( elements, other.elements, rows * columns * sizeof( Numeric ) );
        }


        ~Matrix()
        {
            delete [] elements;
        }
};
