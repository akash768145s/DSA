#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(vector<int> arr, int n) {
    long long sum = 0; // Current sum of the subarray
    long long maxi = arr[0]; // Initialize maxi to the first element

    for(int i = 0; i < n; i++) {
        sum += arr[i]; // Add current element to sum
        maxi = max(maxi, sum); // Update maxi if current sum is greater than maxi
        if(sum < 0) sum = 0; // Reset sum to 0 if it becomes negative
    }
    return maxi > 0 ? maxi : 0; // Ensure non-negative output
}

int main() {
    vector<int> arr = {-7, -8, -16, 4, 8, -5, -7, -11, -10, -12, -4, -6, -4, -6, 10}; // Example array
    int n = arr.size(); // Size of the array
    cout << "Maximum Subarray Sum is: " << maxSubarraySum(arr, n) << endl;
    return 0;
}
