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
#define INF ((int)1e9+7)
#define MOD ((ll)998244353)
using namespace std;
const int maxN=1005;
vi adj[maxN];
ll dp[maxN];
bool seen[maxN];
ll a[maxN];
int n;
void calc(int u){
    if (seen[u]) return;
    seen[u]=true;
    dp[u]=0;
    for (int v:adj[u]){
        calc(v);
        dp[u]+=dp[v];
        dp[u]%=MOD;
    }
    if (dp[u]==0) dp[u]=1;
}
int simulate(){
    vi sub;
    for (int i=1;i<=n;i++)
        if (a[i]>=1)
            sub.pb(i);
    for (int x: sub){
        a[x]--;
        for (int v:adj[x]) a[v]++;
    }
    if (sub.size()==0) return 0;
    else return 1;
}
void solve(){
    int m; cin>>n>>m;
    FOR(n+1){
        adj[i].clear();
        seen[i]=0;
        a[i]=0;
        dp[i]=0;
    }
    int ok=0;
    FOR(n){
        cin>>a[i+1];
        if (a[i+1]!=0) ok=1;
    }
    FOR(m){
        int a,b; cin>>a>>b; adj[a].pb(b);
    }
    if (!ok){
        print(0);
        return;
    }
    FOR(n){
        int v=simulate();
        if (v==0){
            print(i);
            return;
        }
    }
    ll ans=0;
    FOR(n){
        if (!seen[i+1]) calc(i+1);
        ans+=(dp[i+1]*(a[i+1]%MOD))%MOD;
    }
    print((n+ans)%MOD);

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
