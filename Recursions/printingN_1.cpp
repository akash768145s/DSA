#include <iostream>
using namespace std;

void printNos(int N)
{
    if(N == 0)
    {
        return; // Base case: If N is 0, stop the recursion.
    }
    printNos(N-1); // Recursive call: Print numbers from 1 to N-1.
    cout << N << " "; // After returning from recursion, print the current number N.
}

int main() {
    int N = 10; // You can change this value to test with different numbers.
    
    cout << "Printing numbers from 1 to " << N << ":" << endl;
    printNos(N); // Call the function with the value of N.
    
    return 0;
}
