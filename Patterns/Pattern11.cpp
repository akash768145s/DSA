#include <iostream>
using namespace std;
/*
1 
0 1
1 0 1
0 1 0 1
1 0 1 0 1
0 1 0 1 0 1
*/

void nBinaryTriangle(int n)
{
    int start = 1; // Initialize starting value for the pattern
    for (int i = 0; i <= n; i++)
    { // Outer loop to handle the number of rows
        if (i % 2 == 0)
            start = 1; // For even rows (including row 0), start with 1
        else
            start = 0; // For odd rows, start with 0

        for (int j = 0; j <= i; j++)
        { 
            // Inner loop to handle the number of values in each row

            cout << start << " "; // Print the current value of start followed by a space
            start = 1 - start;    // Toggle start between 1 and 0
        }
        cout << endl; // Move to the next line after finishing each row
    }
}

int main()
{
    int n = 5; // Example: height of the diamond's half
    nBinaryTriangle(n);
    return 0;
}