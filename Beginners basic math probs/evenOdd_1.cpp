#include <iostream>
using namespace std;

class Solution{
public:
    string oddEven(int N){
        if(N % 2 == 0){
            return "even";
        }
        else{
            return "odd";
        }
    }
};

// Driver code
int main() {
    Solution sol;
    int N;

    // Example test
    N = 4;
    cout << N << " is " << sol.oddEven(N) << endl;

    N = 5;
    cout << N << " is " << sol.oddEven(N) << endl;

    return 0;
}
