#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// --- Function Prototypes ---

// 1. Input Side Lengths Function
void input_side_lengths(double *a, double *b, double *c);

// 2. Validate Triangle Function (called from display_results)
bool validate_triangle(double a, double b, double c);

// 3. Calculate Area Function (called from display_results)
double calculate_area(double a, double b, double c);

// 4. Display Results Function (main logic flow)
void display_results(void);


// =================================================================
// 1. Input Side Lengths Function
// Prompts the user for the three side lengths and stores them
void input_side_lengths(double *a, double *b, double *c) {
    printf("--- Input Side Lengths ---\n");
    printf("Enter the length of side a: ");
    scanf("%lf", a);
    printf("Enter the length of side b: ");
    scanf("%lf", b);
    printf("Enter the length of side c: ");
    scanf("%lf", c);
    printf("\n");
}

// -----------------------------------------------------------------
// 2. Validate Triangle Function
// Checks if the given lengths satisfy the triangle inequality theorem:
// The sum of any two sides must be greater than the third side.
bool validate_triangle(double a, double b, double c) {
    // Check for positive lengths and the triangle inequality
    if (a > 0 && b > 0 && c > 0 &&
        (a + b > c) &&
        (a + c > b) &&
        (b + c > a)) {
        return true;
    } else {
        return false;
    }
}

// -----------------------------------------------------------------
// 3. Calculate Area Function (using Heron's formula)
// Calculates the area of the triangle. ASSUMES the triangle is valid.
double calculate_area(double a, double b, double c) {
    // 1. Calculate the semi-perimeter (s)
    // s = (a + b + c) / 2
    double s = (a + b + c) / 2.0;

    // 2. Calculate the Area (A)
    // A = sqrt( s * (s - a) * (s - b) * (s - c) )
    double area = sqrt(s * (s - a) * (s - b) * (s - c));

    return area;
}

// -----------------------------------------------------------------
// 4. Display Results Function (The main driver function using a nested call structure)
// This function orchestrates the entire process: Input -> Validate -> Calculate/Display.
void display_results(void) {
    double side_a, side_b, side_c;

    // 1. Input Side Lengths (Calls function 1)
    input_side_lengths(&side_a, &side_b, &side_c);

    // 2. Validate Triangle (Calls function 2)
    bool is_valid = validate_triangle(side_a, side_b, side_c);

    printf("--- Validation and Results ---\n");

    if (is_valid) {
        // 3. Calculate Area (Calls function 3)
        double area = calculate_area(side_a, side_b, side_c);

        printf("Valid Triangle: **Yes**\n");
        printf("Area of the triangular garden: **%.2lf** square units\n", area);
    } else {
        printf("Valid Triangle: **No**\n");
        printf("Message: **The given lengths do not form a valid triangle.**\n");
    }
    printf("------------------------------\n");
}
// =================================================================


// The main function starts the program execution
int main() {
    // Call the main driver function to run the program
    display_results();

    // Test Case 1: a=3, b=4, c=5 -> Area 6.0
    // Test Case 2: a=1, b=2, c=8 -> Invalid

    return 0;
}
