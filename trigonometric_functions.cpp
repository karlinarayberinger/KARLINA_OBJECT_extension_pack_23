/**
 * file: trigonometric_functions.cpp
 * type: C++ (source file)
 * date: 18_OCTOBER_2024
 * author: karbytes
 * license: PUBLIC_DOMAIN 
 */

/** preprocessing directives */
#include <iostream> // standard input (std::cin), standard output (std::cout)
#include <fstream> // file input, file output
#define MAXIMUM_i 10000 // constant which represents maximum number of iterations in Leibniz series
#define MAXIMUM_t 10000 // constant which represents maximum number of terms in Taylor series
#define MAXIMUM_x 10000 // constant which represents maximum value of x

/** function prototypes */
double computePi(int iterations);
double sine(double x);
double cosine(double x);
double tangent(double x);
double cotangent(double x);
double secant(double x);
double cosecant(double x);
double arctangent(double x);
double arcsine(double x);
double arccosine(double x);

/** program entry point */
int main() 
{

    double a = 0.0, b = 0.0;
    std::cout << "\n\n 0 / 0 = " << a / b << ".";
    double x;

    // Declare a file output stream handler (which represents the plain-text file to generate and/or overwrite with program data).
    std::ofstream file;

    // Set the number of digits of floating-point numbers which are printed to the command line terminal to 100 digits.
    std::cout.precision(100);

    // Set the number of digits of floating-point numbers which are printed to the file output stream to 100 digits.
    file.precision(100);

    /**
     * If the file named trigonometric_functions_output.txt does not already exist 
     * inside of the same file directory as the file named trigonometric_functions.cpp, 
     * create a new file named trigonometric_functions_output.txt in that directory.
     * 
     * Open the plain-text file named trigonometric_functions_output.txt
     * and set that file to be overwritten with program data.
     */
    file.open("trigonometric_functions_output.txt");

    file << "\n\nThis is just to generate the text file for now.";

    std::cout << "Enter an angle in radians: ";
    std::cin >> x;

    std::cout << "Sine: " << sine(x) << std::endl;
    std::cout << "Cosine: " << cosine(x) << std::endl;
    std::cout << "Tangent: " << tangent(x) << std::endl;

    std::cout << "Cotangent: " << cotangent(x) << std::endl;
    std::cout << "Secant: " << secant(x) << std::endl;
    std::cout << "Cosecant: " << cosecant(x) << std::endl;

    // Inverse trigonometric functions
    std::cout << "Arctangent: " << arctangent(x) << std::endl;
    if (x >= -1 && x <= 1) 
    {
        std::cout << "Arcsine: " << arcsine(x) << std::endl;
        std::cout << "Arccosine: " << arccosine(x) << std::endl;
    } 
    else 
    {
        std::cout << "Arcsine and Arccosine require a value between -1 and 1." << std::endl;
    }

    return 0;
}

/**
 *---------------------------------------------------------------------------------------
 * 
 * This function computes the approximate value of Pi using the Leibniz series.
 * 
 * Pi ≈ 4 * (1 - (1 / 3) + (1 / 5) - (1 / 7) + (1 / 9) - ...)
 * 
 *---------------------------------------------------------------------------------------
 * 
 * Pi is a mathematical constant that is the ratio of a circle's circumference to 
 * its diameter (which is approximately equal to 3.14159).
 * 
 * For more information on how to compute the approximate value of Pi
 * (using a Monte Carlo dart-throwing simulation in JavaScript), visit
 * the tutorial web page at the following Uniform Resource Locator:
 * 
 * https://karlinaobject.wordpress.com/pi_approximation/
 * 
 *---------------------------------------------------------------------------------------
 * 
 * iterations is assumed to be a nonnegative integer no larger than MAXIMUM_iteratons.
 * 
 *---------------------------------------------------------------------------------------
 */
