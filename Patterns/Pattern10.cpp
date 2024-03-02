#include <iostream>
using namespace std;

/*
*
**
***
****
*****
****
***
**
*
*/

void printDiamond(int n) {
    // Loop through rows from 0 to 2*n - 1
    for(int i=0;i<=2*n-1;i++){
        // Calculate the number of stars for the current row
        // The calculation attempts to create a diamond pattern, but due to the logic,
        // it doesn't decrease the star count correctly in the second half.
        int stars=i;
        
        if(i>n) stars=2*n-i;
        //breaking the pattern here

        // Print stars for the current row based on the calculated count
        for(int j=1;j<=stars;j++){
            cout<<"*";
        }
        // Move to the next line after printing stars for the current row
        cout<<endl;
    }
}

int main() {
    int n = 5; // Example: height of the diamond's half
    printDiamond(n); // Call the function to print the diamond pattern
    return 0; // End of the program
}
