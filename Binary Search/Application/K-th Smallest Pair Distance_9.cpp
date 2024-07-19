#include <vector>    // Include the vector header for vector container
#include <algorithm> // Include the algorithm header for sorting
#include <iostream>
using namespace std;
class Solution
{
public:
    // Function to find the kth smallest distance among all pairs
    int smallestDistancePair(vector<int> &nums, int k)
    {
        // Sort the input vector in non-decreasing order
        sort(nums.begin(), nums.end());

        // Initialize variables for binary search
        int left = 0;
        int right = nums[nums.size() - 1] - nums[0];

        // Binary search loop to find the smallest distance
        while (left < right)
        {
            // Calculate the middle value
            int mid = (left + right) / 2;
            // Check if the count of pairs with distance <= mid is greater than or equal to k
            if (isSmallPairs(nums, k, mid))
                right = mid; // If true, update the right boundary
            else
                left = mid + 1; // If false, update the left boundary
        }
        return left; // Return the smallest distance found
    }

private:
    // Helper function to check if count of pairs with distance <= mid is >= k
    bool isSmallPairs(vector<int> &nums, int k, int mid)
    {
        int count = 0, left = 0;

        // Iterate through the array to count pairs with distance <= mid
        for (int right = 0; right < nums.size(); right++)
        {
            // Move the left pointer until distance between right and left is <= mid
            while (nums[right] - nums[left] > mid)
                left++;
            // Increment count by the number of valid pairs found
            count += right - left;
        }
        // Return true if count is >= k, indicating enough pairs found with distance <= mid
        return count >= k;
    }
};

// Driver code
int main()
{
    // Create an instance of the Solution class
    Solution solution;
    // Example input vector
    vector<int> nums = {1, 3, 1};
    // Example value of k
    int k = 1;
    // Call the function to find the kth smallest distance
    int result = solution.smallestDistancePair(nums, k);
    // Output the result
    cout << "The kth smallest distance is: " << result << endl;
    return 0;
}
