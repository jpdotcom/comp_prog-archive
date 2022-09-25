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
const int maxN=2e5+10;
vi adj[maxN];
int need[maxN];
int k;
int dfs(int u, int p,int r){

    vi vals;
    for (int v:adj[u]){
        if (v!=p) vals.pb(dfs(v,u,r));
    }
    sort(vals.begin(),vals.end());
    int a=(vals.size()>0 ? vals[vals.size()-1] : 0);
    int b=(vals.size()>1 ? vals[vals.size()-2]: 0);
    if (u==r){
        return a+b+need[u];
    }
    else return a+need[u];
}
void solve(){
    int n; cin>>n;
    FOR(n-1){
        int a,b; cin>>a>>b;
        adj[a].pb(b),adj[b].pb(a);
    }
    int q; cin>>q;
    FOR(q){
        cin>>k;
        FOR(n+1) need[i]=0;
        int s=0;
        FOR(k){
            int v; cin>>v;
            s=v;
            need[v]=1;
        }
        print(((dfs(s,-1,s))==k ? "YES" : "NO"));
        //else print("NO");
    }
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int t=1;
    while (t--){
        solve();
    }
}
