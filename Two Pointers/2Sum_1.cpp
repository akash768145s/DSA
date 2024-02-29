#include <vector>
#include <map>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to find two numbers such that they add up to a specific target.
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mpp; // Create a map to store numbers and their indices.
        int n = nums.size(); // Get the size of the input vector.

        // Loop through all elements in the nums vector.
        for(int i = 0; i < n; i++) {
            int num = nums[i]; // Current number in the iteration.
            int moreNeeded = target - num; // Calculate the complement of the current number.

            // Check if the complement exists in the map.
            if(mpp.find(moreNeeded) != mpp.end()) {
                // If the complement is found, return the indices of the two numbers.
                return {mpp[moreNeeded], i};
            }

            // If the complement is not found, add the current number and its index to the map.
            // This is for future reference, in case we find a number which complements the current number.
            mpp[num] = i;
        }

        // If no such pair is found, return {-1, -1}.
        return {-1, -1};
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 7, 11, 15}; // Example input
    int target = 9;
    vector<int> result = solution.twoSum(nums, target);

    if (result[0] == -1 && result[1] == -1) {
        cout << "No two sum solution found." << endl;
    } else {
        cout << "Index: " << result[0] << " and " << result[1] << " (0-based indexing)" << endl;
    }

    return 0;
}

//Approach 2
/*

#include <vector>
#include <algorithm> // For std::sort
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0;
        int n = nums.size(); // Define n based on the size of nums
        int right = n - 1;
        sort(nums.begin(), nums.end());
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                // Correct the syntax for returning a vector
                return "Yes";
            }
            else if (sum < target) left++;
            else right--;
        }
        return "No";
    }
};

// Driver code
int main() {
    Solution solution;
    vector<int> nums = {2, 7, 11, 15}; // Example input
    int target = 9;
    vector<int> result = solution.twoSum(nums, target);
    
    // Print the result
    if (result[0] != -1) {
        cout << "Indices: " << result[0] << " and " << result[1] << endl;
    } else {
        cout << "No two sum solution found." << endl;
    }
    return 0;
}
*/

