#include <iostream>
using namespace std;

/*

* * * * * 
* * * *
* * *
* *
*

*/

// Function to print a decreasing pattern of asterisks
void seeding(int n) {
    // Loop through each row, starting from 1 up to n
    for(int i = 1; i <= n; i++) {
        // For each row 'i', print stars in a decreasing order
        // The number of stars in the current row is 'n-i+1'
        for(int j = 0; j < n - i + 1; j++) {
            cout << "* "; // Print a star followed by a space
        }
        cout << endl; // Move to the next line after each row
    }
}

// Driver code
int main() {
    int n = 5; // Example: total number of rows
    seeding(n); // Call the function to print the pattern
    return 0; // Indicate successful completion
}
