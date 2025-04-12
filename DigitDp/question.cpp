// JAI MAHAKALLLLLLLLLLLLLLL
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define int long long
#define dbg(x) cout << #x << " = " << x << "\n"
#define vi vector<int>
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
const int N = 200;
vector<bool> sievearray(N, true);
vector<int> primes;
void sieve()
{
    sievearray[0] = sievearray[1] = false;
    for (int i = 2; i < N; i++)
    {
        if (sievearray[i])
        {
            primes.push_back(i);
            for (int j = i * i; j < N; j += i)
            {
                sievearray[j] = false;
            }
        }
    }
}
int dp[20][2][200]; 
int solve(string &s, int ind, int flag, int sum)
{
    if (dp[ind][flag][sum] != -1)
        return dp[ind][flag][sum];
    if (ind == s.size())
        return sievearray[sum] ? 1 : 0;
    int limit = (flag ? s[ind] - '0' : 9);
    int ans = 0;
    for (int i = 0; i <= limit; i++)
    {
        int updatedsum = sum + i;
        ans += solve(s, ind + 1, flag && s[ind] - '0' == i, updatedsum);
    }
    return dp[ind][flag][sum] = ans;
}
void coderaryan()
{
    int l, r;
    cin >> l >> r;

    string vl = to_string(l - 1);
    memset(dp, -1, sizeof(dp));
    int left = solve(vl, 0, 1, 0); // Start at index 0, tight constraint (flag=1)

    string vr = to_string(r);
    memset(dp, -1, sizeof(dp));
    int right = solve(vr, 0, 1, 0); // Corrected: use vr instead of vl

    cout << right - left << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();
    // fact();
    int t;
    cin>>t;
    while(t--) coderaryan();
    return 0;
}