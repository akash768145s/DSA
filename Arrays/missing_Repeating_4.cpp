#include <iostream>
#include <vector>
using namespace std;

//Approach 1: Using Basic Math

// Function declaration
vector<int> findMissingRepeatingNumbers(vector<int> a);

int main() {
    // Example input
    vector<int> input = {1, 3, 4, 5, 3};

    // Call the function
    vector<int> result = findMissingRepeatingNumbers(input);

    // Output the result
    cout << "Missing number: " << result[0] << ", Repeating number: " << result[1] << endl;

    return 0;
}

// Function definition
vector<int> findMissingRepeatingNumbers(vector<int> a) {
    long long n = a.size();

    long long SN = (n * (n + 1)) / 2;
    long long SN2 = (n * (n + 1) * (2 * n + 1)) / 6;
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++) {
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }
    long long val1 = S - SN;  // x - y
    long long val2 = S2 - SN2;  // x^2 - y^2
    val2 = val2 / val1;  // x + y
    long long x = (val1 + val2) / 2;
    long long y = x - val1;
    return {(int)x, int(y)};
}


