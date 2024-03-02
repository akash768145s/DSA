#include <iostream>
using namespace std;
/*
1 
2 3
4 5 6
7 8 9 10
11 12 13 14 15
*/

void nNumberTriangle(int n) {
    int num = 1; // Initialize num to 1, which will be used to print numbers in the triangle.
    for(int i = 1; i <= n; i++) { // Outer loop for each row, from 1 to n.
        for(int j = 1; j <= i; j++) { // Inner loop for printing numbers in each row.
            cout << num << " "; // Print the current number followed by a space.
            num = num + 1; // Increment num for the next number to be printed.
        }
        cout << endl; // After printing all numbers in a row, move to the next line.
    }
}

int main() {
    int n = 5; // Example: Define the number of rows for the triangle
    nNumberTriangle(n); // Call the function to print the number triangle.
    return 0;
}

