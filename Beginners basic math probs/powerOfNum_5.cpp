#include <iostream>
using namespace std;

class Solution{
    public:
    // Assuming mod is a known constant. For example, a common value for mod is 1e9+7 (1000000007)
    const long long mod = 1000000007;
    
    long long power(int N,int R) {
        long long ans = 1; // Initialize result
        long long base = N % mod; // Update N if it is more than or equal to mod
        
        while (R > 0) {
            // If R is odd, multiply base with result
            if (R & 1)
                ans = (ans * base) % mod;
            
            // N must be squared and R must be halved for next iteration
            base = (base * base) % mod;
            R >>= 1;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int N, R;
    cout << "Enter base (N) and exponent (R): ";
    cin >> N >> R;
    cout << "Result of " << N << "^" << R << " under modulo " << sol.mod << " is: " << sol.power(N, R) << endl;
    return 0;
}
