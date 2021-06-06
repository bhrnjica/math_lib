
#include <gtest/gtest.h>
#include <Fraction.hpp>

TEST( math_lib_test, CreateFractionTest )
{
    int m = 2;
    int n = 3;

    long a = 4;
    long b = 5;

    short c = 4;
    short d = 6;

    Fraction< int > f ( m, n );

    ASSERT_EQ( 2, f.getNumerator() );

    ASSERT_EQ( 3, f.getDenominator() );

    EXPECT_EQ( typeid( m ).name(), typeid( f.getNumerator() ).name( ));

    EXPECT_EQ( typeid( m ).name(), typeid( f.getNumerator() ).name( ));


    Fraction< long > g ( a, b );

    ASSERT_EQ(4, g.getNumerator() );

    ASSERT_EQ( 5, g.getDenominator() );

    EXPECT_EQ( typeid( b ).name(), typeid( g.getNumerator() ).name( ));

    EXPECT_EQ( typeid( b ).name(), typeid( g.getDenominator() ).name( ));


    Fraction< short > h ( c, d );

    ASSERT_EQ( 2, h.getNumerator() );

    ASSERT_EQ( 3, h.getDenominator() );


    EXPECT_EQ( typeid( c ).name(), typeid( h.getNumerator() ).name( ));

    EXPECT_EQ( typeid( d ).name(), typeid( h.getDenominator() ).name( ));


    Fraction< int > k ( c, d );

    EXPECT_EQ( typeid( n ).name(), typeid( k.getNumerator() ).name( ));

    EXPECT_EQ( typeid( n ).name(), typeid( k.getDenominator() ).name( ));

}

TEST( math_lib_test, ZeroFraction )
{
    EXPECT_THROW({
        try
        {
            Fraction< int> zerro( 1, 0 );
        }
        catch( const std::runtime_error& ex )
        {
            // and this tests that it has the correct message
            EXPECT_STREQ( "Divide by zero!", ex.what() );
            throw;
        }
    }, std::runtime_error );
}

TEST( math_lib_test, FractionTypePromotionTest1 )
{
    int m = 2;
    int n = 3;

    long a = 4;
    long b = 5;

    short c = 4;
    short d = 6;

    Fraction< int > f ( m, n );

    Fraction< long > g ( a, b );

    Fraction< short > h ( c, d );

    auto f1 = f + g;

    auto fd1 = f - g;


    auto f2 = f + h;

    auto fd2 = f - h;

    auto f3 = h + g;

    auto fd3 = h - g;


    EXPECT_EQ( sizeof(long), sizeof( f1.getNumerator() ));

    EXPECT_NE( sizeof(int), sizeof( f1.getDenominator() ));

    EXPECT_EQ( sizeof(long), sizeof( fd1.getNumerator() ));

    EXPECT_NE( sizeof(int), sizeof( fd1.getDenominator() ));


    EXPECT_EQ( sizeof(int), sizeof( f2.getNumerator() ));

    EXPECT_NE( sizeof(short), sizeof( f2.getDenominator()));

    EXPECT_EQ( sizeof(int), sizeof( fd2.getNumerator() ));

    EXPECT_NE( sizeof(short), sizeof( fd2.getDenominator()));


    EXPECT_EQ( sizeof(long), sizeof( f3.getNumerator() ));

    EXPECT_NE( sizeof(short), sizeof( f3.getDenominator() ));

    EXPECT_EQ( sizeof(long), sizeof( fd3.getNumerator() ));

    EXPECT_NE( sizeof(short), sizeof( fd3.getDenominator() ));

}

TEST( math_lib_test, FractionOperationTest )
{
    int m = 2;
    int n = 3;

    long a = 4;
    long b = 5;

    short c = 4;
    short d = 6;

    Fraction< int > f ( m, n );

    Fraction< long > g ( a, b );

    Fraction< short > h ( c, d );

    auto f1 = f + g;

    auto fd1 = f - g;


    ASSERT_EQ( 22, f1.getNumerator() );

    ASSERT_EQ( 15, f1.getDenominator() );


    ASSERT_EQ( -2, fd1.getNumerator() );

    ASSERT_EQ( 15, fd1.getDenominator() );


    auto f2 = f + h;

    auto fd2 = f - h;


    ASSERT_EQ( 4, f2.getNumerator() );

    ASSERT_EQ( 3, f2.getDenominator() );


    ASSERT_EQ( 0, fd2.getNumerator() );

    //ASSERT_EQ( 1, fd2.getDenominator() );


    auto f3 = h + g;

    auto fd3 = h - g;


    ASSERT_EQ( 22, f3.getNumerator() );

    ASSERT_EQ( 15, f3.getDenominator() );


    ASSERT_EQ( -2, fd3.getNumerator() );

    ASSERT_EQ( 15, fd3.getDenominator() );

}

TEST( math_lib_test, FractionOperationTest2 )
{
    int m = 2;
    int n = 3;

    long a = 4;
    long b = 5;

    short c = 4;
    short d = 6;

    Fraction< int > f ( m, n );

    Fraction< long > g ( a, b );

    Fraction< short > h ( c, d );

    auto f1 = f * g;

    auto fd1 = f / g;


    ASSERT_EQ( 8, f1.getNumerator() );

    ASSERT_EQ( 15, f1.getDenominator() );


    ASSERT_EQ( 5, fd1.getNumerator() );

    ASSERT_EQ( 6, fd1.getDenominator() );


    auto f2 = f * h;

    auto fd2 = f / h;


    ASSERT_EQ( 4, f2.getNumerator() );

    ASSERT_EQ( 9, f2.getDenominator() );


    ASSERT_EQ( 1, fd2.getNumerator() );

    ASSERT_EQ( 1, fd2.getDenominator() );


    auto f3 = h * g;

    auto fd3 = h / g;


    ASSERT_EQ( 8, f3.getNumerator() );

    ASSERT_EQ( 15, f3.getDenominator() );

    ASSERT_EQ( 5, fd3.getNumerator() );

    ASSERT_EQ( 6, fd3.getDenominator() );

}


TEST( math_lib_test, FractionTypePromotionTest2 )
{
    int m = 2;
    int n = 3;

    long a = 4;
    long b = 5;

    short c = 4;
    short d = 6;

    Fraction< int > f ( m, n );

    Fraction< long > g ( a, b );

    Fraction< short > h ( c, d );

    auto f1 = f * g;

    auto fd1 = f / g;


    auto f2 = f * h;

    auto fd2 = f / h;

    auto f3 = h * g;

    auto fd3 = h / g;


    EXPECT_EQ( sizeof(long), sizeof( f1.getNumerator() ));

    EXPECT_NE( sizeof(int), sizeof( f1.getDenominator() ));

    EXPECT_EQ( sizeof(long), sizeof( fd1.getNumerator() ));

    EXPECT_NE( sizeof(int), sizeof( fd1.getDenominator() ));
}


TEST( math_lib_test, FractionOperatorTests )
{
    int m = 2;
    int n = 3;

    long a = 4;
    long b = 5;

    short c = 4;
    short d = 6;

    Fraction< int > f ( m, n );

    Fraction< long > g ( a, b );

    Fraction< short > h ( c, d );

    Fraction < int > i (m, n);

    ASSERT_TRUE(f >= i);
    ASSERT_TRUE(i >= f);
    ASSERT_TRUE(f == i);
    ASSERT_TRUE(i == f);
    ASSERT_TRUE(f < g);
    ASSERT_TRUE(g > f);
    ASSERT_TRUE(g >  h);
    ASSERT_TRUE(h < g);
}

