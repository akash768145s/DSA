#include <iostream>
using namespace std;
/*
1 
1 2
1 2 3
1 2 3 4
1 2 3 4 5
*/

// Function to print a numerical triangle of height 'n'
void nTriangle(int n) {
    // Loop through each row
    for(int i = 1; i <= n; i++) {
        // For each row 'i', print numbers from 1 to 'i'
        for(int j = 1; j <= i; j++) {
            cout << j << " "; // Print the number and a space
        }
        cout << endl; // Move to the next line after each row
    }
}

// Driver code
int main() {
    int n = 5; // Example height of the triangle
    nTriangle(n); // Call the function to print the triangle
    return 0; // Indicate successful completion
}
