/*
A 
A B
A B C
A B C D
A B C D E
*/

#include <iostream>
using namespace std;

void nLetterTriangle(int n) {
    // Loop over each row
    for(int i=0;i<n;i++){
        // For each row, print characters from 'A' up to the character that corresponds to the current row
        for(char ch='A';ch<='A'+i;ch++){
            cout<<ch<<" "; // Print character followed by a space
        }
        cout<<endl; // Move to the next line after finishing each row
    }
}

int main() {
    int n = 5; // Example: the number of rows
    nLetterTriangle(n); // Call the function to print the letter triangle
    return 0;
}

