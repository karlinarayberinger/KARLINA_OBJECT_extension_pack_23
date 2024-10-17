#########################################################################################
# file: logarithm.py
# type: Python
# date: 16_OCTOBER_2024
# author: karbytes
# license: PUBLIC_DOMAIN 
#########################################################################################

# Constants for maximum values
MAXIMUM_x = 10000  # Define an appropriate maximum value for x.
MAXIMUM_logarithmic_base = 10000  # Define an appropriate maximum value for logarithmic_base.

#----------------------------------------------------------------------------------------
# If x is determined to be a whole number, return true.
# Otherwise, return false.
#----------------------------------------------------------------------------------------
def is_whole_number(x):
    return x == int(x)

#----------------------------------------------------------------------------------------
# Return the absolute value of a real number input, x.
#----------------------------------------------------------------------------------------
def absolute_value(x):
    if x < 0:
        return -1 * x
    return x

#----------------------------------------------------------------------------------------
# Return the approximate value of Euler's Number to the power of some real number x.
#----------------------------------------------------------------------------------------
def power_of_e_to_x(x):
    a = 1.0
    e = a
    n = 1
    invert = x < 0
    x = absolute_value(x)

    while e != e + a:
        a = a * x / n
        e += a
        n += 1

    return (1 / e) if invert else e

#-------------------------------------------------------------------------------------------------------------
# This function converts a floating-point number (float) into its bit (binary digit) representation.
#-------------------------------------------------------------------------------------------------------------
def float_to_bits(f):
    return int.from_bytes(bytearray(f.hex(), 'utf-8'), 'big')

#-------------------------------------------------------------------------------------------------------------
# This function converts a bit representation of a floating-point number back into its float representation.
#-------------------------------------------------------------------------------------------------------------
def bits_to_float(b):
    return float.fromhex(b.to_bytes(4, 'big').hex())

#-------------------------------------------------------------------------------------------------------------
# Return the approximate value of the natural logarithm of x.
# 
# The base of a natural logarithm (ln) is Euler's Number, e.
#  
# e is approximately equal to 2.71828182845904524019865766693015984856174327433109283447265625.
#-------------------------------------------------------------------------------------------------------------
def ln(x):
    bx = float_to_bits(x)
    ex = bx >> 23
    t = ex - 127
    s = -t if t < 0 else t
    bx = 1065353216 | (bx & 8388607)
    x = bits_to_float(bx)
    return -1.49278 + (2.11263 + (-0.729104 + 0.10969 * x) * x) * x + 0.6931471806 * t

#-------------------------------------------------------------------------------------------------------------
# This function returns the value of base raised to the power of exponent (i.e. base ^ exponent).
# Essentially, "base ^ exponent" is equivalent to saying "base multiplied by itself exponent times"."
#-------------------------------------------------------------------------------------------------------------
def power(base, exponent):
    output = 1.0
    if exponent == 0:
        return 1
    if exponent == 1:
        return base
    # if base == 0 and exponent < 0:
    #    return -666  # // Technically 0 raised to the power of some negative exponent is undefined (i.e. not a number).

    if is_whole_number(exponent):
        if exponent > 0:
            while exponent > 0:
                output *= base
                exponent -= 1
            return output
        else:
            exponent = absolute_value(exponent)
            while exponent > 0:
                output *= base
                exponent -= 1
            return 1 / output

    if exponent > 0:
        return power_of_e_to_x(ln(base) * exponent)

    return power_of_e_to_x(ln(base) * absolute_value(exponent))

#---------------------------------------------------------------------------------------------------------------------------------------------------------------------
# This function returns the result of the following calculation: 
# log_b(x) where log_b is the logarithmic function whose base is b (and where b is logarithmic_base).
# 
# A logarithm is the inverse of exponentiation. 
# 
# For example, ln(x) = y is the inverse of (e ^ y) = x 
# given that the logarithmic base of the function ln(x) is Euler's Number, e 
# (which is approximately equal to 2.71828182845904524019865766693015984856174327433109283447265625).
# 
# Another example of a logarithm is the following:
# log_2(16) = 4
# (which implies 4 ^ 2 = 16).
#
# Note that the base of a logarithm cannot be 1 because
# 
# log_1(x) = y implies (1 ^ y) = x only if x and y are identical and equal to 1.
# 
# log_1(2) = y implies (1 ^ y) = 2 when multiplying 1 by itself by any number of times should always yield the result 1; not 2 (or some other non-one number).
#---------------------------------------------------------------------------------------------------------------------------------------------------------------------
# As an aside, any non-zero number to the power of zero is one due to the following:
#
# Let a be any non-zero number. Then
# 
# (a ^ 3) = a * a * a
# 
# and 
# 
# (a ^ 2) = a * a
# 
# and 
# 
# (a ^ 1) = a.
# 
# Also, according to the rule of exponents, dividing a power by the base gives the next lower power. Hence,
#
# (a ^ 2) = (a ^ 3) / a = (a ^ 2)
# 
# and
#
# (a ^ 1) = (a ^ 2) / a
#
# and, similarly,
#
# (a ^ 0) = (a ^ 1) / a = a / a = 1.
#
# ((0 ^ 1) = 0 * 1 = 0 but (0 ^ 0) = (0 ^ 1) / 0 = 0 / 0 which is technically "not a number").
# 
# (Dividing a number by zero is theoretically impossible while multiplying that number by zero (which results in zero) 
# is theoretically possible because to say that some number is multiplied by zero is logically equivalent to saying 
# that number occurs zero times. By contrast, dividing some number by zero is logically equivalent to saying that
# number is compartmentalized into zero equally-sized parts (and none of those parts apparently have any non-zero size and
# infinitely many of such parts take up any space of any size (whether that size is zero or some positive quantity))).
#---------------------------------------------------------------------------------------------------------------------------------------------------------------------
#
# x is required to be a positive real number.
# 
# logarithmic_base is required to be a positive real number other than one.
#
# This function works by utilizing the following Change of Base (for Logarithms) formula:
#
# log_b = ln(x) / ln(b)
#---------------------------------------------------------------------------------------------------------------------------------------------------------------------
def logarithm(x, logarithmic_base):
    # Set x to 1 if it is out of range.
    if x <= 0 or x > MAXIMUM_x:
        x = 1
    
    # Set logarithmic_base to 2 if it is out of range.
    if logarithmic_base <= 0 or logarithmic_base == 1 or logarithmic_base > MAXIMUM_logarithmic_base:
        logarithmic_base = 2

    # Return ln(x) / ln(logarithmic_base).
    return ln(x) / ln(logarithmic_base)

