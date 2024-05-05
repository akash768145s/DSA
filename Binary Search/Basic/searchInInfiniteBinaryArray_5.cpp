#include <iostream>
using namespace std;

// Mock function to simulate the behavior of get(i).
// This should be replaced by the actual get function in your environment.
int get(int index) {
    // The implementation of this function is hidden and provided by the environment.
    // For demonstration, let's assume the first occurrence of 1 is at index 10.
    static int firstOneIndex = 10; // This should be hidden and is only for demonstration.
    return index >= firstOneIndex ? 1 : 0;
}

long long firstOne() {
    long long low = 0, high = 1;
    
    // Find the interval [low, high] containing the first occurrence of 1
    while (get(high) == 0) {
        low = high;
        high *= 2;
    }
    
    // Perform binary search in the interval [low, high]
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (get(mid) == 1 && (mid == 0 || get(mid - 1) == 0)) {
            return mid; // Found the first occurrence of 1
        } else if (get(mid) == 1) {
            high = mid - 1; // Move left
        } else {
            low = mid + 1; // Move right
        }
    }
    
    return -1; // In case 1 is not found, which should not happen as per problem statement
}

int main() {
    cout << "The first occurrence of 1 is at index: " << firstOne() << endl;
    return 0;
}
