#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<long long,long long> pi;
#define mp(a,b) make_pair(a,b)
#define all(a) a.begin(),a.end()
typedef long long ll;
typedef std::priority_queue<int> pq;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define MOD (ll)(998244353)
#define INF ((int)1e9+7)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
using u64 = uint64_t;
using u128 = __uint128_t;
#define int long long
const int maxN=2e5+10;
int cntA[maxN];
int cntB[maxN];
int a[maxN];
void solve(){
    int n; cin>>n;
    memset(cntA,0,sizeof(cntA));
    memset(cntB,0,sizeof(cntB));
    FOR(n) cin>>a[i];
    FOR(n){
        cntB[a[i]]++;
    }
    ll r=0;
    ll ans=0;
    for (int i=0;i<n;i++){
        r-=cntA[a[i]]*cntB[a[i]];
        cntB[a[i]]--;
        r+=cntA[a[i]]*cntB[a[i]];
        ans+=(ll)(i)*(n-i-1)-r-(i-cntA[a[i]])*cntB[a[i]]-(n-i-1-cntB[a[i]])*cntA[a[i]];
        r-=cntA[a[i]]*cntB[a[i]];
        cntA[a[i]]++;
        r+=cntA[a[i]]*cntB[a[i]];
    }
    print(ans);
}
void precompute(){
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cout<<setprecision(15);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    while (t--){
        solve();
    }
}

