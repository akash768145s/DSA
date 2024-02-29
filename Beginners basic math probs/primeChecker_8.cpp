#include <iostream>

class PrimeChecker {
public:
    int isPrime(int N) {
        if (N <= 1) return 0; // Corrected return value for non-prime numbers
        for (int i = 2; i * i <= N; i++) {
            if (N % i == 0) return 0; // If divisible, N is not prime
        }
        return 1; // N is prime
    }
};

int main() {
    PrimeChecker checker;
    
    // Array of test numbers
    int testNumbers[] = {0, 1, 2, 3, 4, 5, 10, 13, 17, 19, 20, 25, 97, 100};
    int numTestNumbers = sizeof(testNumbers) / sizeof(testNumbers[0]);
    
    for (int i = 0; i < numTestNumbers; ++i) {
        int num = testNumbers[i];
        bool isPrime = checker.isPrime(num);
        std::cout << "Number " << num << " is " << (isPrime ? "prime." : "not prime.") << std::endl;
    }
    
    return 0;
}
