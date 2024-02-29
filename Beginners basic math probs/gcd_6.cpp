#include <iostream>

class Solution
{
    public:
    int gcd(int A, int B) 
    { 
        if (B == 0) 
            return A;
        return gcd(B, A % B);
    } 
};

int main() {
    Solution sol;
    int A, B;
    std::cout << "Enter two numbers to find their GCD: ";
    std::cin >> A >> B;
    std::cout << "The GCD of " << A << " and " << B << " is: " << sol.gcd(A, B) << std::endl;
    return 0;
}
