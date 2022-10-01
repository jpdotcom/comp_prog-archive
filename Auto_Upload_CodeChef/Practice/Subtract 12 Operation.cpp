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
#define INF ((ll)1e18+10)
#define all(a) (a).begin(), (a).end()
#define insert push
#define MOD ((ll)1e9+7)
using namespace std;
using namespace __gnu_pbds;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=2e5+1;
ll a[maxN];
void solve(){
    int n; cin>>n;
    FOR(n){
        cin>>a[i];
    }
    for (int i=n-1;~i;i--){
        if (a[i]>=2 && i!=0){
            ll sub=2*(a[i]/2);
            a[i]-=sub;
            a[i-1]-=sub/2;
        }
    }
    ll s=0;
    for (int i=0;i<n;i++){
        if (a[i]==1 && i!=0 && a[i-1]>0){
            a[i-1]-=1;
            a[i]-=2;
        }
    }
    FOR(n) s+=abs(a[i]);
    print(s);
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
