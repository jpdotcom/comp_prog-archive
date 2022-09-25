#include <bits/stdc++.h>
#define FOR(b) for (int i=0;i<b;i++)
#define endl '\n';
#define F first
#define S second 
#define mp make_pair
#define print(x) cout<<x<<'\n'
#define pb push_back 
#define MOD (ll)1e9+7
typedef std::vector<int> vi;
typedef std::pair<long long, long long> pi;
typedef long long ll;
using namespace std;
const int maxN=1e5+1;
int seen[maxN];
pi a[maxN];
vi adj[maxN];
void dfs(int u){
    seen[u]=1;
    for (int v:adj[u])
        if (!seen[v]) dfs(v);
    return;
}
void solve(){
    int n; cin>>n;
    FOR(n+1){
        seen[i]=0; adj[i].clear();
    }
    for (int j=0;j<2;j++){
    FOR(n){
        int u,v=i+1;
        cin>>u;
        a[i].F=u,a[i].S=v;
    }
    sort(a,a+n);
    FOR(n-1){
        int x1=a[i+1].S,x2=a[i].S;
        adj[x2].pb(x1);
    }
    }
    int mx=a[n-1].S;
    dfs(mx);
    for (int j=1;j<=n;j++) cout<<(int)seen[j];
    cout<<endl;
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }
}
