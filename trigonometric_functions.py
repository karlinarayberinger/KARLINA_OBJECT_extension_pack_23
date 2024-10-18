#########################################################################################
# file: trigonometric_functions.py
# type: Python
# date: 18_OCTOBER_2024
# author: karbytes
# license: PUBLIC_DOMAIN 
#########################################################################################

MAXIMUM_i = 10000 # constant which represents maximum number of iterations in Leibniz series
MAXIMUM_t = 10000 # constant which represents maximum number of terms in Taylor series
MAXIMUM_x = 10000 # constant which represents maximum value of x

#----------------------------------------------------------------------------------------------------------------------------------------------
# 
# This function computes the approximate value of Pi using the Leibniz series.
# 
# Pi ≈ 4 * (1 - (1 / 3) + (1 / 5) - (1 / 7) + (1 / 9) - ...)
# 
#----------------------------------------------------------------------------------------------------------------------------------------------
# 
# Pi is a mathematical constant that is the ratio of a circle's circumference to 
# its diameter (which is approximately equal to 3.14159).
# 
# For more information on how to compute the approximate value of Pi
# (using a Monte Carlo dart-throwing simulation in JavaScript), visit
# the tutorial web page at the following Uniform Resource Locator:
# 
# https://karlinaobject.wordpress.com/pi_approximation/
# 
#----------------------------------------------------------------------------------------------------------------------------------------------
# 
# iterations is assumed to be a nonnegative integer no larger than MAXIMUM_iterations.
# 
#----------------------------------------------------------------------------------------------------------------------------------------------
def compute_pi(iterations):
    pi = 0.0
    sign = 1.0  # alternates between positive and negative

    # If iterations is out of range, set it to 1 and print a message
    if iterations < 0 or iterations > MAXIMUM_i:  
        iterations = 1
        print("\n\nThe number of iterations for the Leibniz series in compute_pi(iterations) was out of range. Hence, iterations has been reset to 1.")

    for i in range(iterations):
        pi += sign / (2.0 * i + 1.0)  # Add the next term in the series
        sign = -sign  # Alternate the sign for each term

    pi *= 4.0  # Multiply by 4 to get Pi
    return pi

#----------------------------------------------------------------------------------------------------------------------------------------------
# 
# This function uses the Taylor series to compute the approximate value of sine of x (which is also expressed as sin(x)).
# 
# The value returned by this function is no smaller than -1 and no larger than 1:
# 
# -1 <= sin(x) <= 1
# 
#----------------------------------------------------------------------------------------------------------------------------------------------
# 
# The sine of an angle, x, in a right triangle is defined as the ratio of the length of 
# the side opposite the angle to the length of the hypotenuse (the longest side of the triangle):
# 
# sin(x) = opposite / hypotenuse
# 
#----------------------------------------------------------------------------------------------------------------------------------------------
# 
# Note that an angle measurement in degrees can be converted to radians using the following formula:
# 
# radians = degrees * (Pi / 180)
# 
# If x is 30 degrees, then the right triangle it is the interior angle measurement of is a triangle
# whose side opposite of x is 1 and whose hypotenuse is 2.
# 
# Hence, sine of 30 degrees can be computed as follows:
# 
# 30 degrees = Pi / 6 radians ≈ 0.5236
# 
# sin(0.5236) = 1 / 2 = 0.5
#
# ---------------------------------------------------------------------------------------------------------------------------------------------
# 
# x is an angle measurement in radians and can theoretically be any real number (but is constrained to be in [(-1 * MAXIMUM_x), MAXIMUM_x]).
# 
#----------------------------------------------------------------------------------------------------------------------------------------------
def sine(x):
    # If x is out of range, set it to 1 and print a message
    if x < -MAXIMUM_x or x > MAXIMUM_x:
        x = 1
        print("\n\nThe number of radians, x, in sine(x) was out of range. Hence, x has been reset to 1.")

    terms = MAXIMUM_t
    result = 0.0
    term = x  # First term: ((x ^ 1) / 1!)
    sign = 1  # Alternating signs for each term

    for i in range(1, terms + 1):
        result += sign * term
        sign *= -1  # Alternate sign
        term *= x * x / (2 * i * (2 * i + 1))  # Update term for the next iteration

    return result

