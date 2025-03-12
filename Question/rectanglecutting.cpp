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
// int qt[501][501];
// int solve(int a, int b)
// {
//     if (a == b) return 0;
//     if (qt[a][b] != -1) return qt[a][b];
//     int h = INT_MAX, v = INT_MAX;
//     // considering horizontal
//     for (int i = 1; i < a; i++)
//     {
//         h = min(h, solve(i, b) + solve(a - i, b) + 1);
//     }
//     // considering horizontal
//     for (int i = 1; i < b; i++)
//     {
//         v = min(v, solve(a, i) + solve(a, b - i) + 1);
//     }
//     // dbg((min(v, h) + 1));
//     qt[a][b] = (min(v, h));
//     return qt[a][b];
// }
// void coderaryan()
// {
//     // executing code from here
//     memset(qt, -1, sizeof(qt));
//     int a, b;
//     cin >> a >> b;
//     solve(a, b);
//     // for (int i = 0; i <= a; i++)
//     // {
//     //     for (int j = 0; j <= b; j++)
//     //     {
//     //         cout<<qt[i][j]<<" ";
//     //     }
//     //     cout<<endl;
//     // }
//     cout << solve(a,b)<<endl;
// }

// int32_t main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     coderaryan();
//     return 0;
// }

// iterative dp
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
void coderaryan()
{
    // executing code from here
    int a, b;
    cin >> a >> b;
    vector<vector<int>> qt(a + 1, vector<int>(b + 1, 2e9));

    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (i == 1)
            {
                qt[i][j] = j - 1;
            }
            else if (i == j)
            {
                qt[i][j] = 0;
            }
            else if (j == 1)
            {
                qt[i][j] = i - 1;
            }
            else
            {
                int h = INT32_MAX, v = INT32_MAX;
                // considering horizontal
                for (int k = 1; k < i; k++)
                {
                    h = min(h, qt[k][j] + qt[i - k][j] + 1);
                }
                // considering horizontal
                for (int k = 1; k < j; k++)
                {
                    v = min(v, qt[i][k] + qt[i][j - k] + 1);
                }
                qt[i][j] = min(h, v);
            }
        }
        // for (int i = 0; i <= a; i++)
        // {
        //     for (int j = 0; j <= b; j++)
        //     {
        //         cout<<qt[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
    }
    cout << qt[a][b] << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    coderaryan();
    return 0;
}