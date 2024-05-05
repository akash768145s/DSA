#include <iostream>
using namespace std;
/*
A 
B B
C C C
D D D D
E E E E E
*/


void alphaRamp(int n) {
    // Loop over each row
    for(int i=0; i<n; i++){
        // Determine the starting character for the current row
        char ch = 'A' + i;
        // Print the character 'ch' for each position in the row
        for(int j=0; j<=i; j++){
            cout << ch << " "; // Print the character followed by a space
        }
        cout << endl; // Move to the next line after completing each row
    }
}

int main() {
    int n = 5; // Example: height of the ramp
    alphaRamp(n); // Call the function to print the alphabet ramp
    return 0;
}
