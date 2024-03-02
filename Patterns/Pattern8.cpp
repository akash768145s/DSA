#include <iostream>
using namespace std;


/*
*********
 *******
  *****
   ***
    *
*/
void invertedPyramid(int n) {
    // Loop through each row from top (0) to bottom (n-1)
    for(int i = 0; i < n; i++) {
        // Print leading spaces
        // Number of spaces increases with each row
        for(int j = 0; j < i; j++) {
            cout << " ";
        }
        // Print stars to form the pyramid
        // Starts with 2*n-1 stars and decreases by 2 with each row
        for(int j = 0; j < 2*n - (2*i + 1); j++) {
            cout << "*";
        }
        // Print trailing spaces
        // These are symmetric to the leading spaces and are optional for the shape
        for(int j = 0; j < i; j++) {
            cout << " ";
        }
        // Move to the next line after each row
        cout << endl;
    }
}

// Driver code
int main() {
    int n = 5; // Example: height of the pyramid
    invertedPyramid(n); // Call the function to print the pattern
    return 0; // Indicate successful completion
}
