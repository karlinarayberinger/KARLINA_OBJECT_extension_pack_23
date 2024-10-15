/**
 * file: logarithm.cpp
 * type: C++ (source file)
 * date: 15_OCTOBER_2024
 * author: karbytes
 * license: PUBLIC_DOMAIN 
 */

/** preprocessing directives */
#include <iostream>
#include <cstdlib>
#include <limits>
#define MAXIMUM_x 10000 // constant which represents maximum value of x
#define MAXIMUM_logarithmic_base 10000 // constant which represents maximum value of logarithmic_base

/** function prototypes */
float ln(float x) 
double power(double base, double exponent);
double logarithm(double x, double logarithmic_base);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <logarithmic_base> <x>\n";
        return 1;
    }

    // Parse the input values from command line
    double logarithmic_base = std::atof(argv[1]);
    double x = std::atof(argv[2]);

    if (logarithmic_base <= 0 || x <= 0) {
        std::cerr << "Error: logarithmic base and x must be positive numbers.\n";
        return 1;
    }

    // Compute logarithm
    double result = logarithm(x, logarithmic_base);

    // Output result
    std::cout << "log_" << logarithmic_base << "(" << x << ") = " << result << std::endl;

    return 0;
}










//--------------------------------------------------------------------------------------------------------------------
// The following function and associated comments were not written by karbytes. 
//
// The following function is essentially identical to the C++ library math.h function log().
//
//--------------------------------------------------------------------------------------------------------------------
//
// The following function was copied from the C++ source code file featured in the following tutorial web page:
//
// https://karlinaobject.wordpress.com/exponentiation/
//
//--------------------------------------------------------------------------------------------------------------------

// ln.c
//
// simple, fast, accurate natural log approximation
// when without 

// featuring * floating point bit level hacking,
//           * x=m*2^p => ln(x)=ln(m)+ln(2)p,
//           * Remez algorithm

// by Lingdong Huang, 2020. Public domain.

// ============================================

float ln(float x) {
  unsigned int bx = * (unsigned int *) (&x);
  unsigned int ex = bx >> 23;
  signed int t = (signed int)ex-(signed int)127;
  unsigned int s = (t < 0) ? (-t) : t;
  bx = 1065353216 | (bx & 8388607);
  x = * (float *) (&bx);
  return -1.49278+(2.11263+(-0.729104+0.10969*x)*x)*x+0.6931471806*t;
}
// done.

//--------------------------------------------------------------------------------------------------------------------
// End of code which was not written by karbytes. 
//--------------------------------------------------------------------------------------------------------------------

/**
 * Reverse engineer the cmath pow() function 
 * using the following properties of natural logarithms:
 * 
 * ln(x ^ y) = y * ln(x).
 * 
 * ln(e ^ x) = x. // e is approximately Euler's Number.
 * 
 * Note that the base of the logarithmic function 
 * used by the cmath log() function is e.
 * 
 * Hence, log(x) is approximately the 
 * natural log of x (i.e. ln(x)).
 * 
 * Note that the base of the exponential function
 * used by the cmath exp() function is
 * (approximately) Euler's Number.
 * 
 * Hence, exp(x) is approximately 
 * x ^ e (where e is approximately Euler's Number).
 * 
 * Note that any number, x, raised to the power of 0 is 1.
 * In more succinct terms, x ^ 0 = 1.
 * 
 * Note that any number, x, raised to the power of 1 is x.
 * In more succinct terms, x ^ 1 = x.
 * 
 * Note that any whole number, x, 
 * raised to the power of a positive whole number exponent, y, 
 * is x multiplied by itself y times.
 * For example, if x is 2 and y is 3, 
 * 2 ^ 3 = power(2, 3) = 2 * 2 * 2 = 8.
 * 
 * Note that any whole number, x, 
 * raised to the power of a negative exponent, y, 
 * is 1 / (x ^ (-1 * y)).
 * For example, if x is 2 and y is -3,
 * 2 ^ -3 = power(2, -3) = 1 / (2 * 2 * 2) = 1 / 8 = 0.125.
 * 
 *--------------------------------------------------------------------------------------------------------------------
 * 
 * The following function was copied from the C++ source code file featured in the following tutorial web page:
 * 
 * https://karlinaobject.wordpress.com/exponentiation/
 *
 *--------------------------------------------------------------------------------------------------------------------
 */
double power(double base, double exponent)
{
    double output = 1.0;
    if (exponent == 0) return 1; 
    if (exponent == 1) return base;
    // if ((base == 0) && (exponent < 0)) return -666; // Technically 0 raised to the power of some negative exponent is undefined (i.e. not a number).
    if (is_whole_number(exponent))
    {
        if (exponent > 0)
        {
            while (exponent > 0) 
            {
                output *= base;
                exponent -= 1;
            }
            return output;
        }
        else 
        {
            exponent = absolute_value(exponent);
            while (exponent > 0)
            {
                output *= base;
                exponent -= 1;
            }
            return 1 / output;
        }
    }
    if (exponent > 0) return power_of_e_to_x(ln(base) * exponent); // Return e ^ (ln(base) * exponent).
    return power_of_e_to_x(power_of_e_to_x(ln(base) * absolute_value(exponent))); // Return e ^ (e ^ (ln(base) * absolute_value(exponent))).
}

// Function to compute logarithm base logarithmic_base of x

/**
 * This function returns the result of the following calculation: 
 * log_b(x) where log_b is the logarithmic function whose base is b (and where b is logarithmic_base).
 * 
 * A logarithm is the inverse of exponentiation. 
 * 
 * For example, ln(x) = y is the inverse of (e ^ y) = x 
 * given that the logarithmic base of the function ln(x) is Euler's Number, e 
 * (which is approximately equal to 2.71828182845904524019865766693015984856174327433109283447265625).
 * 
 *--------------------------------------------------------------------------------------------------------------------
 * 
 * An algorithm for computing the approximate value of Euler's Number is implemented by the C++ program 
 * featured in the following tutorial web page:
 * 
 * https://karlinaobject.wordpress.com/eulers_number_approximation/
 * 
 *--------------------------------------------------------------------------------------------------------------------
 * 
 * Note that the equation (e ^ y) = x is functionally identical to power(e, y) = x 
 * and essentially states that x is the product of multiplying e by itself y times.
 * 
 * x is required to be a positive real number.
 * 
 * logarithmic_base is required to be a positive real number which is larger than one.
 * 
 * This function works by utilizing the following Change of Base (for Logarithms) formula:
 * 
 * log_b = ln(x) / ln(b)
 */
double logarithm(double x, double logarithmic_base) {
    if ((x <= 0) || (x > MAXIMUM_x)) x = 1; // Set x to 1 by default if x is out of range.
    if ((logarithmic_base <= 1) || (logarithmic_base > MAXIMUM_logarithmic_base)) logarithmic_base = 2; // Set logarithmic_base to 2 if logarithmic_base is out of range.
    return ln(x) / ln(logarithmic_base);
}