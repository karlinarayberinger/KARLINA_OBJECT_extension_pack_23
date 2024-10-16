/**
 * file: logarithm.cpp
 * type: C++ (source file)
 * date: 15_OCTOBER_2024
 * author: karbytes
 * license: PUBLIC_DOMAIN 
 */

/** preprocessing directives */
#include <iostream> // standard input (std::cin), standard output (std::cout)
#include <fstream> // file input, file output
#define MAXIMUM_x 10000 // constant which represents maximum value of x
#define MAXIMUM_logarithmic_base 10000 // constant which represents maximum value of logarithmic_base

/** function prototypes */
bool is_whole_number(double x);
double absolute_value(double x);
double power_of_e_to_x(double x);
float ln(float x);
double power(double base, double exponent);
double logarithm(double x, double logarithmic_base);

/** program entry point */
int main()
{
    // Define three double type variables for storing floating-point number values.
    double x = 0.0, logarithmic_base = 0.0, result = 0.0;

    // Declare a file output stream handler (which represents the plain-text file to generate and/or overwrite with program data).
    std::ofstream file;

    /**
     * If the file named logarithm_output.txt does not already exist 
     * inside of the same file directory as the file named logarithm.cpp, 
     * create a new file named logarithm_output.txt in that directory.
     * 
     * Open the plain-text file named logarithm_output.txt
     * and set that file to be overwritten with program data.
     */
    file.open("logarithm_output.txt");

    // Print an opening message to the command line terminal.
    std::cout << "\n\n--------------------------------";
    std::cout << "\nStart Of Program";
    std::cout << "\n--------------------------------";

    // Print an opening message to the file output stream.
    file << "--------------------------------";
    file << "\nStart Of Program";
    file << "\n--------------------------------";

    // Print "This C++ program computes the logarithm of x in some given logarithmic base." to the command line terminal and to the file output stream.
    std::cout << "\n\nThis C++ program computes the logarithm of x in some given logarithmic base.";
    file << "\n\nThis C++ program computes the logarithm of x in some given logarithmic base.";

    // Print a horizontal divider line to the command line terminal and to the file output stream.
    std::cout << "\n\n--------------------------------";
    file << "\n\n--------------------------------";

    // Prompt the user to enter an input value for x (and print that prompt to the command line terminal and to the file output stream).
    std::cout << "\n\nEnter a positive real number, x, to take the logarithm of and which is no larger than " << MAXIMUM_x << ": ";
    file << "\n\nEnter a positive real number, x, to take the logarithm of and which is no larger than " << MAXIMUM_x << ": ";

    // Scan the command line terminal for the most recent keyboard input value. Store that value in x.
    std::cin >> x;

    // Print "The value which was entered for x is {x}." to the command line terminal and to the file output stream.
    std::cout << "\nThe value which was entered for x is " << x << ".";
    file << "\n\nThe value which was entered for x is " << x << ".";

    // Print a horizontal divider line to the command line terminal and to the file output stream.
    std::cout << "\n\n--------------------------------";
    file << "\n\n--------------------------------";

    // Prompt the user to enter an input value for logarithmic_base (and print that prompt to the command line terminal and to the file output stream).
    std::cout << "\n\nEnter a positive real number, logarithmic_base, which is a positive real number other than one and which is no larger than " << MAXIMUM_logarithmic_base << ": ";
    file << "\n\nEnter a positive real number, logarithmic_base, which is a positive real number other than one and which is no larger than " << MAXIMUM_logarithmic_base << ": ";

    // Scan the command line terminal for the most recent keyboard input value. Store that value in logarithmic_base.
    std::cin >> logarithmic_base;

    // Print "The value which was entered for logarithmic_base is {logarithmic_base}." to the command line terminal and to the file output stream.
    std::cout << "\nThe value which was entered for logarithmic_base is " << logarithmic_base << ".";
    file << "\n\nThe value which was entered for logarithmic_base is " << logarithmic_base << ".";

    // Print a horizontal divider line to the command line terminal and to the file output stream.
    std::cout << "\n\n--------------------------------";
    file << "\n\n--------------------------------";

    // Set x to 1 by default if x is out of range (and specify that such a change occurred in the command line terminal and output file stream).
    if ((x <= 0) || (x > MAXIMUM_x)) 
    {
        x = 1; 
        std::cout << "\n\nDue to fact that x was determined to be either less than or equal to zero or else greater than " << MAXIMUM_x << ", x was set to the default value 1.";
        file << "\n\nDue to fact that x was determined to be either less than or equal to zero or else greater than " << MAXIMUM_x << ", x was set to the default value 1.";
    }

    // Set logarithmic_base to 2 if logarithmic_base is out of range (and specify that such a change occurred in the command line terminal and output file stream).
    if (!(logarithmic_base > 0) || (logarithmic_base == 1) || (logarithmic_base > MAXIMUM_logarithmic_base)) 
    {
        logarithmic_base = 2; 
        std::cout << "\n\nDue to fact that logarithmic_base was determined to be either less than zero, equal to one, or else greater than " << MAXIMUM_logarithmic_base << ", logarithmic_base was set to the default value 2.";
        file << "\n\nDue to fact that logarithmic_base was determined to be either less than zero, equal to one, or else greater than " << MAXIMUM_logarithmic_base << ", logarithmic_base was set to the default value 2.";
    }

    // Obtain the result of log_b(x) where b is logarithmic_base.
    result = logarithm(x, logarithmic_base);

    // Print the result of the logarithmic function to the command line terminal and to the file output stream.
    std::cout << "\n\nresult = logarithm(x, logarithmic_base) = logarithm(" << x << ", " << logarithmic_base << ") = " << result << ".";
    file << "\n\nresult = logarithm(x, logarithmic_base) = logarithm(" << x << ", " << logarithmic_base << ") = " << result << ".";

    // Print the inverse of the logarithmic expression to the command line terminal and to the file output stream.
    std::cout << "\n\nx = logarithmic_base ^ result --> " << x << " = " << logarithmic_base << " ^ " << result << ".";
    std::cout << "\n\nx = power(logarithmic_base, result) = " << power(logarithmic_base, result) << ".";
    file << "\n\nx = logarithmic_base ^ result --> " << x << " = " << logarithmic_base << " ^ " << result << ".";
    file << "\n\nx = power(logarithmic_base, result) = " << power(logarithmic_base, result) << ".";

    // Print a closing message to the command line terminal.
    std::cout << "\n\n--------------------------------";
    std::cout << "\nEnd Of Program";
    std::cout << "\n--------------------------------\n\n";

    // Print a closing message to the file output stream.
    file << "\n\n--------------------------------";
    file << "\nEnd Of Program";
    file << "\n--------------------------------";

    // Close the file output stream.
    file.close();

    // Exit the program.
    return 0; 
}

