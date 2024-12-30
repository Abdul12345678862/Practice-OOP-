#include <iostream>  // Include the header file for input/output operations
using namespace std;  // Use the standard namespace to avoid prefixing std::

// Class definition for Polynomial
class Polynomial {
private:
    int totalTerms;     // Number of terms in the polynomial
    int* coeff;         // Pointer to an array of coefficients
    int* exp;           // Pointer to an array of exponents

public:
    // Constructor: Initializes a polynomial with given coefficients and exponents
    Polynomial(int terms, int* coefficients, int* exponents) {
        totalTerms = terms;  // Set the number of terms in the polynomial
        coeff = new int[terms];  // Dynamically allocate memory for coefficients
        exp = new int[terms];    // Dynamically allocate memory for exponents
        
        // Copy the provided coefficients and exponents to the object's arrays
        for (int i = 0; i < terms; ++i) {
            coeff[i] = coefficients[i];
            exp[i] = exponents[i];
        }
    }

    // Destructor: Cleans up dynamically allocated memory when a Polynomial object is destroyed
    ~Polynomial() {
        delete[] coeff;  // Free the memory used for coefficients
        delete[] exp;    // Free the memory used for exponents
    }

    // Copy Constructor: Creates a new Polynomial by copying from another Polynomial object
    Polynomial(const Polynomial& other) {
        totalTerms = other.totalTerms;  // Copy the total number of terms
        coeff = new int[totalTerms];  // Dynamically allocate memory for coefficients
        exp = new int[totalTerms];    // Dynamically allocate memory for exponents
        
        // Copy the coefficients and exponents from the other Polynomial object
        for (int i = 0; i < totalTerms; ++i) {
            coeff[i] = other.coeff[i];
            exp[i] = other.exp[i];
        }
    }

    // Assignment Operator: Assigns one Polynomial object to another
    Polynomial& operator=(const Polynomial& other) {
        if (this != &other) {  // Check for self-assignment
            delete[] coeff;  // Free the old memory for coefficients
            delete[] exp;    // Free the old memory for exponents

            totalTerms = other.totalTerms;  // Set the number of terms
            coeff = new int[totalTerms];  // Allocate new memory for coefficients
            exp = new int[totalTerms];    // Allocate new memory for exponents

            // Copy the coefficients and exponents from the other Polynomial object
            for (int i = 0; i < totalTerms; ++i) {
                coeff[i] = other.coeff[i];
                exp[i] = other.exp[i];
            }
        }
        return *this;  // Return the current object to allow chained assignment
    }

    // Print function: Displays the polynomial in the form of terms
    void Print() {
        for (int i = 0; i < totalTerms; ++i) {
            if (i > 0 && coeff[i] > 0) {  // Add a "+" sign if the coefficient is positive and it's not the first term
                cout << "+";  
            }
            cout << coeff[i] << "x^" << exp[i] << " ";  // Print the term (coefficient and exponent)
        }
        cout << endl;  // Print a newline after all terms are printed
    }

    // Add function: Adds two polynomials and returns the result as a new Polynomial object
    Polynomial Add(const Polynomial& other) {
        int maxTerms = totalTerms + other.totalTerms;  // Maximum possible terms after addition
        int* resultCoeff = new int[maxTerms];  // Array for storing result coefficients
        int* resultExp = new int[maxTerms];    // Array for storing result exponents
        int resultSize = 0;  // Counter for the number of terms in the result polynomial

        int i = 0, j = 0;  // Pointers for iterating through both polynomials

        // Merge the two polynomials, combining terms with the same exponent
        while (i < totalTerms && j < other.totalTerms) {
            if (exp[i] > other.exp[j]) {  // If the current exponent in P1 is greater than P2
                resultCoeff[resultSize] = coeff[i];  // Copy the coefficient from P1
                resultExp[resultSize] = exp[i];      // Copy the exponent from P1
                ++i;  // Move to the next term in P1
            } else if (exp[i] < other.exp[j]) {  // If the current exponent in P2 is greater than P1
                resultCoeff[resultSize] = other.coeff[j];  // Copy the coefficient from P2
                resultExp[resultSize] = other.exp[j];      // Copy the exponent from P2
                ++j;  // Move to the next term in P2
            } else {  // If both exponents are the same, add the coefficients
                resultCoeff[resultSize] = coeff[i] + other.coeff[j];  // Add coefficients
                resultExp[resultSize] = exp[i];  // Copy the exponent (both are the same)
                ++i;  // Move to the next term in P1
                ++j;  // Move to the next term in P2
            }
            ++resultSize;  // Increment the result size
        }

        // If there are remaining terms in P1, add them to the result
        while (i < totalTerms) {
            resultCoeff[resultSize] = coeff[i];
            resultExp[resultSize] = exp[i];
            ++i;
            ++resultSize;
        }

        // If there are remaining terms in P2, add them to the result
        while (j < other.totalTerms) {
            resultCoeff[resultSize] = other.coeff[j];
            resultExp[resultSize] = other.exp[j];
            ++j;
            ++resultSize;
        }

        // Create a new polynomial from the result arrays
        Polynomial result(resultSize, resultCoeff, resultExp);

        // Clean up the temporary arrays to prevent memory leaks
        delete[] resultCoeff;
        delete[] resultExp;

        return result;  // Return the result polynomial
    }
};

// Main function: Entry point of the program
int main() {
    // Initialize the coefficients and exponents for Polynomial P1
    int coeff_P1[] = {1, 2, 5};   // Coefficients for P1 (1x^4 + 2x^2 + 5x^0)
    int exp_P1[] = {4, 2, 0};      // Exponents for P1

    // Initialize the coefficients and exponents for Polynomial P2
    int coeff_P2[] = {4, 3};       // Coefficients for P2 (4x^6 + 3x^2)
    int exp_P2[] = {6, 2};         // Exponents for P2

    // Create Polynomial P1 with 3 terms (1x^4 + 2x^2 + 5x^0)
    Polynomial P1(3, coeff_P1, exp_P1);  
    // Create Polynomial P2 with 2 terms (4x^6 + 3x^2)
    Polynomial P2(2, coeff_P2, exp_P2);  

    // Print Polynomial P1
    cout << "P1 = "; 
    P1.Print();  // Expected output: 1x^4 + 2x^2 + 5x^0

    // Print Polynomial P2
    cout << "P2 = "; 
    P2.Print();  // Expected output: 4x^6 + 3x^2

    // Add P1 and P2, and store the result in Polynomial P3
    Polynomial P3 = P1.Add(P2);   
    // Print the result of the addition
    cout << "P3 = "; 
    P3.Print();  // Expected output: 4x^6 + 1x^4 + 5x^2 + 5x^0

    // Assign Polynomial P1 to Polynomial P3
    P3 = P1;  
    // Print the result of the assignment
    cout << "P3 = "; 
    P3.Print();  // Expected output: 1x^4 + 2x^2 + 5x^0

    return 0;  // End of the program
}
