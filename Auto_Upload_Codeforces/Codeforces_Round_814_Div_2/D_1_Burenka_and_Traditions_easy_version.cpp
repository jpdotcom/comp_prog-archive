#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<long  long> vi;
typedef std::pair<int,int> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((int)1e9)
#define MOD ((ll)1e9+7)
using namespace std;
const int maxN=5005;
int dp[maxN][8193];
int a[maxN];
void solve(){
    int n; cin>>n;
    FOR(n) cin>>a[i];
    for (int i=0;i<8193;i++){
        dp[0][i]=(i!=0);
    }
    for (int i=1;i<n;i++){
        for (int j=0;j<8193;j++){
            dp[i][j]=INF;
            dp[i][j]=min(dp[i][j],1+dp[i-1][j^a[i-1]]);
            dp[i][j]=min(dp[i][j],(j!=0)+dp[i-1][a[i-1]]);
        }
    }
    print(dp[n-1][a[n-1]]);
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
    while (t--)
    {
        solve();
    }
}
