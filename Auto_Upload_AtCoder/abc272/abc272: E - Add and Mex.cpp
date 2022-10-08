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
#define INF ((int)1e9+7)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=4e5;
int seen[maxN];
void solve(){
    int n,m; cin>>n>>m;
    FOR(n+2) seen[i]=0;
    vector<vector<pi>> add(m+1);
    vector<pi> curr;
    FOR(n){
        int a; cin>>a;
        if (a>=0){
            if (a>n) continue;
            curr.pb(mp(a,i+1));
            seen[a]++;
        }
        else{
            int t=ceil(-1.0*a/(i+1));
            if (t<=m){
                add[t].pb(mp(a+(i+1)*t,i+1));
            }
        }
    }
    for (int i=1;i<=m;i++){
        vector<pi> nc;
        for (auto x: curr){
            if (x.F+x.S<=n){
                seen[x.F]--;
                seen[x.F+x.S]++;
                nc.pb(mp(x.F+x.S,x.S));
            }
            else seen[x.F]--;
        }
        for (auto x: add[i]){
            nc.pb(x);
            seen[x.F]++;
        }
        int ans=0;
        for (int j=0;j<n+1;j++){
            assert(seen[j]>=0);
            if (seen[j]) ans++;
            else break;
        }
        curr=nc;
        print(ans);
    }
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
    while (t--){
        solve();
    }
}