#----------------------------------------------------------------------------------------------------------------------------------------------
# 
# This function uses the Taylor series to compute the approximate value of cosine of x (which is also expressed as cos(x)).
# 
# The value returned by this function is no smaller than -1 and no larger than 1:
# 
# -1 <= cos(x) <= 1
# 
#----------------------------------------------------------------------------------------------------------------------------------------------
# 
# The cosine of an angle, x, in a right triangle is defined as the ratio of the length of 
# the side adjacent to the angle to the length of the hypotenuse (the longest side of the triangle):
# 
# cos(x) = adjacent / hypotenuse
# 
#----------------------------------------------------------------------------------------------------------------------------------------------
# 
# Note that an angle measurement in degrees can be converted to radians using the following formula:
# 
# radians = degrees * (Pi / 180)
# 
# If x is 60 degrees, then the right triangle it is the interior angle measurement of is a triangle
# whose side adjacent to x is 1 and whose hypotenuse is 2.
# 
# Hence, cosine of 60 degrees can be computed as follows:
# 
# 60 degrees = Pi / 3 radians ≈ 1.047
# 
# cos(1.047) = 1 / 2 = 0.5
# 
#----------------------------------------------------------------------------------------------------------------------------------------------
# 
# x is an angle measurement in radians and can theoretically be any real number (but is constrained to be in [(-1 * MAXIMUM_x), MAXIMUM_x]).
# 
#----------------------------------------------------------------------------------------------------------------------------------------------
def cosine(x):
    # If x is out of range, set it to 1 and print a message
    if x < -MAXIMUM_x or x > MAXIMUM_x:
        x = 1
        print("\n\nThe number of radians, x, in cosine(x) was out of range. Hence, x has been reset to 1.")

    terms = MAXIMUM_t
    result = 1.0  # First term: ((x ^ 0) / 0!)
    term = 1.0
    sign = -1  # Alternating signs for each term

    for i in range(1, terms + 1):
        term *= x * x / (2 * i * (2 * i - 1))  # Update term for the next iteration
        result += sign * term
        sign *= -1  # Alternate sign

    return result

#-----------------------------------------------------------------------------------------------------------------------------------
# 
# This function computes the approximate value of tangent of x (which is also expressed as tan(x)).
# 
# The value returned by this function can theoretically be any real number:
# 
# tan(x) ∈ (-INFINITY, INFINITY)
# 
#-----------------------------------------------------------------------------------------------------------------------------------
# 
# The tangent of an angle, x, in a right triangle is defined as the ratio of the length of the side opposite 
# the angle to the length of the adjacent side:
# 
# tan(x) = opposite / adjacent
# 
#-----------------------------------------------------------------------------------------------------------------------------------
# 
# x is an angle measurement in radians such that, theoretically speaking,
# 
# x = (((2 * n) + 1) * Pi) / 2 
# 
# where n is any integer
# 
# (but, in this program function, x is allowed to be any integer in [(-1 * MAXIMUM_x), MAXIMUM_x]).
# 
# If x is within [(-1 * MAXIMUM_x), MAXIMUM_x] but 
# 
# x != (((2 * n) + 1) * Pi) / 2 
# 
# where n is theoretically any integer,
# 
# then the output value returned by this function will be "not a number".
# 
# For example, if x = Pi / 2, then tan(x) = "not a number".
#
#-----------------------------------------------------------------------------------------------------------------------------------
def tangent(x):
    # If x is out of range, set it to 1 and print a message
    if x < -MAXIMUM_x or x > MAXIMUM_x:
        x = 1
        print("\n\nThe number of radians, x, in tangent(x) was out of range. Hence, x has been reset to 1.")

    # Calculate tangent as sine(x) / cosine(x)
    sin_x = sine(x)
    cos_x = cosine(x)

    # Handle the case where cosine(x) is zero (i.e., x = (2n + 1) * Pi / 2)
    if cos_x == 0:
        print("\n\nTangent is undefined for x = (2n + 1) * Pi / 2, returning 'not a number'.")
        return float('nan')  # Return 'not a number'

    return sin_x / cos_x

