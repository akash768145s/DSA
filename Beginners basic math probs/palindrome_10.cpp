#include <iostream>
using namespace std;

class Solution
{
    public:
        string is_palindrome(int n)
        {
            string a = "Yes", b = "No";
            int original = n, rev = 0;
            while (n != 0) {
                rev = rev * 10 + n % 10;
                n = n / 10;
            }
            if (rev == original) {
                return a;
            } else {
                return b;
            }
        }
};

int main() {
    Solution solution;
    
    // Array of test numbers
    int testNumbers[] = {121, -121, 123, 456, 454, 0};
    
    // Loop through test numbers and check if they are palindrome
    for (int num : testNumbers) {
        string result = solution.is_palindrome(num);
        cout << "Number " << num << " is palindrome? " << result << endl;
    }
    
    return 0;
}
