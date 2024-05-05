#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Checks if it's possible to place `cows` in the stalls with at least `dist` distance between them.
bool canWePlace(vector<int> &stalls, int dist, int cows){
    int cntCows = 1, last = stalls[0];
    for(int i = 1; i < stalls.size(); i++){
        // If the current stall is at least `dist` away from the last used stall,
        // place a cow here and update `last` to the position of the current stall.
        if(stalls[i] - last >= dist){
            cntCows++;
            last = stalls[i];
        }
        // If we have successfully placed all cows, return true.
        if(cntCows >= cows) return true;
    }
    // If not all cows can be placed with the given distance, return false.
    return false;
}

// Determines the maximum minimum distance possible between any two cows.
int aggressiveCows(vector<int> &stalls, int k){
    // First, sort the stalls so we can apply binary search.
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    // The minimum possible distance is 1 (the lowest we can go) and the maximum
    // possible distance is the difference between the last and first stall.
    int low = 1, high = stalls[n-1] - stalls[0];
    while(low <= high){
        int mid = (low + high) / 2;
        // Check if it's possible to place the cows with `mid` distance apart.
        if(canWePlace(stalls, mid, k)){
            // If yes, try a larger distance.
            low = mid + 1;
        } else {
            // Otherwise, try a smaller distance.
            high = mid - 1;
        }
    }
    // `high` now represents the largest minimum distance we can achieve.
    return high;
}

int main() {
    // Example use case
    vector<int> stalls = {1, 2, 8, 4, 9};
    int cows = 3;
    cout << "Largest minimum distance: " << aggressiveCows(stalls, cows) << endl;
    return 0;
}
