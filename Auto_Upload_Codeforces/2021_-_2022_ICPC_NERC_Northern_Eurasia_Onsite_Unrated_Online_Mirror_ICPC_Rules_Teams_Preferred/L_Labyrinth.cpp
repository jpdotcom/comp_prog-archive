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
#define MOD (ll)(1e9+7)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
const int maxN=2e5+1;
int r[maxN];
int parent[maxN];
vi adj[maxN];
vi out;
int s;
void path(int u,int v){
    while (u!=v){
        out.pb(u);
        u=parent[u];
    }
    out.pb(v);
    reverse(out.begin(),out.end());
    cout<<out.size()<<endl;
    for (int x: out) cout<<x<<' ';
    cout<<endl;
    out.clear();
}
bool dfs(int u, int p, int root){
    if ((r[u]!=0 && r[u]!=root) || (u==r[u])){
        print("Possible");
        out.pb(u);
        path(p,s);
        path(u,s);
        return true;
    }
    parent[u]=p;
    r[u]=root;
    bool ok=false;
    for (int v:adj[u]){
        if (v!=s && r[v]!=root && v!=p)
        {
            ok|=dfs(v,u,root);
            if (ok) return true;
        }
    }
    return false;
}
void solve(){
    int n,m; cin>>n>>m;
    cin>>s;
    FOR(n+1) r[i]=parent[i]=0;
    FOR(m){
        int a,b; cin>>a>>b;
        adj[a].pb(b);
    }
    bool ok=false;
    for (int v:adj[s]){
        ok|=dfs(v,s,v);
        if (ok) break;
    }

    if (!ok) print("Impossible");
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    while (t--){
        solve();
    }
}
