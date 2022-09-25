#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<long long,long long> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
#define MOD ((ll)1e9+7)
using namespace std;
const int maxN=2e5+1;
int deg[maxN];
vi adj[maxN];
int ans[maxN];
map<pi,int> edge;
void dfs(int u, int p, int v){
    int other=(v==2 ? 3 : 2);
    for (int k:adj[u]){
        if (k!=p){
            ans[edge[mp(k,u)]]=v;
            dfs(k,u,other);
        }
    }
}
void solve(){
    int n; cin>>n;
    FOR(n+1){
        deg[i]=0,adj[i].clear();
    }
    FOR(n-1){
        int a,b; cin>>a>>b;adj[a].pb(b),adj[b].pb(a);
        deg[a]++;
        deg[b]++;
        edge[mp(a,b)]=i+1;
        edge[mp(b,a)]=i+1;
    }
    int f=1;
    FOR(n){
        if (deg[i+1]>=3){
            print(-1);
            return;
        }
        else if (deg[i+1]==1) f=i+1;
    }
    dfs(f,-1,3);
    FOR(n-1) cout<<ans[i+1]<<' ';
    cout<<endl;
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(15);
    precompute();
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }
}