#-----------------------------------------------------------------------------------------------------------------------------------
# 
# This function returns the reciprocal of the tangent function:
# 
# cotangent(x) = cot(x) = 1 / tan(x)
# 
#------------------------------------------------------------------------------------------------------------------------------------
#
# The value returned by this function can theoretically be any real number:
# 
# cot(x) ∈ (-INFINITY, INFINITY)
# 
#------------------------------------------------------------------------------------------------------------------------------------
# 
# x is an angle measurement in radians such that, theoretically speaking,
# 
# sin(x) != 0
# 
# (i.e.
# 
# x != (Pi * n)
# 
# where n is any integer)
# 
# (but, in this program function, x is allowed to be any integer in [(-1 * MAXIMUM_x), MAXIMUM_x]).
# 
# If x is within [(-1 * MAXIMUM_x), MAXIMUM_x] but also
# 
# x = Pi * n 
# 
# where n is any integer
# 
# then the output value returned by this function will be "not a number".
# 
# For example, if x = Pi, then cot(x) = "not a number".
# 
#----------------------------------------------------------------------------------------------------------------------------------------------
def cotangent(x):
    # If x is out of range, set it to 1 and print a message
    if x < -MAXIMUM_x or x > MAXIMUM_x:
        x = 1
        print("\n\nThe number of radians, x, in cotangent(x) was out of range. Hence, x has been reset to 1.")

    # Calculate the tangent of x
    tan_x = tangent(x)

    # Handle the case where sine(x) is zero (i.e., x = Pi * n), which makes tangent undefined
    if tan_x == 0:
        print("\n\nCotangent is undefined for x = Pi * n, returning 'not a number'.")
        return float('nan')  # Return 'not a number'

    return 1.0 / tan_x

#----------------------------------------------------------------------------------------------------------------------------------------------
# 
# This function returns the reciprocal of the cosine function:
# 
# secant(x) = sec(x) = 1 / cos(x)
#
#----------------------------------------------------------------------------------------------------------------------------------------------
# 
# The value returned by this function can theoretically be any real number less than or equal to -1 
# or else any real number greater than or equal to 1:
# 
# sec(x) ∈ (-INFINITY, -1] ∪ [1, INFINITY)
# 
#----------------------------------------------------------------------------------------------------------------------------------------------
# 
# x is an angle measurement in radians such that, theoretically speaking,
# 
# cos(x) != 0
# 
# (i.e. 
# 
# x != (((2 * n) + 1) * Pi) / 2
# 
# where n is any integer)
# 
# (but, in this program function, x is allowed to be any integer in [(-1 * MAXIMUM_x), MAXIMUM_x]).
# 
# If x is within [(-1 * MAXIMUM_x), MAXIMUM_x] but also
# 
# x = (((2 * n) + 1) * Pi) / 2
# 
# where n is any integer
# 
# then the output value returned by this function will be "not a number".
# 
# For example, if x = Pi / 2, then sec(x) = "not a number".
#
#----------------------------------------------------------------------------------------------------------------------------------------------
def secant(x):
    # If x is out of range, set it to 1 and print a message
    if x < -MAXIMUM_x or x > MAXIMUM_x:
        x = 1
        print("\n\nThe number of radians, x, in secant(x) was out of range. Hence, x has been reset to 1.")

    # Calculate the cosine of x
    cos_x = cosine(x)

    # Handle the case where cosine(x) is zero (i.e., x = (2n + 1) * Pi / 2)
    if cos_x == 0:
        print("\n\nSecant is undefined for x = (2n + 1) * Pi / 2, returning 'not a number'.")
        return float('nan')  # Return 'not a number'

    return 1.0 / cos_x

#----------------------------------------------------------------------------------------------------------------------------------------------
# 
# This function returns the reciprocal of the sine function:
# 
# cosecant(x) = csc(x) = 1 / sin(x)
#
#----------------------------------------------------------------------------------------------------------------------------------------------
# 
# The value returned by this function can theoretically be any real number less than or equal to -1 
# or else any real number greater than or equal to 1:
# 
# csc(x) ∈ (-INFINITY, -1] ∪ [1, INFINITY)
# 
#----------------------------------------------------------------------------------------------------------------------------------------------
# 
# x is an angle measurement in radians such that, theoretically speaking,
# 
# sin(x) != 0
# 
# (i.e.
# 
# x != (Pi * n)
# 
# where n is any integer)
# 
# (but, in this program function, x is allowed to be any integer in [(-1 * MAXIMUM_x), MAXIMUM_x]).
# 
# If x is within [(-1 * MAXIMUM_x), MAXIMUM_x] but also
# 
# x = Pi * n
# 
# where n is any integer
# 
# then the output value returned by this function will be "not a number".
# 
# For example, if x = Pi, then csc(x) = "not a number".
# 
#----------------------------------------------------------------------------------------------------------------------------------------------
def cosecant(x):
    # If x is out of range, set it to 1 and print a message
    if x < -MAXIMUM_x or x > MAXIMUM_x:
        x = 1
        print("\n\nThe number of radians, x, in cosecant(x) was out of range. Hence, x has been reset to 1.")

    # Calculate the sine of x
    sin_x = sine(x)

    # Handle the case where sine(x) is zero (i.e., x = Pi * n)
    if sin_x == 0:
        print("\n\nCosecant is undefined for x = Pi * n, returning 'not a number'.")
        return float('nan')  # Return 'not a number'

    return 1.0 / sin_x

