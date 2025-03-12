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
// Function to check if a number is palindromic
int palindrome(int n)
{
    vi dig;
    int ld = -1;
    while (n > 0)
    {
        ld = n % 10;
        dig.push_back(ld);
        n /= 10;
    }
    int ans = 1;
    for (int i = 0; i < dig.size() / 2; i++)
    {
        if (dig[i] != dig[dig.size() - i - 1])
        {
            ans = 0;
            break;
        }
    }
    return ans;
}
vi palindromessss()
{
    vi cost;
    for (int i = 1; i <= 4e4 ; i++)
    {
        if (i <= 9 || palindrome(i))
        {
            cost.push_back(i);
        }
    }
    return cost;
}
vi dp;
void merilelo()
{
    vi costs = palindromessss();
    dp.assign(4e4 + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < costs.size(); i++)
    {
        for (int j = costs[i]; j <= 4e4; j++)
        {
            dp[j] = (dp[j] + dp[j - costs[i]]) % MOD;
        }
    }
}
void coderaryan()
{
    // executing code from here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    merilelo();
    coderaryan();
    return 0;
}