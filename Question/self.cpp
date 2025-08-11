#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int rec(int ind, int prev, vector<int> &vec)
{
    cout<<ind<<" "<<prev<<endl;
    if (ind == 0)
    {
        if (prev < vec[ind])
            return 0;
        else
            return 1;
    }
    if(ind<0) return 0;
    int ans = 0;
    if (prev >= vec[ind])
    {
        ans += rec(ind - 1, vec[ind], vec) + 1;
    }
    else
    {
        ans += rec(ind - 1, prev, vec);
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>vec(n,0);
    for(int i=0;i<n;i++) cin>>vec[i];
    int ans = 0;
    for (int i = vec.size() - 1; i >= 0; i--){
        ans = max(ans, rec(i, vec[i], vec));
    }
    cout<<ans<<endl;
}
