#include <iostream>
using namespace std;
/*
    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *
*/

//combination both pattern 7,8



void printDiamond(int n) {
    // Ascending part of the diamond
    for(int i=0; i<n; i++) {
        // Print leading spaces
        for(int j=0; j<n-i-1; j++) {
            cout << " ";
        }
        // Print stars for the pyramid
        for(int j=0; j<2*i+1; j++) {
            cout << "*";
        }
        // Move to the next line after each row
        cout << endl;
    }

    // Descending part of the diamond
    for(int i=n-2; i>=0; i--) { 
        // Start from the second last row and go upwards
        // Print leading spaces
        for(int j=0; j<n-i-1; j++) {
            cout << " ";
        }
        // Print stars for the pyramid
        for(int j=0; j<2*i+1; j++) {
            cout << "*";
        }
        // Move to the next line after each row
        cout << endl;
    }
}

int main() {
    int n = 5; // Example: height of the diamond's half
    printDiamond(n);
    return 0;
}
