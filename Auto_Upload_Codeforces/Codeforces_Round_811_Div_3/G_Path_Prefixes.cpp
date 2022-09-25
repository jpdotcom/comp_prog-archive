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
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((int)1e9)
#define MOD ((ll)1e9+7)
using namespace std;
const int maxN=2e5+1;
const int l=20;
int seen[maxN];
int up[maxN][l];
vi adj[maxN];
ll sum[maxN];
ll limit[maxN];
int distup[maxN];
void dfs(int v, int p, ll s,ll lim,int d){
    up[v][0]=p;
    if (p==1) distup[v]=1;
    if (v==1) distup[v]=0;
    for (int i=1;i<l;++i){
        up[v][i]=up[up[v][i-1]][i-1];
    }
    sum[v]+=s;
    limit[v]+=lim;
    distup[v]=d;
    for (int x: adj[v]){
        if (x!=p){
            dfs(x,v,sum[v],limit[v],d+1);
        }
    }
}
int geta(int u, int k){
    if (k==0) return u;
    int l=k&-k;
    return geta(up[u][(int)log2(l)],k-l);
}
void solve(){
    int n; cin>>n;
    FOR(n+1) adj[i].clear();
    FOR(n+1){
        sum[i]=limit[i]=0;
    }
    FOR(n-1){
        int a,b,c; cin>>a>>b>>c;
        adj[a].pb(i+2);
        adj[i+2].pb(a);
        limit[i+2]=b;
        sum[i+2]=c;
    }
    dfs(1,1,0,0,0);
    vi out;
    for (int i=2;i<=n;i++){
        int low=0,high=n,best=0;
        while (low<=high){
            int mid=low+(high-low)/2;
            int v=geta(i,mid);
            if (sum[v]<=limit[i]){
                best=distup[v];
                high=mid-1;
            }
            else low=mid+1;
        }
        out.pb(best);
    }
    for (int x: out) cout<<x<<' ';
    cout<<endl;
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
    while (t--)
    {
        solve();
    }
}
