#include <iostream>
using namespace std;
/*
A B C D E 
A B C D
A B C
A B
A
*/
void nLetterTriangle(int n) {
    // Loop over each row
    for(int i=0;i<n;i++){
        // For each row, print characters from 'A' up to 'A' + (n-i-1)
        for(char ch='A'; ch<='A'+(n-i-1); ch++){
            cout<<ch<<" "; // Print the character followed by a space
        }
        cout<<endl; // Move to the next line after finishing each row
    }
}

int main() {
    int n = 5; // Example: the number of rows
    nLetterTriangle(n); // Call the function to print the inverted letter triangle
    return 0;
}
