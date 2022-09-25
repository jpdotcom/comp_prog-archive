#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<int, int> pi;
typedef long long ll;
typedef std::priority_queue<int> pq;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define iset tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
#define all(a) a.begin(),a.end()
using namespace std;
using namespace __gnu_pbds;
const int maxN=1e6;
map<pi,int> edge;
int seen[maxN];
int used[maxN];
map<int,int> cnt;
vector<int> adj[maxN];
void dfs(int u,int p){
    seen[u]=1;
    for (int v: adj[u]){
        if (v==p) continue;
        else if (seen[v]){
            used[edge[mp(u,v)]]=1;
            cnt[u]++,cnt[v]++;
            continue;
        }
        dfs(v,u);
    }
    return;
}
bool dfs2(int u,  int v, vector<int>&path,int p=-1){
    path.pb(u);
    if (u==v) return true;
    for (int x: adj[u]){
        if (used[edge[mp(u,x)]]==0 && x!=p){
            bool c=dfs2(x,v,path,u);
            if (c) return c;
        }
    }
    path.pop_back();
    return false;
}
void solve(){
    int n,m; cin>>n>>m;
    edge.clear();
    cnt.clear();
    FOR(n+1) adj[i].clear();
    FOR(m){
        int a,b; cin>>a>>b;
        adj[a].pb(b),adj[b].pb(a);
        edge[mp(a,b)]=edge[mp(b,a)]=i;
    }
    FOR(m+1) used[i]=0;
    FOR(n+1){
        seen[i]=0;
    }
    dfs(1,-1);
    if (m==n+2){
        vector<int> vals;
        for (auto it: cnt){
            vals.pb(it.F);
        }
        if (vals.size()==3){
        vector<int> path;
        dfs2(vals[0],vals[1],path);
        used[edge[mp(vals[0],vals[1])]]=0;
        used[edge[mp(path[1],vals[0])]]=1;
        }
    }

    FOR(m) cout<<used[i];
    cout<<endl;
}
void precompute(){

}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    cin>>t;
    while (t--) solve();
}
