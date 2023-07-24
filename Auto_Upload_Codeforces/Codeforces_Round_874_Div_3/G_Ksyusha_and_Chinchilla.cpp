#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(a) for(int i=0;i<(int)a;i++)
#define mp(a,b) make_pair(a,b)
#define all(a)  a.begin(),a.end()
typedef std::vector<long  long> vi;
typedef std::pair<int,int> pi;
typedef long long ll;
#define F first
#define S second
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>(s))&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+10)
#define MOD ((ll)998244353)
using namespace std;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=1e6+1;
vector<pi> adj[maxN];
set<int> edges;
int c[maxN];
map<pi,int> num;
int start;
bool isBranch(int a, int b){
    return (c[a]==0 && c[b]==0);
}
void dfs1(int u, int p=-1){
    for (pi pa:adj[u]){
        int v=pa.F;
        if (v!=p){
            c[u]++;
            dfs1(v,u);
        }
    }
}
bool dfs2(int u,int p=-1){
    int TC=0;
    for (pi pa:adj[u]){
        int v=pa.F;
        if (v!=p){
            int ans=dfs2(v,u);
            if (!ans) return false;
            TC+=c[v];
        }
    }
    if (c[u]>2) return false;
    if (c[u]==2 && TC==0){
        c[u]-=2;
        if (p!=-1){
            c[p]--;
            edges.insert(num[mp(u,p)]);
        }
    }
    if (c[u]==2 && !TC) return false;
    if (c[u]==1){
        if (p!=-1){
            c[p]++;
            c[u]--;
        }
    }
    return true;
}
/*void dfs3(int u,int p, int cnt=1){
    if (cnt==4){
        edges.insert(num[mp(u,p)]);
    }
    for (pi pa: adj[u]){
        int v=pa.F;
        if (v!=p) dfs3(v,u,cnt+1);
    }
}
bool check(int u,int p){
    if (c[u]>1 && u!=1) return false;
    if (c[u]==0){
        start=u;
    }
    bool ans=true;
    for (pi pa: adj[u]){
        int v=pa.F;
        if (v!=p && edges.find(num[mp(v,u)])==edges.end()) ans&=check(v,u);
    }
    return ans;
}
*/
void solve(){
    int n; cin>>n;
    edges.clear();
    FOR(n+1){
        adj[i].clear();
        c[i]=0;
    }
    FOR(n-1){
        int a,b; cin>>a>>b;
        adj[a].pb({b,i+1}),adj[b].pb({a,i+1});
        num[mp(a,b)]=num[mp(b,a)]=i+1;
    }
    if (n%3){
        print(-1);
        return;
    }
    dfs1(1,-1);
    int val=dfs2(1,-1);
    if (!val){
        print(-1);
        return;
    }
    int u=0;
    for (int i=1;i<=n;i++){
        if (c[i]==0) u=i;
    }
    /*val=check(1,-1);
    if (!val){
        print(-1);
        return;
    }
    if (c[1]>0) dfs3(start,-1);
    */
    cout<<edges.size()<<endl;
    for (int x: edges) cout<<x<<' ';
    cout<<endl;
}
void precompute(){
   
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(15);
    precompute();
    int t=1;
    int i=1;
    cin>>t;
    while (t--)
    {
        solve();
        ++i;
    }
}
