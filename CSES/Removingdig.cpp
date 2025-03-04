// REcursive code
// #include <bits/stdc++.h>
// using namespace std;

// int dp[1000001];

// int rec(int n) {
//     if (n == 0) return 0;
//     if (dp[n] != -1) return dp[n];

//     int ans = INT_MAX;
//     int x = n;

//     while (x > 0) {
//         int ld = x % 10;
//         x /= 10;
//         if (ld != 0) ans = min(ans, 1 + rec(n - ld));
//     }

//     return dp[n] = ans;
// }

// void coderaryan() {
//     int n;
//     cin >> n;
//     memset(dp, -1, sizeof(dp));
//     cout << rec(n) << endl;
// }

// int32_t main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     coderaryan();
//     return 0;
// }

// JAI MAHAKALLLLLLLLLLLLLLL
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define int long long
#define dbg(x) cout << #x << " = " << x << "\n"
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
template <typename T>
void help(const vector<T> &vec)
{
    cout << "help is executed" << endl;
    for (const auto &i : vec)
    {
        cout << i << " ";
    }
    cout << endl;
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
    vi dp(1e6+2);
    int n;
    cin >> n;
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = i, ld, ans = 1e9;
        while (x > 0)
        {
            ld = x % 10;
            x /= 10;
            if (ld != 0)
            {
                ans = min(1 + dp[i - ld], ans);
            }
        }
        dp[i] = ans;
    }
    // help(dp);
    cout << dp[n] << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    coderaryan();
    return 0;
}