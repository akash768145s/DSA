#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lenOfLongSubarr(int A[], int N, int K) {
        // Hash map to store the prefix sum and its corresponding index
        unordered_map<int, int> prefixSumIndex;
        int sum = 0; // Initialize sum of elements
        int maxLength = 0; // Initialize result

        // Iterate through the array
        for (int i = 0; i < N; i++) {
            sum += A[i]; // Add current element to sum
            
            // If sum is equal to K, update maxLength (i + 1 because subarray starts from index 0)
            if (sum == K) {
                maxLength = i + 1;
            }
            
            // If the sum is not found in the map, add it with its index
            if (prefixSumIndex.find(sum) == prefixSumIndex.end()) {
                prefixSumIndex[sum] = i;
            }
            
            // Check if (sum - K) is present in prefixSumIndex or not
            if (prefixSumIndex.find(sum - K) != prefixSumIndex.end()) {
                // If found, update maxLength if it's smaller than the current subarray length
                maxLength = max(maxLength, i - prefixSumIndex[sum - K]);
            }
        }
        
        // Return the result
        return maxLength;
    }
};

int main() {
    Solution solution;
    int A[] = {10, 5, 2, 7, 1, 9};
    int N = sizeof(A) / sizeof(A[0]);
    int K = 15;
    cout << "Length of the longest subarray: " << solution.lenOfLongSubarr(A, N, K) << endl;
    return 0;
}
