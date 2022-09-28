#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<long long,long long> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
#define MOD ((ll)1e9+7)
using namespace std;
const int maxN=5005;
long long dp[maxN][maxN];
int a[maxN];
long long extra[maxN];
void solve(){
    int n,m; cin>>n>>m;
    FOR(n) cin>>a[i];
    FOR(n+2) extra[i]=0;
    FOR(m){
        int a,b; cin>>a>>b;
        extra[a]+=b;
    }
    for (int i=0;i<=n+1;i++){
        dp[n+1][i]=(i!=n+1 ? extra[i] : 0);
    }
    for (int i=n;i>0;i--){
        for (int j=0;j<=n+1;j++){
            dp[i][j]=((j!=n+1 ? extra[j] : 0)+a[i-1]+dp[i+1][min(j+1,n+1)]);
            dp[i][j]=max(dp[i][j],(j!=n+1 ? extra[j] : 0) + dp[i+1][0]);
        }
    }
    print(dp[1][0]);

}
void precompute(){
}
int main(){
    precompute();
    int t=1;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(15);
    while (t--) solve();
}
