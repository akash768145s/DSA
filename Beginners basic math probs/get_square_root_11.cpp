#include <stdio.h>

// Function to find the floor square root of x
long long int floorSqrt(long long int x) 
{
    // Initialize low and high for binary search
    int low = 1, high = x;
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long val = mid * mid;

        if (val == x) {
            // Exact square root found
            return mid;
        } else if (val < x) {
            // Continue searching in the right half
            low = mid + 1;
        } else {
            // Continue searching in the left half
            high = mid - 1;
        }
    }
    // high will have the floor value of sqrt(x) when loop exits
    return high;
}

int main() {
    // Test the function with different values of x
    long long int x;

    printf("Enter a number to find its floor square root: ");
    scanf("%lld", &x);

    long long int result = floorSqrt(x);
    printf("The floor square root of %lld is %lld\n", x, result);

    return 0;
}
