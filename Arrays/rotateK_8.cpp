#include <iostream>
#include <vector>
#include <algorithm> // For std::reverse

using namespace std;

void rotateArray(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n; // Ensure k is within bounds to avoid unnecessary full rotations
    // Correct approach for right rotation
    reverse(arr.begin(), arr.end()); // Reverse the entire array
    reverse(arr.begin(), arr.begin() + k); // Reverse the first k elements
    reverse(arr.begin() + k, arr.end()); // Reverse the rest
}

int main() {
    // Predefined size and array
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 1; // Predefined number of rotations

    // No need to read n and array elements from user
    rotateArray(arr, k); // Rotate the array
    
    // Print the rotated array
    for (const auto& element : arr) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
