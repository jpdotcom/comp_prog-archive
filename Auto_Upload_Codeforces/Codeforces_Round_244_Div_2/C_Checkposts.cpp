#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<long long> vi;
typedef long long ll;
typedef std::pair<int,int> pi;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define endl '\n'
#define print(x) cout<<x<<'\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+1)
#define all(a) (a).begin(), (a).end()
#define MOD ((ll)1e9+7)
using namespace std::chrono;
using namespace std;
using namespace __gnu_pbds;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=2e5+5;
vector<int> adj[maxN];
vector<vector<int>> edges;
int cost[maxN];
vector<int> vals;
vector<vector<int>> comp;
int seen[maxN];
void dfs(int u){

    seen[u]=true;
    for (int v: adj[u]){
        if (!seen[v]) dfs(v);
    }
    vals.pb(u);
}
void dfs2(int u,vector<int> &c){
    seen[u]=true;
    for (int v:adj[u]){
        if (!seen[v]) dfs2(v,c);
    }
    c.pb(u);
}
void solve(){
    int n; cin>>n;
    FOR(n) cin>>cost[i+1];
    FOR(n) seen[i]=false;
    int m; cin>>m;
    FOR(m){
        int a,b; cin>>a>>b;
        adj[a].pb(b);
        edges.pb(vector<int>{b,a});
    }
    FOR(n){
        if (seen[i+1]) continue;
        dfs(i+1);
    }
    FOR(n){
        adj[i+1].clear();
        seen[i+1]=false;
    }
    for (auto &x : edges){
        adj[x[0]].pb(x[1]);
    }
    while (vals.size()){
        int v=vals[vals.size()-1];
        vals.pop_back();
        if (!seen[v]){
            vector<int> c;
            dfs2(v,c);
            comp.pb(c);
        }
    }
    ll ans=1;
    ll ans2=0;
    for (auto &x: comp){
        int v=cost[x[0]],f=1;
        //FOR(x.size()) cout<<x[i]<<' ';
       // cout<<endl;
        for (int i=1;i<x.size();i++){
            if (cost[x[i]]<v){
                v=cost[x[i]];
                f=1;
            }
            else f+=(cost[x[i]]==v);
        }
        ans*=f;
        ans%=MOD;
        ans2+=v;
    }
    cout<<ans2<<' '<<ans<<endl;
}
void precompute(){
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(15);
    precompute();
    int t=1;
    while (t--){
        solve();
    }
}
