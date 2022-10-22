#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<long long,long long> pi;
#define mp(a,b) make_pair(a,b)
#define all(a) a.begin(),a.end()
typedef long long ll;
typedef std::priority_queue<int> pq;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define MOD (ll)(998244353)
#define INF ((ll)1e18)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
//using u64 = uint64_t;
//using u128 = __uint128_t;
const int maxN=1e6+10;
vector<int> adj[maxN];
vector<pair<int,ll>> pos[maxN];
vector<int> s(maxN);
long long dfs(int u, int k){
    for (auto x: pos[u]){
        if (x.F==k) return x.S;
    }
    int cnt=adj[u].size();
    ll ans=(ll)s[u]*k;
    vector<ll> diff;
    if (cnt==0){
        pos[u].pb(mp(k,ans));
        return ans;
    }
    if (k%cnt==0){
        for (int v: adj[u])
            ans+=dfs(v,k/cnt);
    }
    else{for (int v: adj[u]){
        ll v1=dfs(v,k/cnt);
        ll v2=dfs(v,k/cnt+1);
        ans+=v1;
        diff.pb(v2-v1);
    }

    sort(all(diff));
    for (int i=diff.size()-1,j=0;(~i) && j<k%cnt ;i--,j++){
        if (diff[i]<0) break;
        ans+=diff[i];
    }
    }
    pos[u].pb(mp(k,ans));
    return ans;
}
void solve(){
    int n,k; cin>>n>>k;
    FOR(n+1) pos[i].clear();
    FOR(n+1) adj[i].clear();
    for (int i=0;i<n-1;i++){
        int x; cin>>x;
        adj[x].pb(i+2);
    }
    FOR(n) cin>>s[i+1];
    print(dfs(1,k));
}
void precompute(){
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cout<<setprecision(15);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    cin>>t;
    int i=0;
    while (t--){
        //cout<<"Case #" << (i+1) << ": ";
        solve();
        ++i;
    }
}

