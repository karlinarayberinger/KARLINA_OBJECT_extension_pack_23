#########################################################################################
# file: logarithm.py
# type: Python
# date: 16_OCTOBER_2024
# author: karbytes
# license: PUBLIC_DOMAIN 
#########################################################################################

# Constants for maximum values
MAXIMUM_X = 10000
MAXIMUM_LOGARITHMIC_BASE = 10000
ITERATIONS = 100  # Number of iterations for series expansion

def power(base, exponent):
    """Calculate base raised to the power of exponent."""
    result = 1.0
    for _ in range(int(exponent)):
        result *= base
    return result

def ln(x):
    """Approximate natural logarithm (ln) using a series expansion."""
    if x <= 0:
        raise ValueError("ln(x) is undefined for x <= 0")
    if x == 1:
        return 0.0
    
    # Use series expansion for ln(x) around x = 1: ln(x) ≈ 2 * sum[(x - 1)/(x + 1)]^(2n + 1) / (2n + 1)
    if x > 1:
        z = (x - 1) / (x + 1)
    else:
        z = (x - 1) / (x + 1)
    
    result = 0.0
    for n in range(ITERATIONS):
        term = power(z, 2 * n + 1) / (2 * n + 1)
        result += term
    return 2 * result

def logarithm(x, logarithmic_base):
    """Calculate the logarithm of x to the given base using the change of base formula."""
    if x <= 0 or x > MAXIMUM_X:
        x = 1  # Default value if x is out of range
    if logarithmic_base <= 0 or logarithmic_base == 1 or logarithmic_base > MAXIMUM_LOGARITHMIC_BASE:
        logarithmic_base = 2  # Default value if base is out of range
    return ln(x) / ln(logarithmic_base)

def main():
    # Get user input
    x = float(input("Enter the value of x: "))
    logarithmic_base = float(input("Enter the value of the logarithmic base: "))

    # Calculate the result
    result = logarithm(x, logarithmic_base)

    # Print result with high precision
    print(f"\nThe logarithm of {x} with base {logarithmic_base} is approximately: {result:.100f}")

    # Write result to a file
    with open("logarithm_output.txt", "w") as file:
        file.write(f"The logarithm of {x} with base {logarithmic_base} is approximately: {result:.100f}\n")

# program entry point
if __name__ == "__main__":
    main()
