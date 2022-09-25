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
const int maxN=4e5+5;
vi adj[maxN];
int deg[maxN];
int ans[maxN];
void solve(){
    int n,k; cin>>n>>k;
    FOR(n){
        adj[i+1].clear();
        deg[i+1]=0;
    }
    FOR(n-1){
        int a,b;cin>>a>>b;
        adj[a].pb(b), adj[b].pb(a);
        deg[a]++,deg[b]++;
    }
    queue<int>q;
    FOR(n){
        ans[i+1]=0;
        if (deg[i+1]==1){
            q.push(i+1);
            ans[i+1]=1;
        }
    }
    while (!q.empty()){
        int u=q.front();
        q.pop();
        for (int v: adj[u]){
            if (deg[v]>1){
            deg[v]--;
            if (deg[v]==1){
                ans[v]=ans[u]+1;
                q.push(v);
            }
            }
        }
    }
    int s=0;
    FOR(n) s+=(ans[i+1]>k);
    print(s);
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
