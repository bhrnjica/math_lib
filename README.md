# Math Lib 

Math lib is c++ library of math routines around built-in numeric types: `integer`, `float` and `double`. Beside built-in numeric types the library supports custom implementation of `Fraction` and `Complex` type. 

The concept of the library is based on templatized class implementation where each method accept templatized type and returns the type compiler resolves by promotion.

Currently, the library support `Matrix` and `Vector` of any numeric types including `Fraction` and `Complex` with basic operations.

# Getting started 

Define `int`, `long`, `double`,  `Fraction` and `Complex` numbers:

```C++
int m = 1, n = 2;
long a = 3, b = 5;
long x = 3;
double d = 0.5;

Fraction< int > f( m, n );
Fraction< long > g( a, b );

Complex< Fraction < long > > c1{ { 2, 3 }, { 5, 7 } };
Complex< Fraction < int > > c2{ { 3, 4 }, { 7, 2 } };

Complex< int > c3 { 3, 1 };
Complex< int > c4 { 2, 5 };
Complex< double > c5 { 1.5, 2.5 };
Complex< double > c6 { 0.2, 1.1 };

```
Perform algeabric operation between them:

```C++
//operation between built-in and Fraction types

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
```
Operation with `Complex` type:

```C++

//operation between built-in and Fraction and Complex types
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
```

# Linear Algebra in math lib

Math lib implements `Matrix` and `Vector` of any defined numeric types. They can be created from the ordinary 2D and 1D arrays. For example:

```C++
//create 2D arrays
Fraction< int > firstArray [ 3 ][ 2 ] {   { { 4, 2 }, { 3, 5 } },
                                             { { 4, 3 }, { 2, 5 } },
                                             { { 1, 4 }, { 6, 5 } }
                                         };

Complex< Fraction< long > > secondArray[ 2 ][ 4 ] { { { { 1, 3 }, { 2, 5 } }, { { 4, 3 }, { 7, 2 } }, { { 1, 6 }, { 5, 2 } }, { { 7, 4 }, { 3, 8 } } },
                                                    { { { 2, 3 }, { 4, 5 } }, { { 1, 4 }, { 2, 6 } }, { { 1, 5 }, { 2, 7 } }, { { 3, 7 }, { 2, 8 } } }
                                                   };

double thirdArray[ 4 ] [ 2 ] = { 
                                  { 0.5, 1.2 }, 
                                  { 1.5, 0.1 }, 
                                  { 2.5, 0.6 }, 
                                  { 4, 0.8 } };
//create 1D arrays
Fraction< int > firstFArray[ 4 ] { { 1, 4 }, { 6, 5 }, { 7, 3 },{ 9, 7 } };
Complex< Fraction< long > > secondCArray [ 4 ] { { { 1, 3 }, { 2, 5 } }, { { 4, 3 }, { 7, 2 } },{{ 9, 6 }, { 11, 7 }} };
double thirdDArray[ 4 ] = { 0.5, 1.2 , 1.5, 0.1 };
    
//create Matrix from 2D array
Matrix< Fraction< int > > first( firstArray );
Matrix< Complex< Fraction< long > > > second( secondArray );
Matrix< double> third( thirdArray );

//create Vector from 1D array
Vector< Fraction< int > > vector_first( firstFArray );
Vector< Complex< Fraction< long > > > vector_second( secondCArray );
Vector< double> vector_third( thirdDArray );

//operation on Matrices
auto fs = first * second;
auto st = second * third;
auto fst = first * second * third;
std::cout << "first * second = \n" << fs << std::endl << std::endl;
std::cout << "second * third = \n" << st << std::endl << std::endl;
std::cout << "first * second * third = \n" << fst << std::endl << std::endl;

//operation on Vectors
auto vfs = vector_first * vector_second;
auto vst = vector_second * vector_third;
auto vfst = vector_first *  vector_second * vector_third;
std::cout << "v_first * v_second = \n" << vfs << std::endl << std::endl;
std::cout << "v_second * v_third = \n" << vst << std::endl << std::endl;
std::cout << "v_first * v_second * v_third = \n" << vfst << std::endl << std::endl;
```
