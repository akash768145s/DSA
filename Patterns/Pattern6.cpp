#include <iostream>
using namespace std;
/*
1 2 3 4 5 
1 2 3 4
1 2 3
1 2
1
*/


// Function to print a decreasing numerical pattern
void decreasingNumbers(int n) {
    // Loop through each row, from 1 to n
    for(int i = 1; i <= n; i++) {
        // For each row 'i', print numbers starting from 1 up to 'n-i+1'
        for(int j = 1; j <= n - i + 1; j++) {
            cout << j << " "; // Print the number followed by a space
        }
        cout << endl; // Move to the next line after completing each row
    }
}

// Driver code
int main() {
    int n = 5; // Example: total number of rows
    decreasingNumbers(n); // Call the function to print the pattern
    return 0; // Indicate successful completion
}
