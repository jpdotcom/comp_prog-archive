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
const int maxN=2e5+1;
int seen[maxN];
int p[maxN];
int give[maxN];
vi adj[maxN];
int ans;
void dfs(int u){
    if (seen[u]) return;
    seen[u]=true;
    for (int v:adj[u]){
        if (!seen[v]) dfs(v);
        if (p[v]==-1){
            ans++;
            p[v]=u;
            give[u]=v;
        }
    }
}
int cycle(int u, int orig){
    if (give[u]==0) return 0;
    else if (give[u]==orig) return 1;
    return cycle(give[u],orig);
}
void solve(){
    int n; cin>>n;
    ans=0;
    FOR(n+1){
        p[i]=-1; seen[i]=0; adj[i].clear();
        give[i]=0;
    }
    FOR(n){
        int b; cin>>b;
        adj[i+1].pb(b);
    }
    FOR(n) dfs(i+1);
    vector<vi> paths;
    vi out(n+1);
    FOR(n){
        if (p[i+1]==-1 && cycle(i+1,i+1)==0){
            int u=i+1;
            vi add;
            while (u!=0){
                add.pb(u);
                u=give[u];
            }
            paths.pb(add);
        }
    }
    if (paths.size()==1 && paths[0].size()==1){
        int v=paths[0][0];
        int a=adj[v][0];
        int u=p[a];
        p[a]=v;
        give[v]=a;
        p[v]=u;
        give[u]=v;
    }
    else{
        FOR((int) paths.size()) give[paths[i][paths[i].size()-1]]=paths[(i+1)%paths.size()][0];
    }
    cout<<ans<<endl;
    FOR(n) cout<<give[i+1]<<' ';
    cout<<endl;
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
