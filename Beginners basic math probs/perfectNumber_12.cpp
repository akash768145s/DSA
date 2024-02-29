#include <iostream>
using namespace std;

class Solution {
public:
    // Check if a number is a perfect number
    int isPerfectNumber(long long int n) {
        if (n <= 1) return 0;
        
        long long int sum = 1; // Start with 1 as a divisor
        for (long long int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                sum += i;
                if (i != n / i) sum += n / i; // Add the divisor pair
            }
        }
        
        if (sum == n) return 1; // The number is perfect
        else return 0; // The number is not perfect
    }
};

int main() {
    Solution solution;
    
    // Test the function with a known perfect number
    long long int num = 28;
    if (solution.isPerfectNumber(num) == 1) {
        cout << num << " is a perfect number." << endl;
    } else {
        cout << num << " is not a perfect number." << endl;
    }
    
    return 0;
}