#----------------------------------------------------------------------------------------------------------------------------------------------
# 
# This function returns the inverse of the tangent function using the Taylor series:
# 
# arctangent(x) = atan(x) = tan ^ -1 (x) != 1 / tan(x) = (tan(x)) ^ -1
# 
#----------------------------------------------------------------------------------------------------------------------------------------------
#
# The value returned by this function can theoretically be any real number less than or equal to (-1 * (Pi / 2))
# or any real number greater than or equal to (Pi / 2):
# 
# atan(x) ∈ [(-1 * (Pi / 2)), (Pi / 2)]
# 
#----------------------------------------------------------------------------------------------------------------------------------------------
# 
# x is an angle measurement in radians and can theoretically be any real number (but is constrained to be in [(-1 * MAXIMUM_x), MAXIMUM_x]).
# 
#----------------------------------------------------------------------------------------------------------------------------------------------
def arctangent(x):
    # If x is out of range, set it to 1 and print a message
    if x < -MAXIMUM_x or x > MAXIMUM_x:
        x = 1
        print("\n\nThe number of radians, x, in arctangent(x) was out of range. Hence, x has been reset to 1.")

    terms = 20  # Number of terms in the series, MAXIMUM_t placeholder
    result = 0.0
    term = x  # First term
    sign = 1  # Alternating signs for each term

    for i in range(terms):
        result += sign * term
        sign *= -1  # Alternate sign
        term *= x * x * (2 * i + 1) / (2 * i + 3)  # Update term for the next iteration

    return result

#----------------------------------------------------------------------------------------------------------------------------------------------
# 
# This function returns the inverse of the sine function using the Taylor series:
# 
# arcsine(x) = asin(x) = sin ^ -1 (x) != 1 / sin(x) = (sin(x)) ^ -1
# 
#----------------------------------------------------------------------------------------------------------------------------------------------
#
# The value returned by this function can theoretically be any real number less than or equal to (-1 * (Pi / 2))
# or any real number greater than or equal to (Pi / 2):
# 
# asin(x) ∈ [(-1 * (Pi / 2)), (Pi / 2)]
# 
#----------------------------------------------------------------------------------------------------------------------------------------------
# 
# x is an angle measurement in radians and is only valid if
# 
# x ∈ [-1, 1]
# 
# where x is a real number
# 
# (but, in this program, x can be in [(-1 * MAXIMUM_x), MAXIMUM_x]).
# 
# If x is out of range of [-1, 1], then asin(x) = "not a number".
# 
#----------------------------------------------------------------------------------------------------------------------------------------------
def arcsine(x):
    # Set x to 1 if the input is out of range, then print a message
    if x < -MAXIMUM_x or x > MAXIMUM_x:
        x = 1
        print("\n\nThe number of radians, x, in arcsine(x) was out of range. Hence, x has been reset to 1.")

    # If x is out of the valid range for arcsine (i.e., |x| > 1), return 'not a number'
    if x < -1 or x > 1:
        print("\n\nArcsine is undefined for |x| > 1, returning 'not a number'.")
        return float('nan')  # Return 'not a number'

    terms = MAXIMUM_t
    result = x
    term = x

    for i in range(1, terms):
        term *= (x * x * (2 * i - 1)) / (2 * i)  # Update term using the Taylor series formula
        result += term / (2 * i + 1)

    return result

