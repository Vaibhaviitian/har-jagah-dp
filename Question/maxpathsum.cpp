// JAI MAHAKALLLLLLLLLLLLLLL
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
// ASCII values
// A=65, Z=90, a=97, z=122
// Some Tricks
// divide into cases, brute force, pattern finding
// sort, greedy, binary search, two pointer
// transform into graph
// calculating anything in a string = count(in.begin(), in.end(), '0')
// is a substring present on main string or not and X is repetition
// bool checking_substring = in.find(string(X, '1')) != string::npos;
// {for knowing MSB 32 -  __builtin_clz(n)}
// {for knowing set bits  -  __builtin_popcount(n) and __builtin_popcountll(n)}

// Function for modular exponentiation
long long mod_exp(long long base, long long exp, long long mod)
{
    long long result = 1;
    base = base % mod; // Handle base larger than mod
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

void jaimahakal(string some, int something)
{
    cout << some << " " << something << endl;
}

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
int mod(int a) { return a < 0 ? -a : a; }

int prefix_sum(int a, int n)
{
    return (n * (2 * a + (n - 1))) / 2;
}
int coordinate_distance(int x1, int x2, int y1, int y2)
{
    int dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    return dist;
}
int min(int a, int b) { return std::min(a, b); }
int max(int a, int b) { return std::max(a, b); }

void coderaryan()
{
    // executing code from here
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> vec(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> vec[i][j];
            }
        }
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = vec[0][0];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 && j > 0)
                {
                    dp[i][j] = vec[i][j] + dp[i][j - 1];
                }
                else if (j == 0 && i > 0)
                {
                    dp[i][j] = vec[i][j] + dp[i - 1][j];
                }
                else if (i > 0 && j > 0)
                {
                    dp[i][j] = vec[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        cout << dp[n - 1][m - 1] << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    coderaryan();
    return 0;
}