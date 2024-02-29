/*Here we used the concept of binary exponentation*/


#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Solution
{
public:
    int getLastDigit(string a, string b)
    {
        // If the exponent is 0, return 1 as any number to the power of 0 is 1.
        if (b[0] == '0')
            return 1;

        // Calculate the lengths of the strings a and b.
        int n = a.length(), m = b.length();
        // Get the last digit of the base number as a char.
        char last = a[n - 1];

        // If the last digit of the base is 0, 5, 6, or 1, the last digit of the result will be the same.
        // Convert the char to an int before returning.
        if (last == '0' || last == '5' || last == '6' || last == '1')
            return last - '0';
        /*he expression return last - '0' is used to convert a character representing a digit (stored in the variable last) into its corresponding integer value. In C++, characters are internally represented by integer values according to the ASCII table. For example, in ASCII, the character '0' has the integer value 48, '1' has the value 49, and so on up to '9' which has the value 57.

            So, when you have a character last that represents a digit (say '3'), and you subtract the ASCII value of '0' (which is 48) from it, you get the actual numerical value of that character:

            ASCII value of '3' = 51
            ASCII value of '0' = 48
            51 - 48 = 3*/
        // For bases ending in 4 or 9, the pattern of the last digit repeats every 2 numbers.
        // For all other bases (except those handled above), the pattern repeats every 4 numbers.
        int mod = (last == '4' || last == '9') ? 2 : 4;

        // Initialize num to accumulate the effective exponent after modulo operation.
        int num = 0;
        // Convert string b (the exponent) into an integer modulo 'mod'.
        for (int i = 0; i < m; ++i)
            num = (num * 10 + (b[i] - '0')) % mod;

        // If num is 0, it means the power cycle completes, so we use the full cycle length.
        num = num == 0 ? mod : num;

        // Calculate the last digit of the result by raising the last digit of 'a' to the power 'num',
        // then take modulo 10 to get the last digit of the result. Cast the base to int before exponentiation.
        return (int)pow(last - '0', num) % 10;
    }
};

int main()
{
    Solution sol;

    string a, b;

    a = "12";
    b = "5";
    cout << "Last digit of " << a << "^" << b << " is: " << sol.getLastDigit(a, b) << endl;

    a = "3";
    b = "10";
    cout << "Last digit of " << a << "^" << b << " is: " << sol.getLastDigit(a, b) << endl;

    a = "3333";
    b = "2";
    cout << "Last digit of " << a << "^" << b << " is: " << sol.getLastDigit(a, b) << endl;

    return 0;
}
