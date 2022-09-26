#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<long long,long long> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<int> pq;
#define endl '\n'
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define MOD (ll)(1e9+7)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
const int maxN=3e5+4;
ll fac[maxN];
ll inv[maxN];
ll power(ll a, ll b){
    if (b==0) return 1;
    if (b&1) return (a*power(a,b-1))%MOD;
    ll v=power(a,b/2);
    return (v*v)%MOD;
}
ll ginv(ll a){
    return power(a,MOD-2);
}
ll nCr(ll a, ll b){
    if (a<0 || b<0 || a<b) return 0;
    return fac[a]*inv[a-b]%MOD*inv[b]%MOD;
}
void solve(){
    ll n,k; cin>>n>>k;
    ll ans=0;
    if ((n&1)==0){
        for (int i=1;i<=k;i++){
            ans+=power(power(2,n-1)-1,k-i)*power(2,(i-1)*n)%MOD;
            ans%=MOD;
        }
        ans+=power(power(2,n-1)-1,k);
        ans%=MOD;
    }
    else{
        for (int i=1;i<=k;i++){
            ans+=(nCr(k,i)*power(2,(n-1)*(k-i)))%MOD;
            ans%=MOD;
        }
        ans+=power(power(2,n-1),k);
        ans%=MOD;
    }
    print(ans);
}
void precompute(){
    fac[0]=1;
    for (int i=1;i<maxN;i++) fac[i]=(fac[i-1]*i) % MOD;
    for (int i=0;i<maxN;i++) inv[i]=ginv(fac[i]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }
}


