#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<long long,long long> pi;
#define mp(a,b) make_pair(a,b)
#define all(a) a.begin(),a.end()
typedef long long ll;
typedef std::priority_queue<int> pq;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define MOD (ll)(998244353)
#define INF ((int)1e9+7)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=3e5+10;
vector<int> cols[2];
vector<int> adj[maxN];
int l2[maxN];
void dfs(int u=1,int p=-1,int c=0){
    cols[c].pb(u);
    for (int v: adj[u]){
        if (v==p) continue;
        dfs(v,u,c^1);
    }
}
void solve(){

    int n; cin>>n;
    FOR(n+1) adj[i].clear();
    cols[0].clear(),cols[1].clear();
    FOR(n-1){
        int a,b; cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs();
    int idx=(cols[0].size()>cols[1].size() ? 1 : 0);
    int t=idx;
    int sz=cols[idx].size();
    vector<int> seen(n+1,0);
    vi used(n+1,0);
    int curr=0;
    for (int i=1;i<n+1;i++){
        if (bit(sz,l2[i])){
            seen[cols[t][curr++]]=i;
            used[i]=1;
        }
    }
    curr=0;
    for (int i=1;i<n+1;i++){
        if (!used[i]){
            seen[cols[t^1][curr++]]=i;
        }
    }
    for (int i=1;i<n+1;++i) cout<<seen[i]<<' ';
    cout<<endl;
}
void precompute(){
    l2[1]=0;
    for (int i=2;i<maxN;++i) l2[i]=l2[i/2]+1;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cout<<setprecision(15);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }
}

