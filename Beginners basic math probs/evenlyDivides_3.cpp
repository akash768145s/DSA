/*
Example 1:

        Input:
        N = 12
        Output:
        2
        Explanation:
        1, 2 both divide 12 evenly
        Example 2:

        Input:
        N = 23
        Output
        0
        Explanation:
        2 and 3, none of them
        divide 23 evenly
*/

#include <iostream>
using namespace std;

class Solution
{
public:
    int evenlyDivides(int N)
    {
        int count = 0;
        int temp = N;

        while (temp > 0)
        {
            int digit = temp % 10; // Extract the last digit
            if (digit != 0 && N % digit == 0)
            {
                count++;
            }
            temp /= 10; // Move to the next digit
        }

        return count;
    }
};

int main()
{
    Solution sol;
    int N;

    cout << "Enter a number: ";
    cin >> N; // Input a number from the user

    int result = sol.evenlyDivides(N);
    cout << "The number of digits in " << N << " that evenly divide it is: " << result << endl;

    return 0;
}
