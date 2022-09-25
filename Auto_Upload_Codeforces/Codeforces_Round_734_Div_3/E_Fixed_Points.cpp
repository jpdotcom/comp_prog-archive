#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<long long> vi;
typedef std::pair<long long,long long> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<int> pq;
#define endl '\n'
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define MOD (ll)(998244353)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
const int maxN=2005;
int dp[maxN][maxN];
const int INF=1e9+1;
int a[maxN];
void solve(){
    int n,k; cin>>n>>k;
    FOR(n+1){
        for (int j=0;j<n+1;j++) dp[i][j]=-1*INF;
    }
    FOR(n) cin>>a[i];
    dp[0][0]=(a[0]==1);
    dp[0][1]=0;
    for (int i=1;i<n;i++){
        for (int j=0;j<n+1;j++){
            int v=(a[i]==i+1-j);
            dp[i][j]=v+dp[i-1][j];
            if (j>0){
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]);
            }
        }
    }
    int ans=-1;
    FOR(n+1){
        if (dp[n-1][i]>=k){
            ans=i;
            break;
        }
    }
    print(ans);
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }
}
