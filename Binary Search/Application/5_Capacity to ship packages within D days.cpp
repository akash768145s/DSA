#include <bits/stdc++.h>

using namespace std;

// Function to calculate the number of days required to ship weights with given capacity
int findDays(vector<int> &weights, int cap) {
    int days = 1, load = 0; // Initialize days and current load
    for (int i = 0; i < weights.size(); i++) { // Loop through each weight
        if (weights[i] + load > cap) { // If adding the current weight exceeds capacity
            days += 1; // Increment days as a new shipment will start
            load = weights[i]; // Reset load to the current weight
        } else { // If adding the current weight doesn't exceed capacity
            load += weights[i]; // Add the current weight to the load
        }
    }
    return days; // Return the total days required for shipping
}

// Function to find the least weight capacity required to ship weights in 'D' days
int leastWeightCapacity(vector<int> &weights, int D) {
    int low = *max_element(weights.begin(), weights.end()); // Find the minimum possible capacity
    int high = accumulate(weights.begin(), weights.end(), 0); // Find the maximum possible capacity
    while (low <= high) { // Binary search for the minimum capacity
        int mid = (low + high) / 2; // Calculate the mid capacity
        int numberOfDays = findDays(weights, mid); // Calculate the number of days with mid capacity
        if (numberOfDays <= D) { // If the number of days is less than or equal to required days
            high = mid - 1; // Adjust high to search for a lower capacity
        } else { // If the number of days is more than required days
            low = mid + 1; // Adjust low to search for a higher capacity
        }
    }
    return low; // Return the least capacity satisfying the condition
}

int main() {
    // Sample weights and required number of days
    vector<int> weights = {1, 2, 3, 4, 5};
    int D = 3;

    // Calculate and output the least weight capacity
    cout << "Least Weight Capacity: " << leastWeightCapacity(weights, D) << endl;

    return 0;
}
