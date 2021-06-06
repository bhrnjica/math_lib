#include <gtest/gtest.h>

#include "FractionTests.cpp"

#include "ComplexTests.cpp"

#include "MatrixTests.cpp"

#include "VectorTests.cpp"

#include "StatsTests.cpp"

int main( int argc, char ** argv )
{
    ::testing::InitGoogleTest( & argc, argv );

    return RUN_ALL_TESTS();
}
