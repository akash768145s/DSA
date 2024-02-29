#include <iostream>
using namespace std;

// Recursive function to calculate factorial of N
long long factorial(int N) {
    if(N == 0) {
        return 1; // Base case: 0! is 1
    } else {
        return N * factorial(N - 1); // Recursive case: N! = N * (N-1)!
    }
}

int main() {
    int number;
    cout << "Enter a number to calculate its factorial: ";
    cin >> number;

    long long fact = factorial(number);
    cout << "Factorial of " << number << " is " << fact << "." << endl;

    return 0;
}