double computePi(int iterations) 
{
    int i = 0;
    double pi = 0.0;
    double sign = 1.0; // alternates between positive and negative

    // Set iterations to 1 if the function input value is out or range. Then print a message about that change to the command line terminal.
    if ((iterations < 0) || (iterations > MAXIMUM_i)) 
    {
        iterations = 1;
        std::cout << "\n\nThe number of iterations for the Leibniz series in computePi(iterations) was out of range. Hence, iterations has been reset to 1.";
    }

    for (i = 0; i < iterations; ++i) 
    {
        pi += sign / (2.0 * i + 1.0); // add next term in the series
        sign = -sign; // alternate the sign for each term
    }

    pi *= 4.0; // multiply by 4 to get Pi
    return pi;
}

/**
 *----------------------------------------------------------------------------------------------------------------------------------------------
 * 
 * This function uses the Taylor series to compute the approximate value of sine of x (which is also expressed as sin(x)).
 * 
 * The value returned by this function is no smaller than -1 and no larger than 1:
 * 
 * -1 <= sin(x) <= 1
 * 
 *----------------------------------------------------------------------------------------------------------------------------------------------
 * 
 * The sine of an angle, x, in a right triangle is defined as the ratio of the length of 
 * the side opposite the angle to the length of the hypotenuse (the longest side of the triangle):
 * 
 * sin(x) = opposite / hypotenuse
 * 
 *----------------------------------------------------------------------------------------------------------------------------------------------
 * 
 * Note that an angle measurement in degrees can be converted to radians using the following formula:
 * 
 * radians = degrees * (Pi / 180)
 * 
 * If x is 30 degrees, then the right triangle it is the interior angle measurement of is a triangle
 * whose side opposite of x is 1 and whose hypotenuse is 2.
 * 
 * Hence, sine of 30 degrees can be computed as follows:
 * 
 * 30 degrees = Pi / 6 radians ≈ 0.5236
 * 
 * sin(0.5236) = 1 / 2 = 0.5
 *
 *----------------------------------------------------------------------------------------------------------------------------------------------
 * 
 * x is an angle measurement in radians and can theoretically be any real number (but is constrained to be in [(-1 * MAXIMUM_x), MAXIMUM_x]).
 * 
 *----------------------------------------------------------------------------------------------------------------------------------------------
 */
double sine(double x) 
{
    // Set x to 1 if the function input value is out or range. Then print a message about that change to the command line terminal.
    if ((x < (-1 * MAXIMUM_x)) || (x > MAXIMUM_x)) 
    {
        x = 1;
        std::cout << "\n\nThe number of radians, x, in sine(x) was out of range. Hence, x has been reset to 1.";
    }

    int i = 0;
    const int terms = MAXIMUM_t; // number of terms in the Taylor series
    double result = 0.0;
    double term = x; // first term: ((x ^ 1) / 1!)
    int sign = 1; // alternating signs for each term
    for (i = 1; i <= terms; i += 1) 
    {
        result += sign * term;
        sign *= -1; // alternating sign
        term *= x * x / (2 * i * (2 * i + 1)); // update term for the next iteration
    }
    return result;
}

/**
 *----------------------------------------------------------------------------------------------------------------------------------------------
 * 
 * This function uses the Taylor series to compute the approximate value of cosine of x (which is also expressed as cos(x)).
 * 
 * The value returned by this function is no smaller than -1 and no larger than 1:
 * 
 * -1 <= cos(x) <= 1
 * 
 *----------------------------------------------------------------------------------------------------------------------------------------------
 * 
 * The cosine of an angle, x, in a right triangle is defined as the ratio of the length of 
 * the side adjacent to the angle to the length of the hypotenuse (the longest side of the triangle):
 * 
 * cos(x) = adjacent / hypotenuse
 * 
 *----------------------------------------------------------------------------------------------------------------------------------------------
 * 
 * Note that an angle measurement in degrees can be converted to radians using the following formula:
 * 
 * radians = degrees * (Pi / 180)
 * 
 * If x is 60 degrees, then the right triangle it is the interior angle measurement of is a triangle
 * whose side adjacent to x is 1 and whose hypotenuse is 2.
 * 
 * Hence, cosine of 60 degrees can be computed as follows:
 * 
 * 60 degrees = Pi / 3 radians ≈ 1.047
 * 
 * cos(1.047) = 1 / 2 = 0.5
 * 
 *----------------------------------------------------------------------------------------------------------------------------------------------
 * 
 * x is an angle measurement in radians and can theoretically be any real number (but is constrained to be in [(-1 * MAXIMUM_x), MAXIMUM_x]).
 *
 *----------------------------------------------------------------------------------------------------------------------------------------------
 */
