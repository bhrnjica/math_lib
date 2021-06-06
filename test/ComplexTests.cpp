
#include <gtest/gtest.h>

#include <Complex.hpp>

TEST( math_lib_test, CreateComplexTest )
{

    Complex< int > ci1{ 3, 1 };

    Complex< long > ci2{ 2, 5 };

    ASSERT_EQ( 3, ci1.getReal() );

    ASSERT_EQ( 1, ci1.getImaginary() );

    ASSERT_EQ( 2, ci2.getReal() );

    ASSERT_EQ( 5, ci2.getImaginary() );

    EXPECT_EQ( sizeof( int ), sizeof( ci1.getReal() ));

    EXPECT_EQ( sizeof( int ), sizeof( ci1.getImaginary()));

    EXPECT_EQ( sizeof( long ), sizeof( ci2.getReal() ));

    EXPECT_EQ( sizeof( long ), sizeof( ci2.getImaginary()));



    Complex< double > cd1 { 1.5, 2.5 };

    Complex< double > cd2 { 0.2, 1.1 };

    ASSERT_EQ( 1.5, cd1.getReal() );

    ASSERT_EQ( 2.5, cd1.getImaginary() );

    ASSERT_EQ( 0.2, cd2.getReal() );

    ASSERT_EQ( 1.1, cd2.getImaginary() );

    EXPECT_EQ( sizeof( double ), sizeof( cd1.getReal() ));

    EXPECT_EQ( sizeof( double ), sizeof( cd1.getImaginary()));

    EXPECT_EQ( sizeof( double ), sizeof( cd2.getReal() ));

    EXPECT_EQ( sizeof( double ), sizeof( cd2.getImaginary()));


    Complex< Fraction< long > > cfl1{ { 2, 3 }, { 5, 7 } };

    Complex< Fraction< int > > cfi1{ { 3, 4 }, { 7, 2 } };


    Fraction< long > fl1{2,3};

    ASSERT_EQ(fl1, cfl1.getReal() );

    Fraction< long > fl2{5,7};

    ASSERT_EQ( fl2, cfl1.getImaginary() );


    Fraction< int > fi1{3,4};

    ASSERT_EQ(fi1, cfi1.getReal() );

    Fraction< int > fi2{7,2};

    ASSERT_EQ( fi2, cfi1.getImaginary() );

}

TEST( math_lib_test, OperationsComplexTest )
{
    int m = 2;
    int n = 3;

    long a = 4;
    long b = 5;

    double c = 4;
    double d = 6;

    Fraction< int > f1 ( m, n );

    Fraction< int > f2 ( a, b );


    Complex< int > c1{ 3, 1 };

    Complex< long > c2{ 2, 5 };

    Complex< double > c3 { 1.5, 2.5 };

    Complex< double > c4 { 0.2, 1.1 };

    Complex< Fraction< long > > c5{ { 2, 3 }, { 5, 7 } };

    Complex< Fraction< int > > c6{ { 3, 4 }, { 7, 2 } };


    auto r1 = c1 + a;

    auto r2 = c2 + d;


    ASSERT_EQ( 7, r1.getReal() );

    ASSERT_EQ( 1, r1.getImaginary() );

    EXPECT_EQ( sizeof( long ), sizeof( r1.getReal() ));

    EXPECT_EQ( sizeof( long ), sizeof( r1.getImaginary() ));


    ASSERT_EQ( 8, r2.getReal() );

    EXPECT_EQ( 5, r2.getImaginary() );

    EXPECT_EQ( sizeof( double ), sizeof( r2.getReal() ));

    auto r3 = c3 + f1;

    auto r4 = c2 + f2;

    EXPECT_NEAR( 2.16667, r3.getReal(), 0.00001);

    ASSERT_EQ( 2.5, r3.getImaginary() );

    EXPECT_EQ( sizeof( double ), sizeof( r3.getReal() ));

    EXPECT_EQ( sizeof( double ), sizeof( r3.getImaginary() ));

    EXPECT_EQ( 2.8, r4.getReal() );

    ASSERT_EQ( 5, r4.getImaginary() );


    auto r5 = c5 + m;

    Fraction < long > ffr1{ 8,3};

    Fraction < int > ffr2{ 5,7};

    ASSERT_EQ( ffr1, r5.getReal());

    ASSERT_EQ( ffr2, r5.getImaginary() );

    auto r6 = c6 + f2;

    Fraction < long > ffr3{ 31,20};

    Fraction < long > ffr4{ 7, 2};

    ASSERT_EQ( ffr3, r6.getReal());

    ASSERT_EQ( ffr4, r6.getImaginary() );

    auto r7 = c6 + f2 + d;

    Fraction < int > ffr6{ 7, 2};


    ASSERT_EQ( 7.55, r7.getReal());

    ASSERT_EQ( ffr6, r7.getImaginary() );
}
