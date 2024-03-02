#include <iostream>
using namespace std;
/*
1       1
12     21
123   321
1234 4321
123454321
*/
void numberCrown(int n) {
    // Initial space before the numbers start to create the shape
    int space = 2 * (n - 1);

    for(int i = 1; i <= n; i++) {
        // Print ascending numbers from 1 to i
        for(int j = 1; j <= i; j++) {
            cout << j;
        }

        // Print spaces in the middle of the pattern
        for(int j = 1; j < space; j++) {
            cout << " ";
        }

        // Print descending numbers from i to 1
        for(int j = i; j >= 1; j--) {
            // Avoid printing the leading number twice at the apex of each line
            if(j != n) cout << j;
        }

        cout << endl; // Move to the next line after printing each row
        space -= 2; // Decrease the space by 2 for the next row
    }
}

int main() {
    int n = 5; // Example: the number of rows
    numberCrown(n);
    return 0;
}
