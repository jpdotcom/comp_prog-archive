#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<long long> vi;
typedef std::pair<int,int> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
#define MOD (2012)
using namespace std;
const int maxN=1e6+1;
int a[maxN];
vi adj[maxN];
void solve(){
    int n,m; cin>>n>>m;
    FOR(n){
        int v; cin>>v;
        a[i+1]=v;
    }
    FOR(n+1) adj[i].clear();
    FOR(m){
        int u,v; cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int ans=1e9+7;
    if (m%2==0){
        print(0);
        return;
    }
    FOR(n){
        if (adj[i+1].size()%2==1) ans=min(ans,a[i+1]);
        else{
            for (int j=0;j<(int)adj[i+1].size();j++){
                if (adj[adj[i+1][j]].size()%2==0) ans=min(ans,a[i+1]+a[adj[i+1][j]]);
            }
        }
    }
    print(ans);

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
