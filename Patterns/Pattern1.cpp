#include <iostream>
using namespace std;
/*
* * *
* * *
* * *
*/


// Function definition of nForest
// This function prints a square pattern of asterisks '*' of size n x n
void nForest(int n) {
    // Outer loop runs 'n' times, once for each row
    for(int i = 0; i < n; i++) {
        // Inner loop runs 'n' times for each iteration of the outer loop, once for each column
        for(int j = 0; j < n; j++) {
            // Print an asterisk followed by a space without a newline,
            // this constructs a single row of asterisks
            cout << "* ";
        }
        // After printing 'n' asterisks in a row, print a newline character
        // This moves the cursor to the beginning of the next line (row)
        cout << endl;
    }
}

// Driver code to test the nForest function
int main() {
    // Example: Set the size of the square pattern
    int n = 5;

    // Call the nForest function with 'n' to print a 5x5 square of asterisks
    nForest(n);

    // Return 0 to indicate successful completion of the program
    return 0;
}
