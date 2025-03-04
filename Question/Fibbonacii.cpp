#include <bits/stdc++.h>
using namespace std;

vector<int> cache;

int fibbonaci(int n)
{
    if (n < 2)
        return n; 
    if (cache[n] != -1) return cache[n];
    cache[n] = fibbonaci(n - 1) + fibbonaci(n - 2);
    return cache[n];
}

void coderaryan()
{
    int t;
    cin >> t;
    if (t < 0) {
        cout << "Invalid input: Fibonacci is not defined for negative numbers." << endl;
        return;
    }
    cache.resize(t + 1, -1); // Initialize cache with -1
    fibbonaci(t);
    for (int i = 0; i <= t; i++) cout << cache[i] << " ";
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    coderaryan();
    return 0;
}
