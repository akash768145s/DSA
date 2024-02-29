#include <iostream>
#include <vector>

std::vector<int> printDivisors(int n) {
    std::vector<int> divisors;
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
        }
    }
    return divisors;
}

int main() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    std::vector<int> divisors = printDivisors(n);
    std::cout << "Divisors of " << n << " are: ";
    for (int divisor : divisors) {
        std::cout << divisor << " ";
    }
    std::cout << std::endl;

    return 0;
}
