#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<int,int> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define endl '\n'
#define print(x) cout<<x<<'\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
#define MOD ((ll)1e9+7)
using namespace std;
using namespace __gnu_pbds;
const int maxN=100;
int dp[maxN+5][10005];
int a[maxN];
int b[maxN];
void solve(){
    int n; cin>>n;
    dp[0][0]=1;
    ll P=0;
    ll S=0;
    FOR(n){
        cin>>a[i];
        P+=pow(a[i],2);
        S+=a[i];
    }
    FOR(n){
        cin>>b[i];
        P+=b[i]*b[i];
        S+=b[i];
    }
    for (int i=1;i<=n;i++){
        for (int j=0;j<=S;j++){
            dp[i][j]=0;
            dp[i][j]|=((j-b[i-1]>=0 ? dp[i-1][j-b[i-1]] : 0) || (j-a[i-1]>=0 ? dp[i-1][j-a[i-1]] : 0));
        }
    }
    ll PSUM=(n-2)*P;
    ll ans=INF;
    for (int i=0;i<=S;i++){
        if (dp[n][i]) ans=min(ans,PSUM+i*i+(S-i)*(S-i));
    }
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
    while (t--){
        solve();
    }
}
