#include <iostream>
using namespace std;

// This represents a pointer to a function that takes and returns a double.
typedef double (*FUNC)(double);

// Function to perform integration using a while loop.
double integrate(FUNC f, double a, double b) {
    double sum = 0.0;
    double dx = 0.0001; // Width of each small rectangle
    double x = a;       // Start from point a

    while (x < b) {
        sum += f(x) * dx; // Add the area of each rectangle
        x += dx;          // Move to the next rectangle
    }

    return sum;
}

// Functions to test
double line(double x) { return x; }
double square(double x) { return x * x; }
double cube(double x) { return x * x * x; }

// Main function to run the program
int main() {
    cout << "The integral of f(x)=x between 1 and 5 is: " << integrate(line, 1, 5) << endl;
    cout << "The integral of f(x)=x^2 between 1 and 5 is: " << integrate(square, 1, 5) << endl;
    cout << "The integral of f(x)=x^3 between 1 and 5 is: " << integrate(cube, 1, 5) << endl;

    return 0;
}
