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
map<ll,int> cnt;
set<ll> vals;
void solve(){
    int n; cin>>n;
    for (int i=0;i<n;i++){
        char c;
        ll v;
        cin>>c>>v;
        if (c=='+'){
            vals.insert(v);
        }
        else{
            if (cnt.find(v)==cnt.end()) cnt[v]=0;
            while (vals.find(v*(cnt[v]+1)) != vals.end()) cnt[v]++;
            print((ll)(cnt[v]+1)*v);
        }
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

