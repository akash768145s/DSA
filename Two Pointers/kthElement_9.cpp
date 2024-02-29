#include<bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &a, vector<int> &b, int n1, int n2, int k) {
    // Corrects order if first array is larger, ensuring a is the smaller array
if (n1 > n2) return kthElement(b, a, n2, n1, k);

// Search space boundaries
int low = max(0, k - n2), high = min(k, n1);

while (low <= high) {
    // Binary search cut positions on both arrays
    int cut1 = (low + high) / 2;
    int cut2 = k - cut1; // Ensures that cut1 + cut2 = k
    
    // Handling corner cases for minimum and maximum elements
    int l1 = cut1 == 0 ? INT_MIN : a[cut1 - 1]; // Left of cut1 or minimum int
    int l2 = cut2 == 0 ? INT_MIN : b[cut2 - 1]; // Left of cut2 or minimum int
    int r1 = cut1 == n1 ? INT_MAX : a[cut1]; // Right of cut1 or maximum int
    int r2 = cut2 == n2 ? INT_MAX : b[cut2]; // Right of cut2 or maximum int  condition ? expression1 : expression2;
/*
cut2 == n2: This is the condition being evaluated. It checks if cut2, which represents a cut or partition index in array b, is equal to n2, the size of array b.
INT_MAX: This is expression1, the value to use if the condition is true. INT_MAX is a constant that represents the maximum possible value of an int in C++. It's used here to represent a theoretical value that's larger than any element in array b, acting as a placeholder when the partition has moved beyond the last element of b.
b[cut2]: This is expression2, the value to use if the condition is false. It simply accesses the element at index cut2 in array b.

*/
    
    // If correct partition is found
    if (l1 <= r2 && l2 <= r1) {
        // kth element is the max of left parts
        return max(l1, l2);
    } else if (l1 > r2) {
        // Move towards the left in 'a'
        high = cut1 - 1;
    } else {
        // Move towards the right in 'a'
        low = cut1 + 1;
    }
}
return 1; // Fallback return value

    }

int main() {
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int k = 5; // Example: Find the 5th element in the combined sorted array
    cout << "The " << k << "th element is " << kthElement(a, b, a.size(), b.size(), k) << endl;
    return 0;
}
