#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<long long> vi;
typedef std::pair<long long,long long> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<int> pq;
#define endl '\n'
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define MOD (ll)(998244353)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
const int maxN=1e5+1;
vi adj[maxN];
ll dp[maxN][2];
ll a[maxN][2];
void dfs(int u,int i, int p){
    if (dp[u][i]!=-1) return;
    ll ans=0;
    for (int v:adj[u]){
        if (v!=p){
            dfs(v,0,u);
            dfs(v,1,u);
            ans+=max(abs(a[u][i]-a[v][0])+dp[v][0],abs(a[u][i]-a[v][1])+dp[v][1]);
        }
    }
    dp[u][i]=ans;
}
void solve(){

    int n; cin>>n;
    FOR(n+1){
        adj[i].clear(); dp[i][0]=dp[i][1]=-1;
    }
    FOR(n) cin>>a[i+1][0]>>a[i+1][1];
    FOR(n-1){
        int a,b; cin>>a>>b;
        adj[a].pb(b),adj[b].pb(a);
    }
    dfs(1,0,-1);
    dfs(1,1,-1);
    print(max(dp[1][0],dp[1][1]));
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }
}
