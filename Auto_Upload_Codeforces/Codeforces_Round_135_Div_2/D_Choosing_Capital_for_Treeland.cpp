#include <bits/stdc++.h>
#define FOR(b) for (int i=0;i<b;i++)
#define endl '\n';
#define F first
#define S second 
#define mp make_pair
#define print(x) cout<<x<<'\n'
#define pb push_back 
typedef std::vector<long long> vi;
typedef std::pair<long long, long long> pi;
typedef long long ll;
using namespace std;
ll modu(ll a,ll b){
    return (b+(a%b)) % b;
}
int power(long long x, unsigned int y, ll p)
{
    unsigned long long res = 1;     // Initialize result
 
    x = x % p; // Update x if it is more than or
                // equal to p
 
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
void precompute(){
}
const int maxN=2e5+5;
vector<int>adj[maxN];
int val[maxN];
set<pi>edges;
int ans[maxN];
void dfs(int u,int p){
    for (int v:adj[u]){
        if (v!=p){
            val[v]=(edges.find(make_pair(u,v)) == edges.end());
            dfs(v,u);
        }
    }
}
void dfs2(int u,int p,int sc,int ec,int tot){
    sc+=val[u];
    ec++;
    ans[u]=tot+ec-2*sc;
    for (int v:adj[u]){
        if (v!=p) dfs2(v,u,sc,ec,tot);
    }
}
void solve(){
    int n;
    cin>>n;
    FOR(n-1){
        int a,b;
        cin>>a>>b;
        edges.insert(make_pair(a,b));
        adj[a].pb(b),adj[b].pb(a);
    }
    dfs(1,0);
    int tot=0;
    for (int i=1;i<=n;i++){
        tot+=val[i];
    }
    dfs2(1,0,0,-1,tot);
    int min_ans=n+100;
    vi out;
    for (int i=1;i<=n;i++){
        min_ans=min(min_ans,ans[i]);
    }
    for (int i=1;i<=n;i++){
        if (min_ans==ans[i]){
            out.pb(i);
        }
    }
    print(min_ans);
    for (int x:out) cout<<x<<' '; 
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(25);
    precompute();
    int t=1;
    while (t--){
        solve();
    }
}

