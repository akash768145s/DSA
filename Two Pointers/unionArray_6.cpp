#include <bits/stdc++.h>
using namespace std;

vector<int> sortedArray(vector<int> a, vector<int> b);

int main() {
    vector<int> a = {1, 2, 2, 3, 5}; // First sorted array
    vector<int> b = {2, 4, 4, 5, 6}; // Second sorted array

    vector<int> unionArr = sortedArray(a, b);

    cout << "Union Array: ";
    for(int num : unionArr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

// Function to merge two sorted arrays into a sorted array without duplicates.
vector<int> sortedArray(vector<int> a, vector<int> b) {
    int n1 = a.size(); // Size of the first array
    int n2 = b.size(); // Size of the second array
    int i = 0, j = 0; // Pointers for iterating through arrays a and b
    vector<int> unionArr; // Vector to store the result

    // Loop through both arrays until one is fully traversed
    while(i < n1 && j < n2) {
        // If current element of a is smaller
        if(a[i] < b[j]) {
            // Add it to the result if it's not a duplicate of the last element
            if(unionArr.empty() || unionArr.back() != a[i]) {
                unionArr.push_back(a[i]);
            }
            i++;
        } else {
            // If current element of b is smaller or both are equal but not duplicates
            if(b[j] < a[i] || (a[i] == b[j] && (unionArr.empty() || unionArr.back() != a[i]))) {
                if(unionArr.empty() || unionArr.back() != b[j]) {
                    unionArr.push_back(b[j]);
                }
                j++;
            }
            // If elements are equal, move both pointers
            if(a[i] == b[j]) {
                i++;
            }
        }
    }

    // Add remaining elements from a
    while(i < n1) {
        if(unionArr.empty() || unionArr.back() != a[i]) {
            unionArr.push_back(a[i]);
        }
        i++;
    }

    // Add remaining elements from b
    while(j < n2) {
        if(unionArr.empty() || unionArr.back() != b[j]) {
            unionArr.push_back(b[j]);
        }
        j++;
    }

    return unionArr; // Return the merged array without duplicates
}

