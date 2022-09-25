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
#define INF ((ll)1e18)
#define all(a) (a).begin(), (a).end()
#define MOD ((ll)998244353)
using namespace std;
using namespace __gnu_pbds;
const int maxN=1e6+1;
int a[maxN];
int dp[maxN];
int n;
void solve(){
    cin>>n;
    for (int i=1;i<=n;++i) cin>>a[i];
    int x; cin>>x;
    for (int i=1;i<=n;++i){
        a[i]-=x;
    }
    dp[0]=0;
    int ans=0;
    for (int i=1;i<=n;i++){
        dp[i]=1+(i-2>0 ? dp[i-2] : 0);
        if (i>1){
            if (a[i]+a[i-1]>=0) dp[i]=max(dp[i],2+(i-3>0 ? dp[i-3] : 0));
        }
        if (i>2){
            if (a[i]+a[i-1]+a[i-2]>=0 && a[i]+a[i-1]>=0 && a[i-1]+a[i-2]>=0) dp[i]=max(dp[i],1+dp[i-1]);
        }
        ans=max(dp[i],ans);
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