/**
 * If x is determined to be a whole number, return true.
 * Otherwise, return false.
 * 
 *--------------------------------------------------------------------------------------------------------------------
 * 
 * The following function was copied from the C++ source code file featured in the following tutorial web page:
 * 
 * https://karlinaobject.wordpress.com/exponentiation/
 * 
 *--------------------------------------------------------------------------------------------------------------------
 */
bool is_whole_number(double x)
{
    return (x == (long int) x); 
}

/**
 * Return the absolute value of a real number input, x.
 * 
 *--------------------------------------------------------------------------------------------------------------------
 * 
 * The following function was copied from the C++ source code file featured in the following tutorial web page:
 * 
 * https://karlinaobject.wordpress.com/exponentiation/
 * 
 *--------------------------------------------------------------------------------------------------------------------
 */
double absolute_value(double x)
{
    if (x < 0) return -1 * x;
    return x;
}

/**
 * Return the approximate value of Euler's Number to the power of some real number x.
 * 
 * This function is essentially identical to the C++ library math.h function exp().
 * 
 *--------------------------------------------------------------------------------------------------------------------
 * 
 * The following function was copied from the C++ source code file featured in the following tutorial web page:
 * 
 * https://karlinaobject.wordpress.com/exponentiation/
 * 
 *--------------------------------------------------------------------------------------------------------------------
 */
double power_of_e_to_x(double x) {
    double a = 1.0, e = a;
    int n = 1;
    int invert = x < 0;
    x = absolute_value(x);
    for (n = 1; e != e + a; n += 1) {
        a = a * x / n;
        e += a;
    }
    return invert ? (1 / e) : e;
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
 *----------------------------------------------------------------------------------------------------------------------------------------
 * 
 * The following function was copied (and slightly edited) from the C++ source code file featured in the following tutorial web page:
 * 
 * https://karlinaobject.wordpress.com/exponentiation/
 * 
 * (The data types of the function parameters have been changed from double to float).
 *
 *----------------------------------------------------------------------------------------------------------------------------------------
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
 * Note that the base of a logarithm cannot be 1 because
 * 
 * log_1(x) = y implies (1 ^ y) = x only if x and y are identical and equal to 1.
 * 
 * log_1(2) = y implies (1 ^ y) = 2 when multiplying 1 by itself by any number of times should always yield the result 1; not 2 (or some other non-one number).
 * 
 * As an aside, any non-zero number to the power of zero is one due to the following:
 * 
 * Let a be any non-zero number. Then
 * 
 * (a ^ 3) = a * a * a
 * 
 * and 
 * 
 * (a ^ 2) = a * a
 * 
 * and 
 * 
 * (a ^ 1) = a.
 * 
 * Also, according to the rule of exponents, dividing a power by the base gives the next lower power. Hence,
 * 
 * (a ^ 2) = (a ^ 3) / a = (a ^ 2)
 * 
 * and
 * 
 * (a ^ 1) = (a ^ 2) / a
 * 
 * and, similarly,
 * 
 * (a ^ 0) = (a ^ 1) / a = a / a = 1.
 * 
 * ((0 ^ 1) = 0 * 1 = 0 but (0 ^ 0) = (0 ^ 1) / 0 = 0 / 0 which is technically "not a number").
 * 
 * (Dividing a number by zero is theoretically impossible while multiplying that number by zero (which results in zero) 
 * is theoretically possible because to say that some number is multiplied by zero is logically equivalent to saying 
 * that number occurs zero times. By contrast, dividing some number by zero is logically equivalent to saying that
 * number is compartmentalized into zero equally-sized parts (and none of those parts apparently have any non-zero size and
 * infinitely many of such parts take up any space of any size (whether that size is zero or some positive quantity))).
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
 * logarithmic_base is required to be a positive real number other than one.
 * 
 * This function works by utilizing the following Change of Base (for Logarithms) formula:
 * 
 * log_b = ln(x) / ln(b)
 */
double logarithm(double x, double logarithmic_base) {
    if ((x <= 0) || (x > MAXIMUM_x)) x = 1; // Set x to 1 by default if x is out of range.
    if (!(logarithmic_base > 0) || (logarithmic_base == 1) || (logarithmic_base > MAXIMUM_logarithmic_base)) logarithmic_base = 2; // Set logarithmic_base to 2 if logarithmic_base is out of range.
    return ln(x) / ln(logarithmic_base);
}