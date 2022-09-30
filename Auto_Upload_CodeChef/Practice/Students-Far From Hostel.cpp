#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<long long> vi;
typedef std::pair<long long,long long> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)-1e18+7)
#define MOD ((ll)1e9+7)
using namespace std;
const int maxN=2e5+1;
void solve(){
    int n,m; cin>>n>>m;
    vector<vector<ll>> A(n+1);
    vector<vector<ll>> B(n+1);
    vector<vector<ll>> dp(n+1,vector<ll>(m+1,INF));
    FOR(n){
        vi p(m+1,0);
        for (int j=0;j<m;j++){
            cin>>p[j+1];
            p[j+1]+=p[j];
        }
        A[i+1]=p;
    }
    FOR(n){
        vi p(m+1,0);
        for (int j=0;j<m;j++){
            cin>>p[j+1];
            p[j+1]+=p[j];
        }
        B[i+1]=p;
    }
    dp[0][0]=0;
    for (int i=1;i<=n;i++){
        ll mx_val=INF;
        for (int j=0;j<=m;j++){
            mx_val=max(mx_val,dp[i-1][j]);
            dp[i][j]=max(dp[i][j],A[i][j]+B[i][m]-B[i][j]+mx_val);
        }
    }
    ll ans=0;
    FOR(m+1) ans=max(ans,dp[n][i]);
    print(ans);
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
    while (t--)
    {solve();
    }
}
