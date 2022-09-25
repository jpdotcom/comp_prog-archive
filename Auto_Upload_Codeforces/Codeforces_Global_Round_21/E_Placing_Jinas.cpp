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
#define endl '\n'
#define print(x) cout<<x<<'\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
#define MOD ((ll)1e9+7)
using namespace std;
using namespace __gnu_pbds;
const int maxN=1e6+1;
ll fac[maxN];
ll pow(ll a, ll b){
    if (b==0) return 1;
    ll val=pow(a,b/2);
    if (b&1) return val*val%MOD*a%MOD;
    else return val*val%MOD;
}
ll inv(ll a){
    return pow(a,MOD-2);
}
ll nCr(int a, int b){
    if (a<b) return 0;
    return fac[a]*inv(fac[a-b])%MOD*inv(fac[b])%MOD;
}
void solve(){
    int n;
    cin>>n;
    ll ans=0;
    FOR(n+1){
        int v; cin>>v;
        ans+=nCr(i+v,i+1);
        ans%=MOD;
    }
    print(ans);
}
void precompute(){
    fac[0]=1;
    for (int i=1;i<maxN;i++){
        fac[i]=fac[i-1]*i%MOD;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(15);
    precompute();
    int t=1;
    while (t--){
        solve();
    }
}
