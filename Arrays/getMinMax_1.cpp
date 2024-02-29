#include <iostream>
#include <climits> // For LLONG_MIN and LLONG_MAX
#include <utility> // For std::pair

using namespace std;

// Function to find the minimum and maximum elements in an array
pair<long long, long long> getMinMax(long long a[], int n) {
    long long minVal = LLONG_MAX; // Initialize minVal to the maximum possible value
    long long maxVal = LLONG_MIN; // Initialize maxVal to the minimum possible value

    // Traverse the array to find the minimum and maximum elements
    for (int i = 0; i < n; i++) {
        if (a[i] < minVal) {
            minVal = a[i]; // Update minVal if a smaller element is found
        }
        if (a[i] > maxVal) {
            maxVal = a[i]; // Update maxVal if a larger element is found
        }
    }

    // Create a pair with the minimum and maximum values
    pair<long long, long long> result = make_pair(minVal, maxVal);

    return result;
}

int main() {
    // Example array
    long long arr[] = {1000, 11, 445, 5, 330, 3000};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call the function and store the result
    pair<long long, long long> minMax = getMinMax(arr, n);

    // Print the results
    cout << "Minimum element is " << minMax.first << endl;
    cout << "Maximum element is " << minMax.second << endl;

    return 0;
}
