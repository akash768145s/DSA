#include <iostream>
#include <string>
#include <climits> // For INT_MAX and INT_MIN
using namespace std;

int atoi(string s) {
    if(s.empty()) return 0; // Check if string is empty
    
    int i = 0;
    while(i < s.size() && s[i] == ' ') { // Skip leading whitespaces
        i++;
    }
    
    if(i == s.size()) return 0; // If only spaces were found
    
    int sign = 1; // Default sign is positive
    long ans = 0; // Use long to avoid integer overflow during calculation
    
    if(s[i] == '-') {
        sign = -1;
        i++;
    } else if(s[i] == '+') {
        i++;
    }
    
    while(i < s.length() && isdigit(s[i])) { // Ensure current character is a digit
        ans = ans * 10 + (s[i] - '0'); // Convert digit character to integer and add to ans
        if(sign == -1 && -1 * ans < INT_MIN) return INT_MIN; // Check for underflow
        if(sign == 1 && ans > INT_MAX) return INT_MAX; // Check for overflow
        i++;
    }
    
    return static_cast<int>(sign * ans); // Cast result back to int
}

int main() {
    string str;
    cout << "Enter a string to convert to integer: ";
    getline(cin, str); // Use getline to allow spaces in input
    cout << "Converted integer: " << atoi(str) << endl;
    return 0;
}
