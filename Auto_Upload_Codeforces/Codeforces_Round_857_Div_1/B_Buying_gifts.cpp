#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(a) for(int i=0;i<(int)a;i++)
#define mp(a,b) make_pair(a,b)
#define all(a)  a.begin(),a.end()
typedef std::vector<long  long> vi;
typedef long long ll;
typedef std::pair<ll,ll> pi;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>(s))&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+10)
#define MOD ((ll)1e9+7)
using namespace std;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=1e6+1;
pi a[maxN];
multiset<ll> mp;
void solve(){
    mp.clear();
    int n; cin>>n;
    FOR(n) cin>>a[i].F>>a[i].S;
    sort(a,a+n);
    vector<ll> vals;
    ll mx=-1e9;
    ll ans=1e9;
    ll pval=-1;
    FOR(n) mp.insert(a[i].S);
    for (int i=n-1;~i;i--){
        if (pval!=a[i].F){
            for (auto x: vals){
                mp.erase(mp.find(a[x].S));
                mx=max(mx,a[x].S);
            }
            pval=a[i].F;
            vals.clear();
        }
        vals.pb(i);
        mp.erase(mp.find(a[i].S));
        if (mx>=a[i].F){
            ans=min(ans,mx-a[i].F);
        }
        else{
            if (mp.size()==0){
                ans=min(ans,(ll)abs(mx-a[i].F));
                continue;
            }
            int mx_set=*(--mp.end());
            int min_val=*(mp.begin());
            if (mx_set>=a[i].F){
                int val=*mp.upper_bound(a[i].F-1);
                ans=min(ans,val-a[i].F);
            }
            if (min_val<=a[i].F){
                int val=*(--mp.upper_bound(a[i].F));
                if (val>=mx) ans=min(ans,a[i].F-val);
                else ans=min(ans,(ll)abs(mx-a[i].F));
            }
        }
        mp.insert(a[i].S);
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
    int i=1;
    cin>>t;
    while (t--)
    {
        solve();
        ++i;
    }
