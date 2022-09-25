#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<int,int> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<pi> pq;
#define endl '\n'
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define MOD 1e9+7;
#define iset tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
ll modu(ll a,ll b){
    return (b+(a%b)) % b;
}
ll power(ll x, ll y, ll p)
{
    ll res = 1;     
    x = x % p; 
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1) res=modu(res*x,p);
        y = y>>1; 
        x = modu((x*x),p);
    }
    return res;
}
void fileIO(string filename) {
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
const int maxN=2e5+5;
int dp[maxN];
int out[maxN];
vi adj[maxN];
void fill(int u){
    if (dp[u]!=-1) return;
    if (adj[u].size()<=1){
        dp[u]=1;
        return;
    }
    for (int v:adj[u]){
        if (out[v]>1){
            fill(v);
            dp[u]=max(dp[u],1+dp[v]);
        }
    }
    dp[u]=max(dp[u],1);
    return;
}
void solve(){
    int n,m;
    cin>>n>>m;
    FOR(m){
        int a,b;cin>>a>>b;adj[a].pb(b);
        out[b]++;
    }
    for (int i=1;i<=n;i++) dp[i]=-1;
    int ans=0;
    for (int i=1;i<=n;i++){
        fill(i);
        ans=max(ans,dp[i]);
    }
    print(ans);
}
void precompute(){
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(30);
    precompute();
    int t=1;
    while (t--){
        solve();
    }
}
