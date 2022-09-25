#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<long long> vi;
typedef std::pair<int,int> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define endl '\n'
#define print(x) cout<<x<<'\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define INF (1e18+10)
#define all(a) (a).begin(), (a).end()
#define MOD ((ll)998244353)
using namespace std;
using namespace __gnu_pbds;
using u64 = uint64_t;
using u128 = __uint128_t;
void solve(){
    ll n,k; cin>>n>>k;
    vector<ll> tot(n);
    vector<ll> vals(n);
    FOR(n) cin>>vals[i];
    for (int i=0;i<n-1;i++){
        tot[i]=pow(10,vals[i+1]-vals[i])-1;
    }
    tot[n-1]=INF;
    int s=0;
    ll ans=INF;
    ll val=0;
    for (int i=0;i<n;i++){
        if (s<=k && tot[i]+s>k){
            int need=k-s+1;
            ans=min(val+(ll)powl(10,vals[i])*need,ans);
        }
        if (i==n-1) continue;
        s+=tot[i];
        val+=pow(10,vals[i])*tot[i];
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
