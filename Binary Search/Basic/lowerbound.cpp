#include <iostream>
#include <vector>
using namespace std;

// Function to find the lower bound of x in a sorted array arr
int lowerBound(vector<int> arr, int n, int x)
{
    int low = 0, high = n - 1;
    int ans = n; // Initialize answer to n, indicating x is larger than all elements if not updated
    while (low <= high)
    {
        int mid = (low + high) / 2; // Find the middle index
        if (arr[mid] >= x)
        {

            // for upper bound arr[mid]>x then we will get the value

            // If element at mid is greater than or equal to x,
            // update answer to mid, and move to the left half to find lower bound
            ans = mid;
            high = mid - 1;
        }
        else
        {
            // If element at mid is less than x,
            // move to the right half
            low = mid + 1;
        }
    }
    return ans; // Return the lower bound index
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 6}; // Example array
    int n = arr.size();                // Size of the array
    int x = 4;                         // Number to find the lower bound for

    // Call the lowerBound function
    int result = lowerBound(arr, n, x);

    // Print the result
    if (result < n)
    {
        cout << "The lower bound of " << x << " is at index " << result << "." << endl;
    }
    else
    {
        cout << x << " is greater than all elements in the array." << endl;
    }

    return 0;
}
