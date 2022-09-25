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
const int maxN=3e5+1;
int a[maxN];
int dp[maxN];
int n;
void solve(){
    cin>>n;
    FOR(n) cin>>a[i];
    int ans=0;
    int mx=0;
    for (int i=0;i<n;i++){
        dp[i]=1;
        mx=max(a[i],mx);
        for (int j=max(0,i-mx);j<=i+mx;j++){
            int other=j^a[i];
            if (other<i && (a[other]^i)<j){
                    dp[i]=max(dp[i],1+dp[other]);
            }
        }
        ans=max(ans,dp[i]);
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
    while (t--)
    {
        solve();
    }
}