double cosine(double x) 
{
    // Set x to 1 if the function input value is out or range. Then print a message about that change to the command line terminal.
    if ((x < (-1 * MAXIMUM_x)) || (x > MAXIMUM_x)) 
    {
        x = 1;
        std::cout << "\n\nThe number of radians, x, in cosine(x) was out of range. Hence, x has been reset to 1.";
    }

    int i = 0;
    const int terms = MAXIMUM_t; // number of terms in the Taylor series
    double result = 1.0; // first term: ((x ^ 0) / 0!)
    double term = 1.0; 
    int sign = -1; // alternating signs for each term
    for (i = 1; i <= terms; ++i) 
    {
        term *= x * x / (2 * i * (2 * i - 1)); // update term for the next iteration
        result += sign * term;
        sign *= -1; // alternating sign
    }
    return result;
}

/**
 *-----------------------------------------------------------------------------------------------------------------------------------
 * 
 * This function computes the approximate value of tangent of x (which is also expressed as tan(x)).
 * 
 * The value returned by this function can theoretically be any real number:
 * 
 * tan(x) ∈ [-INFINITY, INFINITY]
 * 
 *-----------------------------------------------------------------------------------------------------------------------------------
 * 
 * The tangent of an angle, x, in a right triangle is defined as the ratio of the length of the side opposite 
 * the angle to the length of the adjacent side:
 * 
 * tan(x) = opposite / adjacent
 * 
 *-----------------------------------------------------------------------------------------------------------------------------------
 * 
 * x is an angle measurement in radians such that, theoretically speaking,
 * 
 * x = (((2 * n) + 1) * Pi) / 2 
 * 
 * where n is any integer
 * 
 * (but, in this program, x is allowed to be any integer in [(-1 * MAXIMUM_x), MAXIMUM_x]).
 * 
 * If x is within [(-1 * MAXIMUM_x), MAXIMUM_x] but not 
 * 
 * (((2 * n) + 1) * Pi) / 2 
 * 
 * where n is theoretically any integer,
 * 
 * then the output value returned by this function will be "not a number".
 * 
 * For example, if x = Pi /2, then tan(x) = "not a number".
 *
 *-----------------------------------------------------------------------------------------------------------------------------------
 */
double tangent(double x) 
{
    // Set x to 1 if the function input value is out or range. Then print a message about that change to the command line terminal.
    if ((x < (-1 * MAXIMUM_x)) || (x > MAXIMUM_x)) 
    {
        x = 1;
        std::cout << "\n\nThe number of radians, x, in tangent(x) was out of range. Hence, x has been reset to 1.";
    }

    return sine(x) / cosine(x);
}

/**
 *-----------------------------------------------------------------------------------------------------------------------------------
 * 
 * This function returns the reciprocal of the tangent function:
 * 
 * cotangent(x) = cot(x) = 1 / tan(x)
 * 
 *------------------------------------------------------------------------------------------------------------------------------------
 *
 * The value returned by this function can theoretically be any real number:
 * 
 * cot(x) ∈ [-INFINITY, INFINITY]
 * 
 *------------------------------------------------------------------------------------------------------------------------------------
 * 
 * x is an angle measurement in radians such that, theoretically speaking,
 * 
 * sin(x) != 0
 * 
 * (i.e. 
 * 
 * x != (Pi * n) 
 * 
 * where n is any integer)
 * 
 * (but, in this program, x is allowed to be any integer in [(-1 * MAXIMUM_x), MAXIMUM_x]).
 * 
 * If x is within [(-1 * MAXIMUM_x), MAXIMUM_x] but also
 * 
 * Pi * n 
 * 
 * where n is any integer
 * 
 * then the output value returned by this function will be "not a number".
 * 
 * For example, if x = Pi, then cot(x) = "not a number".
 * 
 *------------------------------------------------------------------------------------------------------------------------------------
 */
