#include <iostream>
#include <climits> // For INT_MIN
using namespace std;

class Solution {
public:
    int thirdLargest(int a[], int n) {
        if (n < 3) return -1;

        int first = a[0], second = INT_MIN, third = INT_MIN;

        for (int i = 1; i < n; i++) {
            if (a[i] > first) {
                third = second;
                second = first;
                first = a[i];
            } else if (a[i] > second && a[i] != first) {
                third = second;
                second = a[i];
            } else if (a[i] > third && a[i] != second) {
                third = a[i];
            }
        }
        return third == INT_MIN ? -1 : third;
    }
};

int main() {
    Solution sol;

    // Define an array of integers
    int a[] = {2, 4, 1, 3, 5};
    int n = sizeof(a) / sizeof(a[0]); // Calculate the number of elements in the array

    // Call the thirdLargest function and store the result
    int result = sol.thirdLargest(a, n);

    // Print the result
    if (result == -1) {
        cout << "The array does not have a third largest element." << endl;
    } else {
        cout << "The third largest element is: " << result << endl;
    }

    return 0;
}
