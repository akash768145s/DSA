#include <iostream>
#include <algorithm> // For sort

using namespace std;

bool findTriplets(int arr[], int n) {
    sort(arr, arr + n); // Corrected sorting for arrays
    for(int i = 0; i < n - 2; i++) {
        int l = i + 1; // Left pointer
        int r = n - 1; // Right pointer
        while(l < r) { // Corrected while loop syntax
            int sum = arr[i] + arr[l] + arr[r];
            if(sum == 0) {
                return true; // Return true if triplet found
            } else if (sum < 0) {
                l++; // Move left pointer right to increase sum
            } else {
                r--; // Move right pointer left to decrease sum
            }
        }
    }
    return false; // Return false if no triplet found
}

int main() {
    int arr[] = {0, -1, 2, -3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    if (findTriplets(arr, n)) {
        cout << "Found triplets with zero sum" << endl;
    } else {
        cout << "No triplets with zero sum found" << endl;
    }
    
    return 0;
}
