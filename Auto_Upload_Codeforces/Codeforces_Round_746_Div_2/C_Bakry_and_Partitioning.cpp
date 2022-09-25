#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
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
vi adj[maxN];
int XOR[maxN];
int a[maxN];
pi v;
int c;
int dfs2(int u, int p){
    XOR[u]=a[u];
    for (int v:adj[u]){
        if (v!=p) XOR[u]^=dfs2(v,u);
    }
    return XOR[u];
}
int dfs(int u, int p){
    int ok=0;
    for (int v:adj[u]){
        if (v!=p) ok|=dfs(v,u);
    }
    if (!ok){
        if (XOR[u]==c){
            v=mp(p,u);
            ok|=1;
        }
    }
    return ok;
}
void solve(){
    int n,k; cin>>n>>k;
    v.F=v.S=-1;
    FOR(n+1){
        XOR[i]=0;
        adj[i].clear();
    }
    c=0;
    FOR(n) cin>>a[i+1];
    FOR(n-1){
        int a,b; cin>>a>>b;
        adj[a].pb(b), adj[b].pb(a);
    }
    dfs2(1,-1);
    c=XOR[1];
    dfs(1,-1);
    int ok=0;
    ok|=(XOR[1]==0);
    if (v.F!=-1 && k>2){
        for (int i=0;i<(int)adj[v.F].size();i++){
            if (adj[v.F][i]==v.S) adj[v.F].erase(adj[v.F].begin()+i);
        }
        v=mp(-1,-1);
        dfs2(1,-1);
        dfs(1,-1);
        ok|=(v.F!=-1);
    }
    if (ok) print("YES");
    else print("NO");

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


