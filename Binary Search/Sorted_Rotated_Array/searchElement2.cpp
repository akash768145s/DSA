#include <iostream>
#include <vector>
using namespace std;
bool searchInARotatedSortedArrayII(vector<int>&arr, int k) {
    int n=arr.size();
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        // If the element is found at the mid position, return true.
        if(arr[mid]==k) return true;
        
        // If the elements at low, mid, and high are equal, we cannot determine which side is sorted.
        // Increment low and decrement high to skip over duplicates.
        if(arr[low]==arr[mid] && arr[mid]==arr[high]){
            low++,high--;
            continue;
        }
        
        // If the left side is sorted
        if(arr[low]<=arr[mid]){
            // If the target is in the range of the sorted left side, move towards it.
            if(arr[low]<=k && k<=arr[mid]){
                high=mid-1;
            }
            else{
                // Otherwise, target must be in the right side
                low=mid+1;
            }
        }
        else{
            // If the right side is sorted
            if(arr[mid]<=k && k<=arr[high]){
                // If the target is in the range of the sorted right side, move towards it.
                low=mid+1;
            }
            else{
                // Otherwise, target must be in the left side
                high=mid-1;
            }
        }
    }
    // If we exit the loop, the element was not found.
    return false;
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int k = 0; // Element to search for
    bool found = searchInARotatedSortedArrayII(arr, k);
    if (found) {
        cout << "Element found in the array." << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}