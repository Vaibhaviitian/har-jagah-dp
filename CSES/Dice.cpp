#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

vector<int> dp(1e6 + 1, -1);

int rec(int n) {
    // Base Cases
    if (n == 0) return 1; 
    if (dp[n] != -1) return dp[n];

    int ans = 0;
    for (int i = 1; i <= 6; i++) {
        if (n - i >= 0) {
            ans = (ans + rec(n - i)) % MOD;  
        }
    }

    return dp[n] = ans;
}

int main() {
    int n;
    cin >> n;
    cout << rec(n) << endl;
    return 0;
}
