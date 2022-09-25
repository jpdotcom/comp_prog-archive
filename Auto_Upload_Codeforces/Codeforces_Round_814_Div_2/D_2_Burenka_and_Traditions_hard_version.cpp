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
#define INF ((int)1e9)
#define all(a) (a).begin(), (a).end()
#define MOD ((ll)998244353)
using namespace std;
using namespace __gnu_pbds;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=2e5+10;
int a[maxN];
int dp[maxN];
void solve(){
    int n; cin>>n;
    FOR(n) cin>>a[i+1];
    for (int i=2;i<=n;i++){
        a[i]^=a[i-1];
    }
    map<int,int> XOR;
    XOR[0]=0;
    dp[0]=0;
    fill(dp,dp+n+1,-1*INF);
    int mx=0;
    for (int i=1;i<=n;i++){
        dp[i]=max(dp[i-1],dp[i]);
        if (XOR.find(a[i]) != XOR.end()){
            dp[i]=max(dp[i],XOR[a[i]]+1);
        }
        XOR[a[i]]=max(dp[i],XOR[a[i]]);
        mx=max(dp[i],mx);
    }
    print(n-mx);
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
