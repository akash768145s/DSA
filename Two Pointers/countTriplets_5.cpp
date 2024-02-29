#include <iostream>
#include <algorithm> // For sort

using namespace std;

int countTriplet(int arr[], int n) {
    // Sort the array to enable the two-pointer technique
    sort(arr, arr + n);
    
    int count = 0; // Initialize count of triplets
    
    // Iterate over the array starting from the third element
    for(int i = n - 1; i >= 2; i--) {
        int l = 0;      // Initialize left pointer
        int h = i - 1;  // Initialize right pointer just before the current element
        
        // Use two-pointer technique to find pairs that sum up to arr[i]
        while(l < h) {
            int sum = arr[l] + arr[h];
            
            // If the sum of the pair is equal to the current element,
            // it means we found a triplet, increment count and move pointers
            if(sum == arr[i]) {
                count++;
                l++;
                h--;
            } else if(sum < arr[i]) {
                // If sum is less than the current element, move the left pointer right
                l++;
            } else {
                // If sum is greater than the current element, move the right pointer left
                h--;
            }
        }
    }
    return count; // Return the total count of such triplets
}

int main() {
    int arr[] = {5, 32, 1, 10, 10, 50, 19, 21, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int totalTriplets = countTriplet(arr, n);
    cout << "Total triplets: " << totalTriplets << endl;
    
    return 0;
}
