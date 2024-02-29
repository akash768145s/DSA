#include <iostream> // Include the library for input/output operations.

using namespace std; // Use the standard namespace to avoid prefixing std:: to cout, cin, etc.

class Solution
{
	public:
		long long int reverse_digit(long long int n) {
        long long int reversed = 0; // Initialize a variable to store the reversed number.
    
        // Loop runs as long as the number is not zero.
        while (n != 0) {
            // Multiply the current reversed number by 10 and add the last digit of 'n'.
            reversed = reversed * 10 + n % 10;
            // Remove the last digit from 'n'.
            n /= 10;
        }
    
        // Return the reversed number.
        return reversed;
    }
};

int main() {
    Solution sol; // Create an instance of the Solution class.
    long long int n; // Declare a variable to store the number to be reversed.

    cout << "Enter a number: "; // Prompt the user to enter a number.
    cin >> n; // Read the user input into the variable 'n'.

    // Call the reverse_digit method with 'n' and store the result in 'reversed'.
    long long int reversed = sol.reverse_digit(n);

    // Print the reversed number.
    cout << "Reversed number: " << reversed << endl;

    return 0; // Indicate that the program finished successfully.
}

