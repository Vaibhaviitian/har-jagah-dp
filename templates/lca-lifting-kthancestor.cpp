// JAI MAHAKALLLLLLLLLLLLLLL
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define MOD 1000000007
#define int long long
#define nl "\n"
#define dbg(x) cout << #x << " = " << x << "\n"
#define vi vector<int>
#define cy cout<<"YES"<<"\n"
#define cn cout<<"NO"<<"\n"
const int N = 10000005;
template<typename T>void help(vector<T> a){for(int i=0;i<a.size();i++) cout<<a[i]<<" ";cout<<"\n";}
template <typename T> void help2D(const vector<vector<T>> &a) { for (int i = 0; i < a.size(); i++) { for (int j = 0; j < a[i].size(); j++) cout << a[i][j] << " "; cout << endl; } }
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
vector<bool> sievearray(N, true);
vector<int> primes;
void sieve() {
    sievearray[0] = sievearray[1] = false;
    for (int i = 2; i < N; i++) {
        if (sievearray[i]) {
            primes.push_back(i);
            for (int j = i * i; j < N; j += i) {
                sievearray[j] = false;
            }
        }
    }
}
//cout << fixed << setprecision(15) << (value upto 15) << "\n";
// s.find_by_order(k): iterator to k-th smallest element (0-based index) 
// s.order_of_key(x): number of elements strictly less than x
// lowerbound: pehela element jo x se bada ya barabar ho
// upperbound: pehela element jo x se bada ho

vector<int>rnk;
vector<int>repre;
vector<vector<pair<int,int>>>vpp;
vector<int>depth;
vector<vector<int>>dp;
vector<vector<int>>max_edge;
vector<pair<int,int>>parent;

int find_kth(int node,int k){
    for(int i=0;i<32;i++){
        if(node == -1) break;
        if(k&(1<<i)){
            node=dp[node][i];
        }
    }
    return node;
}
int lca(int a, int b, int n) {
    if(depth[a] > depth[b]) swap(a, b);
    int maxW = 0;
    int diff = depth[b] - depth[a];
    for(int i = 0; i < 32; i++) {
        if(diff & (1 << i)) {
            maxW = max(maxW, max_edge[b][i]);
            b = dp[b][i];
        }
    }
    if(a == b) return maxW; // Same node after leveling
    for(int i = log2(n); i >= 0; i--) {
        if(dp[a][i] != -1 && dp[a][i] != dp[b][i]) {
            maxW = max({maxW, max_edge[a][i], max_edge[b][i]});
            a = dp[a][i];
            b = dp[b][i];
        }
    }
    maxW = max({maxW, max_edge[a][0], max_edge[b][0]});
    return maxW;
}
void dfs(int node,int par,int w){
    if(par==-1){
        depth[node]=0;
    }else{
        depth[node]=depth[par]+1;
    }
    parent[node].first=par;
    parent[node].second=w;
    for(auto &i:vpp[node])if(depth[i.first]==-1)dfs(i.first,node,i.second);
}
void lifting(int n){
    dp.assign(n+1,vector<int>(log2(n)+1,-1));
    max_edge.assign(n+1,vector<int>(log2(n)+1,-1));
    for(int i=2;i<=n;i++)dp[i][0]=parent[i].first;
    for(int j=1;j<=log2(n);j++){
        for(int i=1;i<=n;i++){
            if(dp[i][j-1]!=-1)dp[i][j]=dp[dp[i][j-1]][j-1];
        }
    }
    // help2D(max_edge);
    for(int i=2;i<=n;i++)max_edge[i][0]=parent[i].second;
    for(int j=1;j<=log2(n);j++){
        for(int i=1;i<=n;i++){
            if(max_edge[i][j-1]!=-1 && dp[i][j-1]!=-1) max_edge[i][j] = max(max_edge[i][j-1], max_edge[dp[i][j-1]][j-1]);
        }
    }
}

void make_set(int n){
    repre.assign(n+1,-1);
    rnk.assign(n+1,-1);
    for(int i=1;i<rnk.size();i++){
        rnk[i]=1;
        repre[i]=i;
    }
}
int find_rep(int n) {
    if (repre[n] != n) {
        repre[n] = find_rep(repre[n]);
    }
    return repre[n];
}
void mer(int a,int b){
    int a_rep=find_rep(a);
    int b_rep=find_rep(b);
    if(a_rep==b_rep) return;
    if(rnk[a_rep]>rnk[b_rep]){
        rnk[a_rep]+=rnk[b_rep];
        repre[b_rep]=a_rep;
    }else{
        rnk[b_rep]+=rnk[a_rep];
        repre[a_rep]=b_rep;
    }
}
void coderaryan() {
    // executing code from here 
    int n,m;
    cin>>n>>m;
    vector<vector<int>>vec;
    vector<vector<int>>temp;
    make_set(n);
    map<pair<int,int>,int>mpl;
    while(m--){
        int a,b,c;cin>>a>>b>>c;
        vec.push_back({a,b,c});
    }
    temp=vec;
    sort(vec.begin(),vec.end(),[](vector<int>a,vector<int>b){
        return a[2]<b[2];
    });
    int cnt=0,ans=0;
    vpp.resize(n+1);
    for(auto &i:vec){
        if(find_rep(i[0])!=find_rep(i[1])){
            cnt++;
            mer(i[0],i[1]);
            vpp[i[0]].push_back({i[1],i[2]});
            vpp[i[1]].push_back({i[0],i[2]});
            ans+=i[2];
            mpl[{i[0],i[1]}]=1;
        }
        if(cnt==n-1)break;
    }
    // adjaceny matrix tayyar hai
    depth.assign(n+1,-1);
    parent.assign(n+1,{-1,-1});
    dfs(1,-1,-1);
    // help(depth);
    // for(int i=1;i<=n;i++){
    //     cout<<i<<" "<<parent[i].first<<" "<<parent[i].second<<endl;
    // }
    lifting(n);
    // help2D(dp);
    // cout<<lca(1,2,n)<<endl;
    // cout<<find_kth(5,4)<<endl;
    // dbg(ans);
    for(auto &i:temp){
        int temp=ans;
        temp+=i[2];
        // cout<<i[0]<<" "<<i[1]<<endl;
        // dbg(lca(i[0],i[1],n));
        temp-=lca(i[0],i[1],n);
        cout<<temp<<'\n';
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // sieve();
    coderaryan();
    return 0;
}