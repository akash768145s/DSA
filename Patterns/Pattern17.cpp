#include <iostream>
using namespace std;
/*
    A
   A B A
  A B C B A
 A B C D C B A
A B C D E D C B A
*/

void alphaHill(int n)
{
    for (int i = 0; i < n; i++)
    {
        // Print leading spaces for the pyramid shape
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }

        char ch = 'A';
        int breakpoint = (2 * i + 1) / 2;
        // Print letters in ascending then descending order
        for (int j = 1; j <= 2 * i + 1; j++)
        {
            cout << ch << " ";
            if (j <= breakpoint)
                ch++; // Increase character until midpoint
            else
                ch--; // Decrease character after midpoint
        }

        // Print trailing spaces for symmetry
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl; // Move to the next line after each row
    }
}

int main()
{
    int n = 5;    // Example: height of the hill
    alphaHill(n); // Call the function to print the alphabet hill
    return 0;
}
