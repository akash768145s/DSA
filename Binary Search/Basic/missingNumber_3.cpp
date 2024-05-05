#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // Initialize xorAll with the size of the vector, which represents the 'n' value in the range [0, n]
        int xorAll = nums.size(); 
        for (int i = 0; i < nums.size(); i++) { // Iterate through the vector
            // Apply XOR operation with i (index) and nums[i] (element at index i) and accumulate the result in xorAll
            xorAll ^= i ^ nums[i];
        }
        // xorAll now holds the missing number due to properties of XOR operation
        return xorAll;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3,0,1}; // Example array with missing number 2
    cout << "The missing number is: " << solution.missingNumber(nums) << endl;
    // Output: The missing number is: 2
    return 0;
}

