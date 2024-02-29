#include <iostream>
#include <unordered_map>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) {
    // Create an empty unordered_map
    unordered_map<int,int> mp;
    
    // Store all elements of a1[] in the map with their index
    for(int i = 0; i < n; i++) {
        mp[a1[i]] = i;   
    }
    
    // Check if each element of a2[] is present in the map
    for(int i = 0; i < m; i++) {
        if(mp.find(a2[i]) == mp.end()) {
            return "No"; // Element of a2[] not found in a1[]
        }
    }
    return "Yes"; // All elements of a2[] found in a1[]
}

int main() {
    // Example arrays
    int a1[] = {11, 7, 1, 13, 21, 3, 7, 3};
    int a2[] = {11, 3, 7, 1, 7};
    int n = sizeof(a1) / sizeof(a1[0]);
    int m = sizeof(a2) / sizeof(a2[0]);

    // Check if a2[] is a subset of a1[] and print the result
    cout << isSubset(a1, a2, n, m) << endl;

    return 0;
}
