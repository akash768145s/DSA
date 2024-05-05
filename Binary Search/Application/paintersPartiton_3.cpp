#include <iostream>
#include <vector>
#include <algorithm> 
#include <numeric>   

using namespace std;

// Function to count the number of students required for given pages
int countStudents(vector<int> &arr, int pages)
{
    int students = 1;
    long long pagesStudent = 0; // Total pages a student has till now

    for (int i = 0; i < arr.size(); i++)
    {
        if (pagesStudent + arr[i] <= pages) // If current student can read more pages
        {
            pagesStudent += arr[i];
        }
        else
        {
            students += 1;            // Increment student count
            pagesStudent = arr[i];    // Start counting pages for next student
        }
    }
    return students;
}

// Function to find the minimum number of pages such that each student gets allocated
// contiguous pages and the maximum number of pages allocated is minimized
int findPages(vector<int> arr, int n, int m)
{
    if (m > n)
        return -1; // If number of students is more than the number of books, return -1

    int low = *max_element(arr.begin(), arr.end()); // Find the maximum number of pages a book has
    int high = accumulate(arr.begin(), arr.end(), 0); // Calculate the total number of pages in all books

    // Binary search to find the minimum number of pages
    while (low <= high)
    {
        int mid = (low + high) / 2; // Current guess for the minimum number of pages
        int students = countStudents(arr, mid); // Calculate number of students required for current guess

        if (students > m) // If number of students required is more than available students
        {
            low = mid + 1; // Increase the minimum pages
        }
        else // If number of students required is less than or equal to available students
        {
            high = mid - 1; // Decrease the minimum pages
        }
    }
    return low; // Return the minimum number of pages that ensures a valid allocation
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    return findPages(boards, boards.size(), k); // Call findPages to get the minimum number of pages
}

int main()
{
    vector<int> boards = {10, 20, 30, 40}; // Input data: Number of pages in each book
    int k = 2; // Number of students

    int result = findLargestMinDistance(boards, k); // Find the minimum number of pages

    cout << "Minimum number of pages with largest minimum distance: " << result << endl;

    return 0;
}
