#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(a,n) for (int a=0;a<n;a++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<long  long> vi;
typedef std::pair<int,int> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>(s))&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((int)1e9+10)
#define MOD ((ll)1e9+7)
using namespace std;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=5005;
int a[maxN];
ll dp[maxN][maxN];
ll cnt[maxN];
void solve(){
    int n,k,q; cin>>n>>k>>q;
    FOR(i,n) cin>>a[i];
    FOR(i,n){
        dp[i][0]=1;
    }
    for (int j=1;j<=k;j++){
        for (int i=0;i<n;i++){
            dp[i][j]=0;
            if (i-1>-1) dp[i][j]+=dp[i-1][j-1];
            dp[i][j]%=MOD;
            if (i+1<n) dp[i][j]+=dp[i+1][j-1];
            dp[i][j]%=MOD;
        }
    }
    ll s=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<=k;j++){
            cnt[i]+=(dp[i][j]*dp[i][k-j])%MOD;
            cnt[i]%=MOD;
        }
    }
    FOR(i,n){
        s+=(cnt[i]*a[i])%MOD;
        s%=MOD;
    }
    FOR(i,q){
        int j,val; cin>>j>>val;j--;
        s-=(a[j]*cnt[j])%MOD;
        s=(s+MOD)%MOD;
        a[j]=val;
        s+=(a[j]*cnt[j])%MOD;
        s%=MOD;
        print(s);
    }
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
    while (t--)
    {
        solve();
        ++i;
    }
}
