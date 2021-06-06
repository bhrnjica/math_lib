
#include <gtest/gtest.h>

#include <Complex.hpp>

TEST( math_lib_test, CreateComplexTest )
{

    Complex< int > ci1{ 3, 1 };

    Complex< int > ci2{ 2, 5 };


    Complex< double > cd1 { 1.5, 2.5 };

    Complex< double > cd2 { 0.2, 1.1 };


    Complex< Fraction< long > > cfl1{ { 2, 3 }, { 5, 7 } };

    Complex< Fraction< int > > cfi2{ { 3, 4 }, { 7, 2 } };




    ASSERT_EQ( 3, ci1.getReal() );

    ASSERT_EQ( 1, ci1.getImaginary() );

    EXPECT_EQ( sizeof( int ), sizeof( ci1.getReal() ));

    EXPECT_EQ( sizeof( int ), sizeof( ci1.getImaginary()));



}
