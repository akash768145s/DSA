#include <iostream>
#include <vector>
using namespace std;

void frequencyCount(vector<int>& arr, int N, int P) {
    int i, j;
    // Loop through each element of the array
    for(i = 0; i < N;) {
        // If the element is in the range [1, N]
        if(arr[i] > 0 && arr[i] <= N) {
            j = arr[i] - 1; // Find the index where this element should be counted
            // If the target position already has a negative count
            if(arr[j] <= 0) {
                arr[i] = 0; // Mark the current position as visited
                arr[j]--; // Decrement the count (negative value) at the target position
                i++; // Move to the next element
            } else {
                // Swap the current element with the element at its target count position
                swap(arr[j], arr[i]);
                arr[j] = -1; // Initialize the count for this element as -1 (since it's found once)
            }
        } else if(arr[i] > N) { // If the element is greater than N, it's not within the counting range
            arr[i] = 0; // Set its frequency as 0
            i++; // Move to the next element
        } else { // If the element is already processed (negative or 0), just move on
            i++;
        }
    }
    // Convert negative counts back to positive for the final frequency result
    for(i = 0; i < N; i++) {
        arr[i] = -arr[i]; // Convert negative values to positive
    }
}

int main() {
    // Example input
    vector<int> arr = {2, 3, 2, 3, 5};
    int N = arr.size(); // Number of elements in arr
    int P = 5; // Not used in the given function, possibly a placeholder for a problem constraint

    frequencyCount(arr, N, P); // Modify arr to contain frequency counts

    // Print the modified arr with frequency counts
    for(int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
