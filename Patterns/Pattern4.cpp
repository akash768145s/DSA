#include <iostream>
using namespace std;
/*
1 
2 2
3 3 3
4 4 4 4
5 5 5 5 5
*/

// Function to print a triangle pattern where each row 'i' contains 'i' instances of the number 'i'
void nPattern(int n) {
    // Loop through each row
    for(int i = 1; i <= n; i++) {
        // For each row 'i', print the row number 'i', 'i' times
        for(int j = 1; j <= i; j++) {
            cout << i << " "; // Print the row number and a space
        }
        cout << endl; // Move to the next line after each row
    }
}

// Driver code
int main() {
    int n = 5; // Example height of the triangle
    nPattern(n); // Call the function to print the pattern
    return 0; // Indicate successful completion
}
