#include <vector>    // Include the vector header file for using vector container
#include <algorithm> // Include the algorithm header file for using algorithms like max
#include <cmath>     // Include the cmath header file for using mathematical functions like ceil

using namespace std; // Using the standard namespace to avoid having to prefix standard library elements

class Solution
{ // Declaration of a class named Solution
public:
    int findMax(vector<int> &piles)
    {                         // Definition of a function findMax which finds the maximum element in a vector
        int maxi = INT_MIN;   // Initialize the maximum variable to the smallest possible integer value
        int n = piles.size(); // Get the size of the vector
        for (int i = 0; i < n; i++)
        {                               // Loop through each element of the vector
            maxi = max(maxi, piles[i]); // Update the maximum variable if the current element is greater
        }
        return maxi; // Return the maximum value
    }

    long long calculateTotalHours(vector<int> &piles, int h)
    {                         // Definition of a function calculateTotalHours which calculates the total hours required to eat all piles
        long long totalH = 0; // Initialize the total hours variable
        int n = piles.size(); // Get the size of the vector
        for (int i = 0; i < n; i++)
        {                                                 // Loop through each element of the vector
            totalH += ceil((double)piles[i] / (double)h); // Add the hours required to eat the current pile to the total hours
        }
        return totalH; // Return the total hours
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {                                       // Definition of a function minEatingSpeed which finds the minimum eating speed to eat all piles within h hours
        int low = 1, high = findMax(piles); // Initialize low to 1 and high to the maximum pile size
        while (low <= high)
        {                                                       // While the search space is valid
            int mid = (low + high) / 2;                         // Calculate the mid value of the search space
            long long totalH = calculateTotalHours(piles, mid); // Calculate the total hours required to eat all piles at the mid speed
            if (totalH <= h)
            {                   // If total hours are less than or equal to h
                high = mid - 1; // Update high to mid - 1 (search in the lower half)
            }
            else
            {                  // If total hours are greater than h
                low = mid + 1; // Update low to mid + 1 (search in the upper half)
            }
        }
        return low; // Return the minimum eating speed found
    }
};

int main()
{
    // Example usage
    vector<int> piles = {3, 6, 7, 11};              // Define a vector containing pile sizes
    int h = 8;                                      // Define the total hours available
    Solution solution;                              // Create an instance of the Solution class
    int result = solution.minEatingSpeed(piles, h); // Call the minEatingSpeed function to find the minimum eating speed
    return 0;                                       // Return 0 to indicate successful execution
}