#----------------------------------------------------------------------------------------------------------------------------------------------
# 
# This function returns the inverse of the cosine function using the following formula: acos(x) = pi/2 - asin(x)
# 
# arccosine(x) = acos(x) = cos ^ -1 (x) != 1 / cos(x) = (cos(x)) ^ -1
# 
#----------------------------------------------------------------------------------------------------------------------------------------------
# 
# The value returned by this function can theoretically be any real number less than or equal to 0
# or any real number greater than or equal to Pi:
# 
# acos(x) ∈ [0, Pi]
# 
#----------------------------------------------------------------------------------------------------------------------------------------------
# 
# x is an angle measurement in radians and is only valid if
# 
# x ∈ [-1, 1]
# 
# where x is a real number
# 
# (but, in this program, x can be in [(-1 * MAXIMUM_x), MAXIMUM_x]).
# 
# If x is out of range of [-1, 1], then acos(x) = "not a number".
# 
#----------------------------------------------------------------------------------------------------------------------------------------------
def arccosine(x):
    # If x is out of range, set it to 1 and print a message
    if x < -MAXIMUM_x or x > MAXIMUM_x:
        x = 1
        print("\n\nThe number of radians, x, in arccosine(x) was out of range. Hence, x has been reset to 1.")

    # If x is out of the valid range for arccosine (i.e., |x| > 1), return 'not a number'
    if x < -1 or x > 1:
        print("\n\nArccosine is undefined for |x| > 1, returning 'not a number'.")
        return float('nan')  # Return 'not a number'

    # Compute the approximate value of Pi 
    pi_value = compute_pi(MAXIMUM_i)

    # Return acos(x) using the formula: acos(x) = Pi/2 - arcsine(x)
    return pi_value / 2 - arcsine(x)

#----------------------------------------------------------------------------------------------------------------------------------------------
#
# main function (prompts for user inputs, prints output messages to the command line terminal and to a text file)
#
#----------------------------------------------------------------------------------------------------------------------------------------------
def main():
    # Define one float type variable for storing a floating-point number value.
    x = 0.0

    # Declare a variable for storing the user's answer of whether to continue inputting values.
    input_additional_values = 1

    # Open a file to write the output to.
    with open("trigonometric_functions_output.txt", "w") as file:
        # Print opening message to the console and file.
        print("\n\n--------------------------------")
        print("Start Of Program")
        print("--------------------------------")

        file.write("--------------------------------\n")
        file.write("Start Of Program\n")
        file.write("--------------------------------\n")

        # Print program information to the console and file.
        print("\n\nThis Python program computes sine, cosine, tangent, cotangent, secant, cosecant, arctangent, arcsine, and arccosine of some angle measurement in radians, x.")
        file.write("\n\nThis Python program computes sine, cosine, tangent, cotangent, secant, cosecant, arctangent, arcsine, and arccosine of some angle measurement in radians, x.\n")

        # Execute the code in the loop until the user wants to stop.
        while input_additional_values != 0:
            # Print a horizontal divider line to the console and file.
            print("\n\n--------------------------------")
            file.write("\n\n--------------------------------\n")

            # Prompt the user to enter a value for x and get input.
            x = float(input(f"\n\nEnter a real number of radians, x, to input into trigonometric functions which is no smaller than {-MAXIMUM_x} and no larger than {MAXIMUM_x}: "))
            file.write(f"\n\nEnter a real number of radians, x, to input into trigonometric functions which is no smaller than {-MAXIMUM_x} and no larger than {MAXIMUM_x}: {x}\n")

            # Print the entered value of x to the console and file.
            print(f"\nThe value which was entered for x is {x}.")
            file.write(f"\nThe value which was entered for x is {x}.\n")

            # Print and log trigonometric function results.
            functions = [
                ("sine", sine(x)),
                ("cosine", cosine(x)),
                ("tangent", tangent(x)),
                ("cotangent", cotangent(x)),
                ("secant", secant(x)),
                ("cosecant", cosecant(x)),
                ("arctangent", arctangent(x)),
                ("arcsine", arcsine(x)),
                ("arccosine", arccosine(x))
            ]

            for name, result in functions:
                print(f"\n{name}(x) = {result}.")
                file.write(f"\n{name}(x) = {result}.\n")

            # Ask the user if they want to continue inputting values.
            input_additional_values = int(input("\n\nWould you like to continue inputting program values? (Enter 1 if YES. Enter 0 if NO): "))

        # Print a closing message to the console and file.
        print("\n\n--------------------------------")
        print("End Of Program")
        print("--------------------------------\n\n")

        file.write("\n\n--------------------------------\n")
        file.write("End Of Program\n")
        file.write("--------------------------------\n")

# Run the main function.
main()








