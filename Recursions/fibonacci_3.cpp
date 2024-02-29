#include <iostream>
using namespace std;

int nthFibonacci(int n){
    // Initial two Fibonacci numbers
    int n1 = 1, n2 = 1;
    
    // 'ans' will hold the final result, initialized to -1 as an invalid value
    int ans = -1;
    
    // For the first two Fibonacci numbers, return 1 directly
    if(n == 2 || n == 1) {
        return 1;
    }
    
    // Variable to store the next Fibonacci number
    int n3;
    
    // Loop to calculate n-th Fibonacci number
    for(int i = 2; i < n; i++) {
        // Calculate next Fibonacci number and apply modulo to avoid overflow
        n3 = (n1 + n2) % 1000000007;
        
        // Update 'ans' with the latest Fibonacci number
        ans = n3;
        
        // Shift n1 and n2 for the next iteration
        n1 = n2;
        n2 = n3;
    }
    
    // Return the n-th Fibonacci number
    return ans;
}

int main() {
    int n;
    cout << "Enter the value of n to find the nth Fibonacci number: ";
    cin >> n;
    
    cout << "The " << n << "th Fibonacci number is: " << nthFibonacci(n) << endl;
    
    return 0;
}
