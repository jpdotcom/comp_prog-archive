#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<long long> vi;
typedef long long ll;
typedef std::pair<ll,ll> pi;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define endl '\n'
#define print(x) cout<<x<<'\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+10)
#define all(a) (a).begin(), (a).end()
#define MOD ((ll)1e9+7)
using namespace std;
using namespace __gnu_pbds;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=1e6+1;
vector<int> adj[maxN];
int p[maxN];
int c;
ll ans;
void dfs(int u=1,int x=-1){
    p[u]=x;
    for (int v:adj[u]){
        if (v!=x) dfs(v,u);
    }
}
bool dfs2(int u){

    int par=p[u];
    int mult=c-1-(par!=-1);
    int ok=false;
    for (int v: adj[u]){
        if (v!=par){
            ok|=(mult<=0);
            ans*=mult--;
            ans%=MOD;
            ok|=dfs2(v);
        }
    }
    return ok;
}
void solve(){
    int n; cin>>n>>c;
    ans=c;
    FOR(n-1){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b),adj[b].pb(a);
    }
    dfs();
    int ok=dfs2(1);
    if (ok) print(0);
    else print(ans);
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
