#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
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
#define INF ((int)1e9)
#define MOD ((ll)1e9+7)
using namespace std;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=1e6+10;
ll pw2[maxN];
ll fac[maxN];
ll ifac[maxN];
ll power(ll a,ll b){
    if (b==0) return 1;
    ll v=power(a,b/2);
    return v*v%MOD*(b&1 ? a:1)%MOD;
}
ll nCr(int a,int b){
    if (a<b || a<0 || b<0) return 0;
    return fac[a]*ifac[a-b]%MOD*ifac[b]%MOD;
}
ll get_inv(ll a){
    return power(a,MOD-2);
}
void solve(){
    int n,k; cin>>n>>k;
    string s; cin>>s;
    ll ans=0;
    if (n==k) print(2);
    else if (k&1) print(power(2,n));
    else print(power(2,n-1));
}
void precompute(){
    pw2[0]=1;
    fac[0]=1;
    ifac[0]=1;
    for (int i=1;i<maxN;i++) pw2[i]=pw2[i-1]*2%MOD;
    for (int i=1;i<maxN;i++){
        fac[i]=fac[i-1]*i%MOD;
        ifac[i]=get_inv(fac[i]);
    }
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
