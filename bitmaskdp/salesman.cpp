// JAI MAHAKALLLLLLLLLLLLLLL
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define int long long
#define dbg(x) cout << #x << " = " << x << "\n"
#define vi vector<int>
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
// ASCII values
// A=65, Z=90, a=97, z=122
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
// Function to print 2D vector
template <typename T>
void helptwo(const vector<vector<T>> &vec)
{
    cout << "2D help is executed:" << endl;
    for (const auto &row : vec)
    {
        for (const auto &i : row)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
// Function to print a map
template <typename K, typename V>
void helpmap(const map<K, V> &mp)
{
    cout << "map help is executed:" << endl;
    for (const auto &i : mp)
    {
        cout << i.first << " -> " << i.second << endl;
    }
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
const int N = 10000005;
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
vector<int> factorial(N);
void fact()
{
    factorial[0] = 1;
    for (int i = 1; i < N; i++)
    {
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }
}
int nCr(int n, int r)
{
    if (r > n)
    {
        return 0;
    }
    int ans = factorial[n];
    ans = (ans * mod_exp(factorial[r], MOD - 2, MOD)) % MOD;
    ans = (ans * mod_exp(factorial[n - r], MOD - 2, MOD)) % MOD;
    return ans;
}
vector<vector<int>> vec;
int dp[21][(1 << 22)];
// int x=0;
int solve(int city, int mask)
{
    // set bits of mask number here representing those cities which are not get traversed 
    cout<<"solve("<<city<<","<<mask<<")"<<endl;
    if(city == vec.size()) return vec[city][0];;
    if(__builtin_popcount(mask)==0) return vec[city][0];;
    if(dp[city][mask] != -1) return dp[city][mask];
    // here we are iterating in the mask and if we get the value which bit is 1 means that city is not traversed now 
    int ans=1e9;
    for(int j=0;j<vec.size();j++){
        if((mask&(1<<j))){
            // there are the line i got stucked not able to think where to use which
            ans=min(ans,vec[city][j]+solve(j,mask^(1<<j)));
        }
    }
    return dp[city][mask]=ans;
}
void coderaryan()
{
    // executing code from here
    int t;
    cin >> t;
    vec.resize(t, vector<int>(t, 0));
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < t; j++)
        {
            cin >> vec[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout<<solve(0,(1<<t)-1)<<endl;
    // dbg(x);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // sieve();
    // fact();
    coderaryan();
    return 0;
}