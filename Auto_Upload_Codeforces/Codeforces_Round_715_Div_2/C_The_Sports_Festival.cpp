#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<long long, long long> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
using namespace std;
using namespace __gnu_pbds;
const int maxN=2005;
ll dp[maxN][maxN];
int a[maxN];
void solve(){
    int n; cin>>n;
    FOR(n) cin>>a[i];
    sort(a,a+n);
    FOR(n) dp[i][i]=0;
    for (int i=n-1;i>=0;i--){
        for (int j=i+1;j<n;j++){
            dp[i][j]=INF;
            dp[i][j]=a[j]-a[i]+min(dp[i+1][j],dp[i][j-1]);
        }
    }
    print(dp[0][n-1]);
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
    while (t--){
        solve();
    }
}
