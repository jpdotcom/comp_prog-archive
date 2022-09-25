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
#define MOD (int)1e9+7
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
vector<int>adj[maxN];
ll only[maxN];
bool has[maxN];
ll dp[maxN];
ll dist1[maxN];
ll dist2[maxN];
int pa[maxN];
int x,y;
void dfs1(int u,int p,int dist){
    dist1[u]=dist;
    pa[u]=p;
    for (int v:adj[u]){
        if (v!=p){
            if (has[v]){
                has[u]=true;
                only[u]=false;
            }
            dfs1(v,u,dist+1);
            has[u]|=has[v];
        }
    }
}
void dfs2(int u,int p,int dist){
    dist2[u]=dist;
    for (int v:adj[u])
        if (v!=p) dfs2(v,u,dist+1);
}
void calc(int u){
    if (dp[u]!=-1) return;
    dp[u]=0;
    for (int v:adj[u]){
        if (v!=pa[u] && has[v]){
            calc(v);
            dp[u]+=dp[v]+2;
        }
    }
}
void solve(){
    int n,k;
    cin>>n>>k;
    cin>>x>>y;
    FOR(n+1){
        adj[i].clear();
        dp[i]=-1;
        pa[i]=-1;
        has[i]=false;
        only[i]=false;
        dist1[i]=dist2[i]=-1;
    }
    FOR(k){
        int val; cin>>val;
        has[val]=true;
        only[val]=true;
    }
    FOR(n-1){
        int a,b;cin>>a>>b;
        adj[a].pb(b),adj[b].pb(a);
    }
    dfs1(x,0,0);
    dfs2(y,0,0);
    ll ans=1e12;
    calc(x);
    for (int i=1;i<=n;i++){
        if (only[i]) ans=min(dp[x]-dist1[i]+dist2[i],ans);
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
    cin>>t;
    while (t--){
        solve();
    }
}
