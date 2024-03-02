#include <iostream>
using namespace std;

/*
    *    
   ***
  *****
 *******
*********
*/

// Function to print a pyramid pattern
void printPyramid(int n) {
    // Outer loop for each row
    for(int i=0; i<n; i++) {
        // Print leading spaces
        // Spaces decrease as i increases
        for(int j=0; j<n-i-1; j++) {
            cout << " ";
        }
        // Print stars for the pyramid
        // The number of stars is odd for each row, starting with 1
        for(int j=0; j<2*i+1; j++) {
            cout << "*";
        }
        // Print trailing spaces
        // Not necessary for pyramid shape, but included for pattern consistency
        // This loop has the same condition as the first inner loop
        for(int j=0; j<n-i-1; j++) {
            cout << " ";
        }
        // Move to the next line after each row
        cout << endl;
    }
}

// Driver code
int main() {
    int n = 5; // Height of the pyramid
    printPyramid(n); // Call the function to print the pattern
    return 0; // Indicate successful completion
}
