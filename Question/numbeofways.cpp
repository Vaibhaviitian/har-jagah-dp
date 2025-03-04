#include <iostream>
#include <vector>
using namespace std;

int jump(int level, int n, vector<int> &dp)
{
    if (level == n)
        return 1; // Base case: Reached the target level.
    if (level > n)
        return 0; // Base case: Exceeded the target level.

    if (dp[level] != -1)
        return dp[level]; // Use memoized result.

    int ways = 0;
    for (int i = 1; i <= 3; i++)
    {
        ways += jump(level + i, n, dp); // Recursive step.
    }

    return dp[level] = ways; // Store the result in dp.
}

void coderaryan()
{
    int t;
    cin >> t;
    vector<int> dp(t + 1, -1);      // Initialize memoization array.
    cout << jump(0, t, dp) << endl; // Start from level 0.
}

int main()
{
    coderaryan();
    return 0;
}
