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
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
#define MOD ((ll)1e9+7)
using namespace std;
const int maxN=5e5+1;
map<ll,ll> cnt;
ll a[maxN];
ll orSum[maxN];
ll power(ll a, ll b){
    if (b==0) return 1;
    ll v=power(a,b/2);
    if (b&1) return v*v%MOD*a%MOD;
    else return v*v%MOD;
}
void solve(){
    ll n; cin>>n;
    cnt.clear();
    FOR(n){
        ll v; cin>>v;
        a[i]=v;
        orSum[i]=0LL;
        for (int j=0;j<61;j++)
            if (bit(v,j))
                cnt[j]++;
    }
    FOR(n){
        for (int j=0;j<60;j++){
            if (bit(a[i],j)) orSum[i]+=(1LL<<j)%MOD*n%MOD;
            else orSum[i]+=(1LL<<j)%MOD*cnt[j]%MOD;
            orSum[i]%=MOD;
        }
    }
    ll ans=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<60;j++){
            if (bit(a[i],j)){
                ans+=cnt[j]*((1LL<<j)%MOD)%MOD*orSum[i]%MOD;
                ans%=MOD;
            }
        }
    }
    print(ans);
}
void precompute(){
}
int main(){
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
