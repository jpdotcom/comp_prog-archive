#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<int,int> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<pi> pq;
#define endl '\n'
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define MOD (int)1e9+7
#define iset tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
ll modu(ll a,ll b){
    return (b+(a%b)) % b;
}
ll power(ll x, ll y, ll p)
{
    ll res = 1;     
    x = x % p; 
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1) res=modu(res*x,p);
        y = y>>1; 
        x = modu((x*x),p);
    }
    return res;
}
void fileIO(string filename) {
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
const int maxN=4005;
vector<int>adj[maxN];
int cnt[maxN];
int black[maxN];
int dfs(int u){
    if (cnt[u]!=-1) return cnt[u];
    cnt[u]=1;
    int bal=0;
    for (int v:adj[u]){
        bal+=dfs(v);
        cnt[u]+=cnt[v];
        black[u]+=black[v];
    }
    bal+=(cnt[u]-black[u]==black[u]);
    return bal;
}
void solve(){
    int n;
    cin>>n;
    FOR(n+1){
        cnt[i]=-1;
        black[i]=0;
        adj[i].clear();
    }
    for (int i=2;i<=n;i++){
        int val;cin>>val;
            adj[val].pb(i);
    }
    string s;
    cin>>s;
    FOR((int) s.size()){
        if (s[i]=='B') black[i+1]++;
    }
    print(dfs(1));
}
void precompute(){
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(15);
    precompute();
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }
}
