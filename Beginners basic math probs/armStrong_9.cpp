#include <iostream>
#include <cmath> // For pow() function
using namespace std;

class Solution {
public:
    string armstrongNumber(int n){
        int originalNumber = n;
        int sum = 0;
        int numberOfDigits = 0;
        
        // Step 1: Calculate the number of digits in n
        int temp = n;
        while (temp != 0) {
            temp /= 10;
            numberOfDigits++;
        }
        
        // Step 2: Calculate the sum of the dth powers of its digits
        temp = n;
        while (temp != 0) {
            int digit = temp % 10;
            sum += pow(digit, numberOfDigits);
            temp /= 10;
        }
        
        // Step 3: Check if the sum is equal to the original number
        if (sum == originalNumber) {
            return "Yes";
        } else {
            return "No";
        }
    }
};

int main() {
    Solution sol;
    
    int N = 153; // Example input
    cout << "Input: N = " << N << endl;
    cout << "Output: " << sol.armstrongNumber(N) << endl;
    
    N = 123; // Non-Armstrong number example
    cout << "Input: N = " << N << endl;
    cout << "Output: " << sol.armstrongNumber(N) << endl;
    
    return 0;
}
