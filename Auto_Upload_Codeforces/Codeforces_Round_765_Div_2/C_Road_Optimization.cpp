#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<long long,long long> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<int> pq;
#define endl '\n'
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define MOD (ll)(1e9+7)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
const int maxN=505;
pi a[maxN];
ll dp[maxN][maxN];
void solve(){
    ll n,l,k; cin>>n>>l>>k;
    FOR(n) cin>>a[i].F;
    FOR(n) cin>>a[i].S;
    int end=n;
    if (a[n-1].F!=l){
        a[n]=make_pair(l,l);
        end++;
    }
    dp[0][0]=0;
    ll ans=1e18+7;
    ll INF=1e18;
    memset(dp,INF,sizeof(dp));
    for (int i=1;i<=end;i++){
        for (int j=0;j<=k;j++){
            if (i==1) dp[i][j]=0;
            if (i>1){
                dp[i][j]=dp[i-1][j]+a[i-2].S*(a[i-1].F-a[i-2].F);
                for (int c=i-1;c>=1 && j-(i-c-1)>=0;c--){
                    dp[i][j]=min(dp[i][j],a[c-1].S*(a[i-1].F-a[c-1].F)+dp[c][j-(i-c-1)]);
                }
            }
        }
    }
    for (int i=0;i<=k;i++){
        ans=min(ans,dp[end][i]);
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
    while (t--){
        solve();
    }
}


