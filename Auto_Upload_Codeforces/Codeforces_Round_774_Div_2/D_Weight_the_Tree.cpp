#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<int,int> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define endl '\n'
#define print(x) cout<<x<<'\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
#define MOD ((ll)1e9+7)
using namespace std;
using namespace __gnu_pbds;
const int maxN=2e5+1;
pair<int,int> dp[maxN][2];
int out[maxN];
int w[maxN];
vector<int> adj[maxN];
void dfs(int u, int v, int p){
    if (dp[u][v].F!=-1) return;
    dp[u][v].F=v;
    dp[u][v].S=(v==1 ? -1*out[u] : -1);
    for (int x: adj[u]){
        if (x!=p){

            dfs(x,0,u);
        if (v==1 && (out[x]>1 || out[u]>1)){
            dfs(x,0,u);
            dp[u][v].F+=dp[x][0].F;
            dp[u][v].S+=dp[x][0].S;
        }
        else{
            dfs(x,1,u);
            dp[u][v].F+=max(dp[x][0],dp[x][1]).F;
            dp[u][v].S+=max(dp[x][0],dp[x][1]).S;
        }
        }
    }
}
void assign(int u,int v, int p){
    if (v==0){
        w[u]=1;
    }
    else w[u]=out[u];
    for (int x: adj[u]){
        if (x!=p){
        if (v==1 && (out[x]>1 || out[u]>1)){
            assign(x,0,u);
        }
        else{
            if (dp[x][0]>dp[x][1]){
                assign(x,0,u);
            }
            else{
                assign(x,1,u);
            }
        }
        }
    }
}
void solve(){
    int n; cin>>n;
    FOR(n+1) dp[i][0]=dp[i][1]=mp(-1,-1);
    FOR(n-1){
        int a,b; cin>>a>>b;
        adj[a].pb(b),adj[b].pb(a);
        out[a]++;
        out[b]++;
    }
    dfs(1,1,-1);
    dfs(1,0,-1);
    if (dp[1][0]>dp[1][1]){
        cout<<dp[1][0].F<<' '<<-1*dp[1][0].S<<'\n';
        assign(1,0,-1);
    }
    else{
        cout<<dp[1][1].F<<' '<<-1*dp[1][1].S<<'\n';
        assign(1,1,-1);
    }
    for (int i=1;i<=n;i++) cout<<w[i]<<' ';
    cout<<'\n';
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
    while (t--){
        solve();
    }
}
