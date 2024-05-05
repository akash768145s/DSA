#include <bits/stdc++.h>
using namespace std;

int firstOcc(vector<int>& arr, int n, int k) {
    int low = 0, high = n - 1;
    int first = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == k) {
            first = mid;
            high = mid - 1; // Move left to find the first occurrence
        }
        else if (arr[mid] < k) low = mid + 1;
        else high = mid - 1;
    }
    return first;
}

int lastOcc(vector<int>& arr, int n, int k) {
    int low = 0, high = n - 1;
    int last = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == k) {
            last = mid;
            low = mid + 1; // Move right to find the last occurrence
        }
        else if (arr[mid] < k) low = mid + 1;
        else high = mid - 1;
    }
    return last;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k) {
    int first = firstOcc(arr, n, k);
    if (first == -1) return {-1, -1}; // Element not present
    int last = lastOcc(arr, n, k);
    return {first, last};
}

int main() {
    vector<int> arr = {2, 4, 4, 4, 6, 7, 8};
    int n = arr.size();
    int k = 4;
    
    pair<int, int> positions = firstAndLastPosition(arr, n, k);
    cout << "First Occurrence: " << positions.first << endl;
    cout << "Last Occurrence: " << positions.second << endl;
    
    return 0;
}

