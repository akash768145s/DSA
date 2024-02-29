#include <iostream>
using namespace std;


//Approach using Binary exponentiation

class Solution{
    public:
    const long long mod = 1000000007;
    
    long long power(int N,int R) {
        long long ans = 1; // Initialize result to 1.
        long long base = N % mod; // Calculate N modulo mod to handle large numbers.
        
        while (R > 0) {
            // If R is odd, multiply the current base with the answer and take modulo.
            if (R & 1)
                ans = (ans * base) % mod;
            
            // Square the base for the next iteration and take modulo.
            base = (base * base) % mod;
            R >>= 1; // Right shift R by 1 (equivalent to dividing by 2) for the next iteration.
        }
        return ans; // Return the computed power.
    }
};

int main() {
    Solution sol;
    int N, R;
    cout << "Enter the base (N) and the exponent (R): ";
    cin >> N >> R; // Input base and exponent from the user.
    cout << "The result of " << N << "^" << R << " under modulo " << sol.mod << " is: ";
    cout << sol.power(N, R) << endl; // Display the result of N^R modulo 1000000007.
    return 0;
}
