#include <Vector.hpp>
#include <Stats.hpp>



void statsTest()
{

    int n[6]= { 1, 2, 8, 4, 5, 6};

    Fraction < int > firstFArray[ 4 ] { { 1, 4 }, { 6, 5 }, { 7, 3 },{ 9, 7 } };

    Complex < Fraction< long > > secondCArray [ 4 ] { { { 1, 3 }, { 2, 5 } }, { { 4, 3 }, { 7, 2 } },{{ 9, 6 }, { 11, 7 }} };

    double thirdDArray[ 4 ] = { 0.5, 1.2 , 1.5, 0.1 };


    std::cout << "max of int  = " << Stats::max<int>(n) << std::endl;

    std::cout << "max of double  = " << Stats::max<Fraction < int > >(firstFArray) << std::endl;

    std::cout << "mean of int = " << Stats::mean<int>(n) << std::endl;

    std::cout << "mean of Fraction < int > = " << Stats::mean<Fraction < int > >(firstFArray) << std::endl;

    std::cout << "std of int = " << Stats::std<int>(n) << std::endl;

    std::cout << "std of fraction < int > = " << Stats::std<Fraction < int > >(firstFArray) << std::endl;

    std::cout << "varaiance of int = " << Stats::variance<int>(n) << std::endl;


    std::cout << "variance of fraction < int > = " << Stats::variance<Fraction < int > >(firstFArray) << std::endl;

    std::cout << "median of fraction < int > = " << Stats::median<Fraction < int > >(firstFArray) << std::endl;


}

