#include <iostream>
using namespace std;
// Dutch National Flag Algorithm is Used for this problem and visualization is in notes

class Solution
{
public:
    void sort012(int arr[], int n)
    {
        int low = 0, mid = 0, high = n - 1;
        while (mid <= high)
        {
            if (arr[mid] == 0)
            {
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            }
            else if (arr[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};

int main()
{
    Solution sol;

    // Example input
    int arr[] = {0, 2, 1, 2, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call the sort012 function
    sol.sort012(arr, n);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
