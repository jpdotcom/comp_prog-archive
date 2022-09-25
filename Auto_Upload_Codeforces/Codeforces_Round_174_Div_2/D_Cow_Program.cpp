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
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF (-1e18)
#define endl '\n'
#define MOD ((int)1e9+7)
using namespace std;
const int maxN=1e6+1;
ll hasRoot[maxN][2];
ll proc[maxN][2];
ll ans[maxN][2];
ll a[maxN];
int n; 
ll dfs(int u,int v){
    if (u<=0 ||  u>n) return 0;
    if (ans[u][v]!=-1) return (ans[u][v]==INF ? INF : ans[u][v]);
    else if (proc[u][v]) return ans[u][v]=INF;
    else{
        proc[u][v]=1;
        ans[u][v]=(a[u]+dfs(u+(v ? a[u] : -1*a[u]),v^1));
        if (ans[u][v]<0) ans[u][v]=INF;
        int next=u+(v?a[u] : -1*a[u]);
        if(next>0 && next<=n) hasRoot[u][v]|=(hasRoot[next][v^1]);
        return ans[u][v];
    }
}
void solve(){
    cin>>n;
    FOR(n-1) cin>>a[i+2];
    FOR(n+1){
        ans[i][0]=ans[i][1]=-1;
        proc[i][0]=proc[i][1]=0;
        hasRoot[i][0]=hasRoot[i][1]=0;
    }
    hasRoot[1][1]=1;
    FOR(n){
        dfs(i+1,0);
        dfs(i+1,1);
    }
    for (int i=1;i<n;i++){
        if (ans[i+1][0]==INF || hasRoot[i+1][0]) print(-1);
        else print(i+ans[i+1][0]);
    }
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    while (t--) solve();
}
