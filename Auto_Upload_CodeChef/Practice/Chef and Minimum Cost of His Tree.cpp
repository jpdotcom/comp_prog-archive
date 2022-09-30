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
const int maxN=3e5+1;
ll L[maxN];
ll R[maxN];
ll A[maxN];
ll dp[maxN][2];
ll V[maxN];
vi adj[maxN];
int n;
ll median(vi vals, int l, int r){
    sort(vals.begin(),vals.end());
    ll median=vals[vals.size()/2];
    if (vals.size()%2==0) median=(median+vals[vals.size()/2-1])/2;
    if (median<l) return l;
    if (median>r) return r;
    return median;

}
void dfs(int u, int p, int t){
    if (dp[u][t] != INF) return;
    dp[u][t]=0;
    vi vals;
    for (int v:adj[u]){
        if (v!=p){
            dfs(v,u,0);
            dfs(v,u,1);
            if (t!=1){
                vals.pb(A[v]);
            }
            else{
                dp[u][t]+=min(abs(V[v]-A[u])+dp[v][0],abs(A[v]-A[u])+dp[v][1]);
            }
        }
    }
    if (p!=-1) vals.pb(A[p]);
    if (t!=1 && vals.size()!=0){
        ll d=median(vals,L[u],R[u]);
        V[u]=d;
        for (int v:adj[u]){
            if (v!=p){
                dp[u][t]+=abs(V[u]-A[v])+dp[v][1];
            }
        }
    }
}
void solve(){
    cin>>n;
    FOR(n+1) adj[i].clear();
    FOR(n+1) dp[i][0]=dp[i][1]=INF;
    FOR(n){
        int a,b,c; cin>>a>>b>>c;
        L[i+1]=a;
        R[i+1]=c;
        A[i+1]=b;
    }
    FOR(n-1){
        int a,b; cin>>a>>b; adj[a].pb(b),adj[b].pb(a);
    }
    dfs(1,-1,0),dfs(1,-1,1);
    print(min(dp[1][0],dp[1][1]));
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
