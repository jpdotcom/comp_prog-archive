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
vector<pi> adj[maxN];
vector<vector<ll>> edges;
ll dist[maxN];
int seen[maxN];
int n;
void dij(){
    priority_queue<pair<long long,int>> q;
    for (int i=1;i<=n;++i){
        if (dist[i]!=INF){
            q.push(mp(-1*dist[i],i));
        }
    }

    while (q.size()){
        int u=q.top().S;q.pop();
        if (!seen[u]){
        seen[u]=true;
        for (auto p: adj[u]){
            if (!seen[p.F] && dist[p.F]>dist[u]+p.S){
                dist[p.F]=dist[u]+p.S;
                q.push(mp(-1*(dist[u]+p.S),p.F));
            }
        }
        }
    }
    return;
}
void solve(){
    int m; cin>>n>>m;
    FOR(n+1){
        dist[i]=INF;
        seen[i]=false;
    }
    FOR(m){
        int a,b,w; cin>>a>>b>>w;
        edges.pb(vector<ll>{a,b,w});
        adj[a].pb(mp(b,w));
    }
    dist[1]=0;
    dij();
    FOR(n+1){
        adj[i].clear();
        seen[i]=false;
    }
    for (auto &x: edges){
        adj[x[1]].pb(mp(x[0],x[2]));
    }
    dij();
    for (int i=2;i<n+1;++i){
        ll out=dist[i];
        if (out==INF) cout<<-1<<' ';
        else cout<<out<<' ';
    }
    cout<<endl;
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