int main( int argc, char *argv[] )
{
    statsTest();

    return 0;

    int m = 1, n = 2;

    long a = 3, b = 5;

    long x = 3;

    double d = 0.5;



    Fraction< int > f( m, n );

    Fraction< long > g( a, b );


    Complex< Fraction< long > > c1{ { 2, 3 }, { 5, 7 } };

    Complex< Fraction< int > > c2{ { 3, 4 }, { 7, 2 } };


    Complex< int > c3{ 3, 1 };

    Complex< int > c4{ 2, 5 };


    Complex< double > c5{ 1.5, 2.5 };

    Complex< double > c6{ 0.2, 1.1 };



    std::cout << "x = " << x << std::endl;

    std::cout << "d = " << d << std::endl;


    std::cout << "f = " << f << std::endl;

    std::cout << "g = " << g << std::endl;


    std::cout << "f + x = " << f + x << std::endl;

    std::cout << "x + f = " << x + f << std::endl;

    std::cout << "f + g = " << f + g << std::endl;


    std::cout << "f - x = " << f - x << std::endl;

    std::cout << "x - f = " << x - f << std::endl;

    std::cout << "f - g = " << f - g << std::endl;


    std::cout << "f * x = " << f * x << std::endl;

    std::cout << "x * f = " << x * f << std::endl;

    std::cout << "f * g = " << f * g << std::endl;


    std::cout << "f / x = " << f / x << std::endl;

    std::cout << "x / f = " << x / f << std::endl;

    std::cout << "f / g = " << f / g << std::endl;



    std::cout << "f + d = " << f + d << std::endl;

    std::cout << "d + f = " << d + f << std::endl;


    std::cout << "f * d = " << f * d << std::endl;

    std::cout << "d * f = " << d * f << std::endl;


    std::cout << "f / d = " << f / d << std::endl;

    std::cout << "d / f = " << d / f << std::endl;


    std::cout << "c1 = " << c1 << std::endl;

    std::cout << "c2 = " << c2 << std::endl;

    std::cout << "c3 = " << c3 << std::endl;

    std::cout << "c4 = " << c4 << std::endl;

    std::cout << "c5 = " << c5 << std::endl;

    std::cout << "c6 = " << c6 << std::endl;


    std::cout << "c1 + c2 = " << c1 + c2 << std::endl;

    std::cout << "c1 - c2 = " << c1 - c2 << std::endl;

    std::cout << "c1 * c2 = " << c1 * c2 << std::endl;

    std::cout << "c1 / c2 = " << c1 / c2 << std::endl;


    std::cout << "c3 + c4 = " << c3 + c4 << std::endl;

    std::cout << "c3 - c4 = " << c3 - c4 << std::endl;

    std::cout << "c3 * c4 = " << c3 * c4 << std::endl;

    std::cout << "c3 / c4 = " << c3 / c4 << std::endl;


    std::cout << "c5 + c6 = " << c5 + c6 << std::endl;

    std::cout << "c5 - c6 = " << c5 - c6 << std::endl;

    std::cout << "c5 * c6 = " << c5 * c6 << std::endl;

    std::cout << "c5 / c6 = " << c5 / c6 << std::endl;


    std::cout << "c5 + d = " << c5 + d << std::endl;

    std::cout << "c5 - d = " << c5 - d << std::endl;

    std::cout << "c5 * d = " << c5 * d << std::endl;

    std::cout << "c5 / d = " << c5 / d << std::endl;


    std::cout << "c5 + x = " << c5 + x << std::endl;

    std::cout << "c5 - x = " << c5 - x << std::endl;

    std::cout << "c5 * x = " << c5 * x << std::endl;

    std::cout << "c5 / x = " << c5 / x << std::endl;


    std::cout << "c2 + x = " << c2 + x << std::endl;

    std::cout << "c2 - x = " << c2 - x << std::endl;

    std::cout << "c2 * x = " << c2 * x << std::endl;

    std::cout << "c2 / x = " << c2 / x << std::endl;


    std::cout << "c1 + c6 = " << c1 + c6 << std::endl;

    std::cout << "c1 - c6 = " << c1 - c6 << std::endl;

    std::cout << "c1 * c6 = " << c1 * c6 << std::endl;

    std::cout << "c1 / c6 = " << c1 / c6 << std::endl;



    Fraction< int > fracStackTwo[ 2 ][ 2 ]{ { { 4, 2 }, { 3, 5 } }, { { 1, 3 }, { 2, 5 } } };

    int intStackTwo[ 2 ][ 2 ]{ { 3, 2 }, { 1, 4 } };


    auto fracDynTwo = new Fraction< int >[ 2 ][ 2 ];

    auto intDynTwo = new int[ 2 ][ 2 ];



    Fraction< int > fracStackOne[ 4 ]{ { 4, 2 }, { 3, 5 }, { 1, 3 }, { 2, 5 } };

    int intStackOne[ 4 ]{ 3, 2, 1, 4 };


    auto fracDynOne = new Fraction< int >[ 4 ];

    auto intDynOne = new int[ 4 ];



    for( int i = 0; i < 2; i++ )
    {
        for( int j = 0; j < 2; j++ )
        {
            fracDynTwo[ i ][ j ] = fracStackTwo[ i ][ j ];

            intDynTwo[ i ][ j ] = intStackTwo[ i ][ j ];
        }
    }


    for( int i = 0; i < 4; i++ )
    {
        fracDynOne[ i ] = fracStackOne[ i ];

        intDynOne[ i ] = intStackOne[ i ];
    }



    Matrix< Fraction< int > > fracStackTwoMatrix( fracStackTwo );

    Matrix< int > intStackTwoMatrix( intStackTwo );


    Matrix< Fraction< int > > fracDynTwoMatrix( 2, fracDynTwo );

    Matrix< int > intDynTwoMatrix( 2, intDynTwo );


    auto resultStackTwo = fracStackTwoMatrix + intStackTwoMatrix;

    auto resultDynTwo = fracDynTwoMatrix + intDynTwoMatrix;


    std::cout << "fracStackTwoMatrix = \n" << fracStackTwoMatrix << std::endl << std::endl;

    std::cout << "intStackTwoMatrix = \n" << intStackTwoMatrix << std::endl << std::endl;

    std::cout << "fracStackTwoMatrix + intStackTwoMatrix = \n" << resultStackTwo << std::endl << std::endl;


    std::cout << "fracDynTwoMatrix = \n" << fracDynTwoMatrix << std::endl << std::endl;

    std::cout << "intDynTwoMatrix = \n" << intDynTwoMatrix << std::endl << std::endl;

    std::cout << "fracDynTwoMatrix + intDynTwoMatrix = \n" << resultDynTwo << std::endl << std::endl;



    Matrix< Fraction< int > > fracStackOneMatrix( 2, fracStackOne );

    Matrix< int > intStackOneMatrix( 2, intStackOne );


    Matrix< Fraction< int > > fracDynOneMatrix( 2, 2, fracDynOne );

    Matrix< int > intDynOneMatrix( 2, 2, intDynOne );


    auto resultStackOne = fracStackOneMatrix + intStackOneMatrix;

    auto resultDynOne = fracDynOneMatrix + intDynOneMatrix;


    std::cout << "fracStackOneMatrix = \n" << fracStackOneMatrix << std::endl << std::endl;

    std::cout << "intStackOneMatrix = \n" << intStackOneMatrix << std::endl << std::endl;

    std::cout << "fracStackOneMatrix + intStackOneMatrix = \n" << resultStackOne << std::endl << std::endl;


    std::cout << "fracDynOneMatrix = \n" << fracDynOneMatrix << std::endl << std::endl;

    std::cout << "intDynOneMatrix = \n" << intDynOneMatrix << std::endl << std::endl;

    std::cout << "fracDynOneMatrix + intDynOneMatrix = \n" << resultDynOne << std::endl << std::endl;


    Fraction< int > firstArray[ 3 ][ 2 ] {   { { 4, 2 }, { 3, 5 } },
                                             { { 4, 3 }, { 2, 5 } },
                                             { { 1, 4 }, { 6, 5 } }
                                         };

    Complex< Fraction< long > > secondArray[ 2 ][ 4 ]{ { { { 1, 3 }, { 2, 5 } }, { { 4, 3 }, { 7, 2 } }, { { 1, 6 }, { 5, 2 } }, { { 7, 4 }, { 3, 8 } } },
                                                       { { { 2, 3 }, { 4, 5 } }, { { 1, 4 }, { 2, 6 } }, { { 1, 5 }, { 2, 7 } }, { { 3, 7 }, { 2, 8 } } }
                                                     };

    double thirdArray[ 4 ][ 2 ] = { { 0.5, 1.2 }, { 1.5, 0.1 }, { 2.5, 0.6 }, { 4, 0.8 } };


    Matrix< Fraction< int > > first( firstArray );

    Matrix< Complex< Fraction< long > > > second( secondArray );

    Matrix< double> third( thirdArray );


    auto fs = first * second;

    auto st = second * third;

    auto fst = first * second * third;


    std::cout << "first = \n" << first << std::endl << std::endl;

    std::cout << "second = \n" << second << std::endl << std::endl;

    std::cout << "third = \n" << third << std::endl << std::endl;


    std::cout << "first * second = \n" << fs << std::endl << std::endl;

    std::cout << "second * third = \n" << st << std::endl << std::endl;

    std::cout << "first * second * third = \n" << fst << std::endl << std::endl;


    Fraction< int > firstFArray[ 4 ] { { 1, 4 }, { 6, 5 }, { 7, 3 },{ 9, 7 } };

    Complex< Fraction< long > > secondCArray [ 4 ] { { { 1, 3 }, { 2, 5 } }, { { 4, 3 }, { 7, 2 } },{{ 9, 6 }, { 11, 7 }} };

    double thirdDArray[ 4 ] = { 0.5, 1.2 , 1.5, 0.1 };




    Vector< Fraction< int > > vector_first( firstFArray );

    Vector< Complex< Fraction< long > > > vector_second( secondCArray );

    Vector< double> vector_third( thirdDArray );


    auto vfs = vector_first * vector_second;

    auto vst = vector_second * vector_third;

    auto vfst = vector_first *  vector_second * vector_third;


    std::cout << "v_first = \n" << vector_first << std::endl << std::endl;

    std::cout << "v_second = \n" << vector_second << std::endl << std::endl;

    std::cout << "v_third = \n" << vector_third << std::endl << std::endl;


    std::cout << "v_first * v_second = \n" << vfs << std::endl << std::endl;

    std::cout << "v_second * v_third = \n" << vst << std::endl << std::endl;

    std::cout << "v_first * v_second * v_third = \n" << vfst << std::endl << std::endl;


    return 0;
}
