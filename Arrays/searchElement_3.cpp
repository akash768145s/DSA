#include <iostream>
using namespace std;

class Solution {
public:
    int search(int arr[], int N, int X) {
        // Iterate through the array
        for(int i = 0; i < N; i++) {
            // Check if the current element is the one we're searching for
            if(arr[i] == X) {
                // If found, return the current index
                return i;
            }
        }
        // If not found, return -1
        return -1;
    }
};

int main() {
    Solution sol;

    // Example input
    int arr[] = {1, 2, 3, 4};
    int n = 4;
    int x = 3;

    // Call the search function
    int result = sol.search(arr, n, x);

    // Output the result
    if(result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
