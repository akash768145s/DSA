#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &arr, int n);

int main() {
    vector<int> arr = {1, 1, 2, 2, 3, 4, 4, 5}; // Sample input
    int n = arr.size(); // Size of the input array

    int newLength = removeDuplicates(arr, n); // Removing duplicates

    cout << "Array after removing duplicates: ";
    for(int i = 0; i < newLength; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

int removeDuplicates(vector<int> &arr, int n) {
    // Initialize a pointer i at the start of the array.
    int i = 0;

    // Iterate through the array starting from the second element.
    for(int j = 1; j < n; j++) {
        // If the current element is not equal to the element at i,
        // it means this is a unique element we haven't encountered yet.
        if(arr[i] != arr[j]) {
            // Move i forward and replace the element at the new i with
            // the current unique element. This effectively brings all
            // unique elements to the front of the array in sorted order.
            arr[i + 1] = arr[j];
            // Increment i to move to the next unique element's position.
            i++;
        }
        // If arr[i] == arr[j], just move j forward by the loop to skip the duplicate.
    }

    // The new length of the array without duplicates is i + 1,
    // since i is the index of the last unique element.
    return i + 1;
}

