/**
 * file: trigonometric_functions.cpp
 * type: C++ (source file)
 * date: 17_OCTOBER_2024
 * author: karbytes
 * license: PUBLIC_DOMAIN 
 */

/** preprocessing directives */
#include <iostream> // standard input (std::cin), standard output (std::cout)
#include <fstream> // file input, file output
#define MAXIMUM_t 10000 // constant which represents maximum number of terms in each Taylor series
#define MAXIMUM_x 10000 // constant which represents maximum value of x

/** function prototypes */
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
    double x;
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

// Function to compute sine using the Taylor series
double sine(double x) 
{
    const int terms = MAXIMUM_t; // Number of terms in the Taylor series
    double result = 0.0;
    double term = x; // First term (x^1 / 1!)
    int sign = 1; // Alternating signs for each term
    for (int i = 1; i <= terms; ++i) 
    {
        result += sign * term;
        sign *= -1; // Alternating sign
        term *= x * x / (2 * i * (2 * i + 1)); // Update term for the next iteration
    }
    return result;
}

// Function to compute cosine using the Taylor series
double cosine(double x) 
{
    const int terms = MAXIMUM_t; // Number of terms in the Taylor series
    double result = 1.0; // First term (x^0 / 0!)
    double term = 1.0; 
    int sign = -1; // Alternating signs for each term
    for (int i = 1; i <= terms; ++i) 
    {
        term *= x * x / (2 * i * (2 * i - 1)); // Update term for the next iteration
        result += sign * term;
        sign *= -1; // Alternating sign
    }
    return result;
}

// Tangent is sine / cosine
double tangent(double x) 
{
    return sine(x) / cosine(x);
}

// Cotangent is 1 / tangent
double cotangent(double x) 
{
    return 1.0 / tangent(x);
}

// Secant is 1 / cosine
double secant(double x) 
{
    return 1.0 / cosine(x);
}

// Cosecant is 1 / sine
double cosecant(double x) 
{
    return 1.0 / sine(x);
}

// Arctangent using the Taylor series (valid for -1 <= x <= 1)
double arctangent(double x) 
{
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
    return 3.14159265358979323846 / 2 - arcsine(x);  // Using pi = 3.14159265358979323846
}
