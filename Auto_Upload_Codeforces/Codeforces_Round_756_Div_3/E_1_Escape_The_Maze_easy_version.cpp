#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<int,int> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<int> pq;
#define put push
#define endl '\n'
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
const int maxN=2e5+1;
int t[maxN];
int dist[maxN];
vi adj[maxN];
const int INF=1e9+6;
void solve(){
    int n,k; cin>>n>>k;
    FOR(n+1){
        adj[i].clear();
        dist[i]=INF,t[i]=0;
    }
    vi vals(k);
    FOR(k) cin>>vals[i];
    FOR(n-1){
        int a,b; cin>>a>>b;
        adj[a].pb(b), adj[b].pb(a);
    }
    queue<int> q;
    q.put(1);
    dist[1]=0;
    t[1]=1;
    while (q.size()){
        int u=q.front();
        q.pop();
        for (int v:adj[u]){
            if (dist[v]==INF){
                dist[v]=dist[u]+1;
                t[v]=1;
                q.put(v);
            }
        }
    }
    for (int c: vals){
        q.put(c);
        dist[c]=0;
        t[c]=2;
    }
    while (q.size()){
        int u=q.front();
        q.pop();
        for (int v:adj[u]){
            if (t[v]!=2 && dist[u]+1<=dist[v]){
                t[v]=2;
                dist[v]=dist[u]+1;
                q.put(v);
            }
        }
    }
    bool ok=false;
    for (int i=2;i<=n;i++){
        ok|=(adj[i].size()==1 && t[i]==1);
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


