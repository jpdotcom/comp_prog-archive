#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<long long> vi;
typedef std::pair<long,long> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<int> pq;
#define endl '\n'
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define MOD (int)(1e9+7)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
const int maxN=201;
pi a[maxN];
ll p[maxN];
void solve(){
    int n; cin>>n;
    FOR(n) cin>>a[i].F>>a[i].S>>p[i];
    ll l=0, r=4e9+1;
    ll ans=r;
    while (l<=r){
        ll m=l+(r-l)/2;
        ll dp[n][n];
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (i==j) dp[i][j]=0;
                else if (p[i]*m>=abs(a[i].F-a[j].F)+abs(a[i].S-a[j].S)) dp[i][j]=1;
                else dp[i][j]=1e18;
            }
        }
        for (int k=0;k<n;k++){
            for (int i=0;i<n;i++){
                for (int j=0;j<n;j++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }
        bool ok=false;
        FOR(n){
            bool f=true;
            for (int j=0;j<n;j++){
                if (dp[i][j]>=1e18) f=false;
            }
            ok|=f;
        }
        if (ok){
            r=m-1;
            ans=m;
        }
        else l=m+1;
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
