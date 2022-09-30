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
const int maxN=3e5+1;
ll dp[maxN][2];
int a[maxN];
void solve(){
    int n,x; cin>>n>>x;
    FOR(n) cin>>a[i];
    dp[0][1]=0;
    dp[0][0]=0;
    for (int i=1;i<n;i++){
        for (int j=0;j<2;j++){
            dp[i][j]=0;
            if (j){
                dp[i][j]=max(((a[i]+x)^(a[i-1]))+dp[i-1][0],((a[i]+x)^(a[i-1]+x))+dp[i-1][1]);
            }
            else{
                dp[i][j]=max(((a[i])^(a[i-1]))+dp[i-1][0],((a[i])^(a[i-1]+x))+dp[i-1][1]);
            }
        }
    }
    print(max(dp[n-1][0],dp[n-1][1]));
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
    cin>>t;
    while (t--) solve();
}
