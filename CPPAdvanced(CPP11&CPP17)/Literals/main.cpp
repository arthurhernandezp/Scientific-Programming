#include <iostream>
/*
 *  User defined Literals
 */

/*
 * Literals are constants
 *
 * C++ has 4 kinds of literals
 *      intenger        -----   45
 *      floating point  -----   4.5
 *      character       -----   'z'
 *      string          -----   "Dog"
 */

//C++ 11
//User defined literals

constexpr double operator"" _cm(long double x){return x * 10;}
constexpr long double operator"" _m(long double x){return x * 1000;}
constexpr long double operator"" _mm(long double x){return x;}

int main()
{
    45;         // int literal
    45u;        // unsigned int     (suffix specifies type)
    45l;        // long

    //C++ 99
    long double height = 3.4;       //Metres? Centimeters? Inches?

    //C++ 11
    long double height2 = 1.10_m;
    long double height3 = 3.4_cm;
    long double height4 = 500.0_mm;

    long double height5 = height3 + 13.0_m;     // height5: 13034
    return 0;
}