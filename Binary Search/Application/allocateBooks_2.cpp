#include <bits/stdc++.h>
using namespace std;

// Function to count the minimum number of students required to allocate pages under the given maximum limit.
int countStudents(vector<int> &arr, int pages) {
    int students = 1; // Start with one student
    long long pagesStudent = 0; // Pages allocated to the current student

    // Iterate through each book
    for (int i = 0; i < arr.size(); i++) {
        // If adding the current book's pages doesn't exceed the limit
        if (pagesStudent + arr[i] <= pages) {
            pagesStudent += arr[i]; // Allocate the book to the current student
        } else {
            // Otherwise, allocate the book to a new student
            students += 1;
            pagesStudent = arr[i]; // Start counting pages for the new student
        }
    }
    return students; // Return the total number of students required
}

// Function to find the minimum pages that results in all books being allocated without exceeding the student limit.
int findPages(vector<int> arr, int n, int m) {
    if (m > n) return -1; // If there are more students than books, allocation is not possible

    // Setting the search range for binary search
    // Low end is the maximum number of pages in a single book (minimum possible maximum pages)
    int low = *max_element(arr.begin(), arr.end()); 
    // High end is the sum of all pages (maximum possible maximum pages)
    int high = accumulate(arr.begin(), arr.end(), 0);

    // Binary search to find the minimum feasible maximum pages
    while (low <= high) {
        int mid = (low + high) / 2; // Mid is the current guess for the maximum number of pages
        int students = countStudents(arr, mid); // Calculate the number of students needed with this guess

        // If more students are needed than available, increase the page limit
        if (students > m) {
            low = mid + 1;
        } else {
            // Otherwise, try a lower limit to minimize the maximum pages
            high = mid - 1;
        }
    }
    // Low ends up as the minimum possible maximum pages to satisfy all constraints
    return low; 
}

int main() {
    vector<int> arr = {12, 34, 67, 90}; // Example: pages in each book
    int n = arr.size(); // Number of books
    int m = 2; // Number of students

    // Print the minimum number of pages a student has to read such that all books are allocated
    cout << "Minimum number of pages: " << findPages(arr, n, m) << endl;

    return 0;
}
