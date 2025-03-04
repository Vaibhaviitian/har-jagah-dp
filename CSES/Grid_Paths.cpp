// // JAI MAHAKALLLLLLLLLLLLLLL
// #include <bits/stdc++.h>
// using namespace std;
// #define MOD 1000000007
// #define int long long
// #define dbg(x) cout << #x << " = " << x << "\n"
// #define vi vector<int>
// #define pii pair<int, int>
// #define pb push_back
// #define mp make_pair
// #define cy cout << "YES" << endl
// #define cn cout << "NO" << endl
// // ASCII values
// // A=65, Z=90, a=97, z=122
// // Some Tricks
// // divide into cases, brute force, pattern finding
// // sort, greedy, binary search, two pointer
// // transform into graph
// // calculating anything in a string = count(in.begin(), in.end(), '0')
// // is a substring present on main string or not and X is repetition
// // bool checking_substring = in.find(string(X, '1')) != string::npos;
// // {for knowing MSB 32 -  __builtin_clz(n)}
// // {for knowing set bits  -  __builtin_popcount(n) and __builtin_popcountll(n)}

// // Function for modular exponentiation
// long long mod_exp(long long base, long long exp, long long mod)
// {
//     long long result = 1;
//     base = base % mod; // Handle base larger than mod
//     while (exp > 0)
//     {
//         if (exp % 2 == 1)
//         {
//             result = (result * base) % mod;
//         }
//         base = (base * base) % mod;
//         exp /= 2;
//     }
//     return result;
// }
// template <typename T>
// void help(const vector<T> &vec)
// {
//     cout << "help is executed" << endl;
//     for (const auto &i : vec)
//     {
//         cout << i << " ";
//     }
//     cout << endl;
// }
// int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
// int lcm(int a, int b) { return a / gcd(a, b) * b; }
// int mod(int a) { return a < 0 ? -a : a; }

// int prefix_sum(int a, int n)
// {
//     return (n * (2 * a + (n - 1))) / 2;
// }
// int coordinate_distance(int x1, int x2, int y1, int y2)
// {
//     int dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
//     return dist;
// }
// int min(int a, int b) { return std::min(a, b); }
// int max(int a, int b) { return std::max(a, b); }
// int cnt = 0;
// vector<vector<int>> dp(1002, vector<int>(1002, -1));
// int rec(int i, int j, vector<vector<char>> &vec)
// {
//     cnt++;
//     int ans = 0;
//     if (i == 1 && j == 1) return 1;
//     if (dp[i][j] != -1) return dp[i][j];
//     if (vec[i - 1][j] == '.' && i - 1 >= 0)
//     {
//         ans = (ans + rec(i - 1, j, vec)) % MOD;
//     }
//     if (vec[i][j - 1] == '.' && j - 1 >= 0)
//     {
//         ans = (ans + rec(i, j - 1, vec)) % MOD;
//     }
//     dp[i][j] = (ans % MOD);
//     return dp[i][j];
// }
// void coderaryan()
// {
//     // executing code from here
//     // int t;
//     // cin >> t;
//     // while (t--)
//     // {
//     int n;
//     cin >> n;
//     vector<vector<char>> vec(n + 1, vector<char>(n + 1));
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             cin >> vec[i][j];
//         }
//     }
//     // dbg(vec[n][n]);
//     if (vec[n][n] == '.')
//     {
//         cout << rec(n, n, vec) << endl;
//         // cy;
//     }
//     else
//     {
//         cout << 0 << endl;
//         // cn;
//     }
//     // dbg(cnt);
//     // }
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
    int n;
    cin >> n;
    vector<vector<char>> vec(n + 1, vector<char>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> vec[i][j];
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    vec[1][1] == '*' ? dp[1][1] = 0 : dp[1][1] = 1;
    // dbg(dp[1][1]);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i - 1 >= 0 && vec[i][j] == '.')
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            }
            if (j - 1 >= 0 && vec[i][j] == '.')
            {
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
            }
        }
    }
    cout << dp[n][n] % MOD << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    coderaryan();
    return 0;
}