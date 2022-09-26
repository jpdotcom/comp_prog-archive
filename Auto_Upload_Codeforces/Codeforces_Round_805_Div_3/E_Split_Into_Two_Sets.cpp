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
int c[maxN];
vi vals[maxN];
int seen[maxN];
int dfs(int u,int p){
    c[u]=p;
    seen[u]=1;
    for (int v:adj[u]){
        if (!seen[v] && c[v]==-1){
           int g= dfs(v,p^1);
           if (g==-1) return g;
        }
        else if (c[v]==c[u]) return -1;
    }
    return 1;
}
void solve(){
    int n; cin>>n;
    FOR(n+1){
        vals[i].clear();
        adj[i].clear();
        seen[i]=0;
        c[i]=-1;
    }
    bool ok=true;
    FOR(n){
        int a,b; cin>>a>>b;
        if (ok){
            if (vals[a].size()>=3){
                ok=false;
                continue;
            }
            if (vals[b].size()>=3){
                ok=false;
                continue;
            }
        for (int j=0;j<(int)vals[a].size();j++){
            adj[vals[a][j]].pb(i+1);
            adj[i+1].pb(vals[a][j]);
            if (adj[vals[a][j]].size()>=3){
                ok=false;
                break;
            }
        }
        for (int j=0;j<(int)vals[b].size();j++){
            adj[vals[b][j]].pb(i+1);
            adj[i+1].pb(vals[b][j]);
            if (adj[vals[b][j]].size()>=3){
                ok=false;
                break;
            }
        }

        vals[a].pb(i+1);
        vals[b].pb(i+1);
        if (a==b){
            ok=false;
            continue;
        }
        }
    }
    if (!ok){
        print("NO");
        return;
    }
    for (int i=1;i<=n;i++){
        if (!seen[i]){
            int v=dfs(i,0);
            if (v==-1){
                print("NO");
                return;
            }
        }
    }
    print("YES");
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
