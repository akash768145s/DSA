#include <iostream>
using namespace std;

/*
E 
D E
C D E
B C D E
A B C D E
*/

void alphaTriangle(int n) {
    for(int i=0;i<n;i++){
        // Starting character changes in each row, moving backwards from 'E'
        for(char ch='E'-i;ch<='E';ch++){
            cout<<ch<<" "; // Print characters from current start to 'E'
        }
        cout<<endl; // Move to the next line after each row
    }
}

int main() {
    int n = 5; // Example: height of the triangle
    alphaTriangle(n); // Call the function to print the alphabet triangle
    return 0;
}
