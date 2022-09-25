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
#define MOD (ll)(1e9+7)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
const int maxN=5005;
int a[maxN];
int dp[maxN];
void solve(){
    int n; cin>>n;
    FOR(n) cin>>a[i];
    dp[0]=0;
    dp[1]=1;
    for (int i=2;i<=n;i++){
        int cnt[n+1];
        FOR(n+1) cnt[i]=0;
        int m=0;
        dp[i]=-1e9+7;
        for (int j=i-1;j>=0;j--){
            if (((i-j-1)&1)==0 && m<=(i-j-1)/2 && (j==0 || (a[i-1]==a[j-1]))){
                dp[i]=max(dp[i],dp[j]+1);
            }
            if (j!=0){
            cnt[a[j-1]]++;
            m=max(m,cnt[a[j-1]]);
            }
        }
    }
    int cnt[n+1];
    int m=0;
    FOR(n+1) cnt[i]=0;
    int ans=0;
    for (int i=n;i>=0;i--){
        if (((n-i)&1)==0 && m<=(n-i)/2) ans=max(dp[i],ans);
        if (i){
            cnt[a[i-1]]++;
            m=max(m,cnt[a[i-1]]);
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
