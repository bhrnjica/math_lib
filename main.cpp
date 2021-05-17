#include "Fraction.hpp" 

#include "Complex.hpp"

#include "Matrix.hpp"

void fractionTest();

void complexTest();

void matrixTest();


int main( int argc, char *argv[] )
{
    //fractionTest();
    
    //complexTest();

    matrixTest();

    return 0;
}


void matrixTest()
{
    Matrix<int> m( 3 , 3 );
    cout<< m << endl;
}


void complexTest()
{
    int i1 = 4;

    int i2 = 7;

    long l1 = 16;

    long l2 = 23;
    
    double d = 32.5;

    Fraction< long > f1 ( l1, i1 );

    Fraction< long > f2 ( l2, i2 );


    Complex < int > c1 ( i1, l1 );

    Complex < long > c2 ( l1, d );

    Complex < double > c3 ( l1, d );

    Complex <Fraction<long> > c4 ( i1, f1);

    Complex < long > c5 ( i1, f1);

    Complex < Fraction < long > > c6 ( l1, f2);


    cout<< "Result: " << c6 * 0 <<endl;


    cout<< "Constructions examples: " << endl;

    cout<< "int: " << i1 << "; long: " << l1 << "; double: " << d <<"; fraction1: " << f1 << "; fraction2: " << f2 << endl;

    cout<< "Complex < int  >: " << c1 <<endl;

    cout<< "Complex < long  >: " << c2 <<endl;

    cout<< "Complex < double >: " << c3 <<endl;

    cout<< "Complex <Fraction<long> >: " << c4 <<endl;

    cout<< "Complex <Fraction<long> >: " << c5 <<endl;

    cout<< "Complex <Fraction2<long> >: " << c6 <<endl;
   
    cout<< "End of Constructions examples: " << endl;


    cout<< "Operations examples: " << endl;

    cout<< "Complex < int  > + Complex < long >: " << c2 + c1 <<endl;

    cout<< "Complex <double> + Complex <long>: " << c3 + c2 <<endl;

    cout<< "Complex <Fraction<long> > + Complex <long>: " << c4 + c2<<endl;

    cout<< "Complex <Fraction<long> > + Complex <double>: " << c6 + c3 <<endl;
}


void fractionTest()
{
    int m = 1, n = 2;

    long a = 3, b = 5;

    long x = 3;

    double d = 0.5;



    Fraction< int > f( m, n );

    Fraction< long > g( a, b );



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
}
