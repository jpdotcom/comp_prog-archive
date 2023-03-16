#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(a) for(int i=0;i<a;i++)
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
const int maxN=6e6+1;
ll a[maxN];
pi b[maxN];
void solve(){
    int n,c; cin>>n>>c;
    FOR(n) cin>>a[i+1];
    FOR(n){
        b[i+1]={min(a[i+1]+i+1,a[i+1]+n-i),i+1};
    }

    sort(b+1,b+n+1);
    FOR(n){
        b[i+1].F+=b[i].F;
    }
    int ans=0;
    for (int i=1;i<=n;i++){
        int l=1,r=n;
        ll p=a[b[i].S];
        ll pi=b[i].S;
        if (p+pi<=c) ans=max(ans,1);
        while (l<=r){
            int m=l+(r-l)/2;
            ll val=p+pi+b[m].F-((m>=i) ? min(p+pi,p+n+1-pi): 0);
            if (val<=c){
                ans=max(ans,m+(i>m));
                l=m+1;
            }
            else r=m-1;
        }
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
    int i=1;
    while (t--)
    {
        solve();
        ++i;
    }
}
