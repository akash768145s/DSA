#include <iostream>
#include <vector>
using namespace std;

// Define the maximum number N up to which we want to find prime numbers
const int N = 1000000;

// Create a global array 'sieve' of size N+1 to store boolean values.
// sieve[i] will be true if 'i' is a prime number, false otherwise.
bool sieve[N + 1];

// Function to initialize and populate the sieve array using the Sieve of Eratosthenes algorithm
void createSieve() {
    // Initialize all entries of sieve[] as false to indicate that we haven't processed them yet.
    for(int i = 2; i * i <= N; i++){
        sieve[i] = true;
    }

    // Loop over the numbers from 2 to N to populate the sieve
    for (int i = 2; i <= N; i++) {
        // Check if the number is marked as prime
        if (sieve[i] == true) { 
            // If the current number 'i' is prime, mark all multiples of 'i' as non-prime
            for (int j = i * i; j <= N; j += i)
                sieve[j] = false; // Mark the multiple of i as non-prime
        }
    }
}  

// Main function to execute the program
int main() {
    // First, we need to call createSieve to initialize the sieve
    createSieve();

    // Now, we can iterate over the sieve array and print the prime numbers
    for (int i = 2; i <= N; i++) {
        // If sieve[i] is true, then 'i' is a prime number
        if (sieve[i])
            cout << i << " ";
    }
    cout << endl; // Print a newline at the end

    return 0; // Indicate that the program executed successfully
}


/*
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to generate all primes less than or equal to N using the Sieve of Eratosthenes algorithm
    vector<int> sieveOfEratosthenes(int N) {
        // Step 1: Create a boolean array "isPrime[0..N]" and initialize all entries as true. 
        // A value in isPrime[i] will be false if i is Not a prime, true if i is a prime.
        vector<bool> isPrime(N + 1, true);

        // 0 and 1 are not primes, so they are set to false.
        isPrime[0] = isPrime[1] = false;

        // Step 2: Iterate over each number starting from 2 to sqrt(N) to check for prime numbers
        for (int i = 2; i * i <= N; i++) {
            // If isPrime[i] is not changed, then it is a prime
            if (isPrime[i] == true) {
                // Update all multiples of i greater than or equal to the square of it.
                // Numbers which are multiple of i and are less than i^2 are already been marked.
                for (int j = i * i; j <= N; j += i)
                    isPrime[j] = false; // Marking the number as not prime
            }
        }

        // Step 3: Collect all prime numbers into a vector and return
        vector<int> primes;
        for (int i = 2; i <= N; i++) {
            if (isPrime[i])
                primes.push_back(i); // If isPrime[i] is true, i is a prime number, so add it to the primes list
        }

        return primes;
    }
};

int main() {
    Solution solution;
    int N = 100; // Example: Find all prime numbers up to 100
    vector<int> primes = solution.sieveOfEratosthenes(N);

    cout << "Prime numbers up to " << N << ":" << endl;
    for (int prime : primes) {
        cout << prime << " ";
    }
    cout << endl;

    return 0;
}
*/