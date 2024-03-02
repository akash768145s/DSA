#include <iostream>
using namespace std;

/*

* 
* * 
* * * 
* * * *
* * * * *

*/
// Function definition of nForest
// This function prints a right-angled triangle pattern of asterisks '*'
// The triangle has 'n' rows, with each row having one more asterisk than the previous row
void nForest(int n) {
    // Outer loop runs 'n' times, once for each row
    for(int i = 0; i < n; i++) {
        // Inner loop: In each row, the number of asterisks printed is one more than the row number 'i'
        // Hence, it runs from 0 to 'i', inclusive
        for(int j = 0; j <= i; j++) {
            // Print an asterisk followed by a space without a newline,
            // constructing the current row of the triangle
            cout << "* ";
        }
        // After printing the required number of asterisks in a row, print a newline character
        // This moves the cursor to the beginning of the next line (row)
        cout << endl;
    }
}

// Driver code to test the nForest function
int main() {
    // Example: Set the height of the triangle
    int n = 5;

    // Call the nForest function with 'n' to print a right-angled triangle
    // with a height and base length of 5
    nForest(n);

    // Return 0 to indicate successful completion of the program
    return 0;
}
