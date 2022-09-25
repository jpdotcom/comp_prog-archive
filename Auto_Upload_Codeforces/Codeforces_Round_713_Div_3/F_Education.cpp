#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<long long> vi;
typedef long long ll;
typedef std::pair<ll,ll> pi;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define endl '\n'
#define print(x) cout<<x<<'\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((int)1e9+10)
#define all(a) (a).begin(), (a).end()
#define MOD ((ll)998244353)
using namespace std;
using namespace __gnu_pbds;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=1e6+1;
int a[maxN];
int b[maxN];
pi reach[maxN];
void solve(){
    ll n,c; cin>>n>>c;

    FOR(n) cin>>a[i];
    FOR(n-1) cin>>b[i+1];

    reach[0]=mp(0,0);

    for (int i=1;i<n;i++){
        ll dayse=max(0LL,(ll)ceil((b[i]-reach[i-1].S)/(long double)a[i-1]));
        reach[i].F=reach[i-1].F+dayse+1;
        reach[i].S=reach[i-1].S+dayse*a[i-1]-b[i];
    }
    ll ans=1e10;
    for (int i=0;i<n;i++){
        ll extra=reach[i].S;
        ll days=reach[i].F;
        ans=min(ans,days+max(0LL,(ll)ceil((c-extra)/(long double)a[i])));
    }
    print(ans);
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
    cin>>t;
    while (t--){
        solve();
        
    }
}
