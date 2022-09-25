#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(a) for (int i=0;i<a;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<long long,long long> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF (1e9)
#define endl '\n'
#define MOD ((int)998244353)
using namespace std;
const int maxN=1e6;
int color[maxN];
int deg[maxN];
vector<int> adj[maxN];
void dfs(int u=1,int p=-1){
    for (int v:adj[u]){
        if (v!=p){
            color[v]=color[u]^1;
            dfs(v,u);
        }
    }
}
void solve(){
    int n; cin>>n;
    FOR(n+1){
        adj[i].clear();
        color[i]=deg[i]=0;
    }
    FOR(n-1){
        int a,b; cin>>a>>b;
        adj[a].pb(b),adj[b].pb(a);
        deg[a]++,deg[b]++;
    }
    dfs();
    for (int i=1;i<n+1;++i) cout<<(color[i] ? 1: -1)*deg[i]<<' ';
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
    while (t--) solve();
}