#------------------------------------------------------------------------------------------------------------------------
# main function (prompts for user inputs, prints output messages to the command line terminal and to a text file)
#------------------------------------------------------------------------------------------------------------------------
def main():
    # Define three variables for storing floating-point numbers.
    x = 0.0
    logarithmic_base = 0.0
    result = 0.0

    # Variable to store whether or not to continue inputting values.
    input_additional_values = 1

    # Open a file to write program data. This will overwrite the file if it exists.
    with open("logarithm_output.txt", "w") as file:

        # Print opening message to the console and file.
        print("\n\n--------------------------------")
        print("Start Of Program")
        print("--------------------------------")

        file.write("--------------------------------\n")
        file.write("Start Of Program\n")
        file.write("--------------------------------\n")

        print("\n\nThis Python program computes the (approximate) logarithm of x in some given logarithmic base.")
        file.write("\n\nThis Python program computes the (approximate) logarithm of x in some given logarithmic base.\n")

        # Continue inputting values until the user specifies to stop.
        while input_additional_values != 0:

            # Print horizontal divider.
            print("\n\n--------------------------------")
            file.write("\n\n--------------------------------\n")

            # Prompt the user for input value of x.
            print(f"\n\nEnter a positive real number, x, to take the logarithm of and which is no larger than {MAXIMUM_x}: ")
            x = float(input())

            # Print the entered value of x.
            print(f"\nThe value which was entered for x is {x}.")
            file.write(f"\n\nThe value which was entered for x is {x}.\n")

            # Prompt the user for input value of logarithmic_base.
            print(f"\n\nEnter a positive real number, logarithmic_base, which is a positive real number other than one and which is no larger than {MAXIMUM_logarithmic_base}: ")
            logarithmic_base = float(input())

            # Print the entered value of logarithmic_base.
            print(f"\nThe value which was entered for logarithmic_base is {logarithmic_base}.")
            file.write(f"\n\nThe value which was entered for logarithmic_base is {logarithmic_base}.\n")

            # Validate x and logarithmic_base, and set defaults if necessary.
            if x <= 0 or x > MAXIMUM_x:
                x = 1
                print(f"\n\nDue to the fact that x was out of range, x was set to the default value 1.")
                file.write(f"\n\nDue to the fact that x was out of range, x was set to the default value 1.\n")

            if logarithmic_base <= 0 or logarithmic_base == 1 or logarithmic_base > MAXIMUM_logarithmic_base:
                logarithmic_base = 2
                print(f"\n\nDue to the fact that logarithmic_base was out of range, logarithmic_base was set to the default value 2.")
                file.write(f"\n\nDue to the fact that logarithmic_base was out of range, logarithmic_base was set to the default value 2.\n")

            # Compute the logarithm.
            result = logarithm(x, logarithmic_base)

            # Print the result of the logarithmic function.
            print(f"\n\nresult = logarithm(x, logarithmic_base) = logarithm({x}, {logarithmic_base}) = {result}.")
            file.write(f"\n\nresult = logarithm(x, logarithmic_base) = logarithm({x}, {logarithmic_base}) = {result}.\n")

            # Print the inverse of the logarithmic expression.
            print(f"\n\nx = logarithmic_base ^ result --> {x} = {logarithmic_base} ^ {result}.")
            print(f"\n\nx = power(logarithmic_base, result) = power({logarithmic_base}, {result}) = {power(logarithmic_base, result)}.")
            file.write(f"\n\nx = logarithmic_base ^ result --> {x} = {logarithmic_base} ^ {result}.\n")
            file.write(f"\n\nx = power(logarithmic_base, result) = power({logarithmic_base}, {result}) = {power(logarithmic_base, result)}.\n")

            # Ask the user whether to continue inputting values.
            print("\n\nWould you like to continue inputting program values? (Enter 1 if YES. Enter 0 if NO): ")
            input_additional_values = int(input())

        # Print closing message to the console and file.
        print("\n\n--------------------------------")
        print("End Of Program")
        print("--------------------------------\n\n")

        file.write("\n\n--------------------------------\n")
        file.write("End Of Program\n")
        file.write("--------------------------------\n")

# Run the main function.
main()