double cotangent(double x) 
{
    // Set x to 1 if the function input value is out or range. Then print a message about that change to the command line terminal.
    if ((x < (-1 * MAXIMUM_x)) || (x > MAXIMUM_x)) 
    {
        x = 1;
        std::cout << "\n\nThe number of radians, x, in cotangent(x) was out of range. Hence, x has been reset to 1.";
    }

    return 1.0 / tangent(x);
}

/**
 *------------------------------------------------------------------------------------------------------------------------------------
 * 
 * This function returns the reciprocal of the cosine function:
 * 
 * secant(x) = sec(x) = 1 / cos(x)
 *
 *------------------------------------------------------------------------------------------------------------------------------------
 */
double secant(double x) 
{
    // Set x to 1 if the function input value is out or range. Then print a message about that change to the command line terminal.
    if ((x < (-1 * MAXIMUM_x)) || (x > MAXIMUM_x)) 
    {
        x = 1;
        std::cout << "\n\nThe number of radians, x, in secantt(x) was out of range. Hence, x has been reset to 1.";
    }

    return 1.0 / cosine(x);
}

/**
 * This function returns the reciprocal of the sine function:
 * 
 * cosecant(x) = cos(x) = 1 / sin(x)
 */
double cosecant(double x) 
{
    // Set x to 1 if the function input value is out or range. Then print a message about that change to the command line terminal.
    if ((x < (-1 * MAXIMUM_x)) || (x > MAXIMUM_x)) 
    {
        x = 1;
        std::cout << "\n\nThe number of radians, x, in cosecant(x) was out of range. Hence, x has been reset to 1.";
    }

    return 1.0 / sine(x);
}

// Arctangent using the Taylor series (valid for -1 <= x <= 1)
double arctangent(double x) 
{
    // Set x to 1 if the function input value is out or range. Then print a message about that change to the command line terminal.
    if ((x < -1) || (x > 1)) 
    {
        x = 0;
        std::cout << "\n\nThe number of radians, x, in arctangent(x) was out of range. Hence, x has been reset to 0.";
    }

    const int terms = MAXIMUM_t; // Number of terms in the series
    double result = 0.0;
    double term = x; // First term
    int sign = 1; // Alternating signs for each term
    for (int i = 0; i < terms; ++i) 
    {
        result += sign * term;
        sign *= -1; // Alternating sign
        term *= x * x * (2 * i + 1) / (2 * i + 3); // Update term for the next iteration
    }
    return result;
}

// Arcsine using the Taylor series (valid for -1 <= x <= 1)
double arcsine(double x) 
{
    // Set x to 1 if the function input value is out or range. Then print a message about that change to the command line terminal.
    if ((x < -1) || (x > 1)) 
    {
        x = 0;
        std::cout << "\n\nThe number of radians, x, in arcsine(x) was out of range. Hence, x has been reset to 0.";
    }

    const int terms = MAXIMUM_t;
    double result = x;
    double term = x;
    for (int i = 1; i < terms; ++i) 
    {
        term *= (x * x * (2 * i - 1)) / (2 * i);
        result += term / (2 * i + 1);
    }
    return result;
}

// Arccosine is derived from arcsine: acos(x) = pi/2 - asin(x)
double arccosine(double x) 
{
    // Set x to 1 if the function input value is out or range. Then print a message about that change to the command line terminal.
    if ((x < -1) || (x > 1)) 
    {
        x = 0;
        std::cout << "\n\nThe number of radians, x, in arccosine(x) was out of range. Hence, x has been reset to 0.";
    }

    return computePi(MAXIMUM_i) / 2 - arcsine(x);  
}
