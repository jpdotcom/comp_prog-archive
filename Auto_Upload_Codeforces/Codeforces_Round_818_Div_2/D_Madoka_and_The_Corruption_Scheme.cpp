#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<long long,long long> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
#define MOD ((ll)1e9+7)
using namespace std;
const int maxN=1e6;
ll inv[maxN];
ll fac[maxN];
ll bpow(ll a,ll b){
    if (b==0) return 1;
    ll val=bpow(a,b/2);
    return val*val%MOD*(b&1 ? a : 1) %MOD;
}
ll nCr(int a, int b){
    if (a<b || a<0 || b<0) return 0;
    return fac[a]*inv[a-b]%MOD*inv[b]%MOD;
}
void solve(){
    int n,k; cin>>n>>k;
    ll ans=0;
    for (int i=0;i<=min(n,k);i++){
        ans+=nCr(n,i);
        ans%=MOD;
    }
    print(ans);
}
void precompute(){

    fac[0]=1;
    for (int i=1;i<maxN;i++) fac[i]=fac[i-1]*i%MOD;
    inv[0]=1;
    for (int i=1;i<maxN;i++) inv[i]=(inv[i-1]*bpow(i,MOD-2))%MOD;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    while (t--) solve();
}
