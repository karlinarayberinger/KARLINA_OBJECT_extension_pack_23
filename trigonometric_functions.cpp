/**
 * file: trigonometric_functions.cpp
 * type: C++ (source file)
 * date: 17_OCTOBER_2024
 * author: karbytes
 * license: PUBLIC_DOMAIN 
 */

#include <iostream>

// Function to compute sine using the Taylor series
double sine(double x) {
    const int terms = 10; // Number of terms in the Taylor series
    double result = 0.0;
    double term = x; // First term (x^1 / 1!)
    int sign = 1; // Alternating signs for each term
    for (int i = 1; i <= terms; ++i) {
        result += sign * term;
        sign *= -1; // Alternating sign
        term *= x * x / (2 * i * (2 * i + 1)); // Update term for the next iteration
    }
    return result;
}

// Function to compute cosine using the Taylor series
double cosine(double x) {
    const int terms = 10; // Number of terms in the Taylor series
    double result = 1.0; // First term (x^0 / 0!)
    double term = 1.0; 
    int sign = -1; // Alternating signs for each term
    for (int i = 1; i <= terms; ++i) {
        term *= x * x / (2 * i * (2 * i - 1)); // Update term for the next iteration
        result += sign * term;
        sign *= -1; // Alternating sign
    }
    return result;
}

// Tangent is sine / cosine
double tangent(double x) {
    return sine(x) / cosine(x);
}

// Cotangent is 1 / tangent
double cotangent(double x) {
    return 1.0 / tangent(x);
}

// Secant is 1 / cosine
double secant(double x) {
    return 1.0 / cosine(x);
}

// Cosecant is 1 / sine
double cosecant(double x) {
    return 1.0 / sine(x);
}

int main() {
    double x;
    std::cout << "Enter an angle in radians: ";
    std::cin >> x;

    std::cout << "Sine: " << sine(x) << std::endl;
    std::cout << "Cosine: " << cosine(x) << std::endl;
    std::cout << "Tangent: " << tangent(x) << std::endl;
    std::cout << "Cotangent: " << cotangent(x) << std::endl;
    std::cout << "Secant: " << secant(x) << std::endl;
    std::cout << "Cosecant: " << cosecant(x) << std::endl;

    return 0;
}
