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
#define endl '\n'
#define print(x) cout<<x<<'\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((int)1e9+6)
#define all(a) (a).begin(), (a).end()
#define MOD ((ll)998244353)
using namespace std;
using namespace __gnu_pbds;
const int maxN=1e6+2;
int dp[maxN];
ll f[maxN];
ll prefix[maxN];
int a[maxN];
int t[maxN];
int n;
void mod(int i, int v){
    for (i;i<=n;i+=(i&-i)){
        t[i]=max(v,t[i]);
    }
}
int q(int i){
    int ans=-1*INF;
    for (i;i>0;i-=(i&-i)){
        ans=max(ans,t[i]);
    }
    return ans;
}
void solve(){
    cin>>n;
    vector<pi> getord(n);
    ll s=0;
    FOR(n){
        cin>>a[i];
        s+=a[i];
        prefix[i+1]=s;
        getord[i]=mp(s,-1*i);
    }
    sort(all(getord));
    for (int i=0;i<n;i++){
        f[-1*getord[i].S]=i+1;
    }
    FOR(n+1) t[i]=-1*INF;
    dp[0]=0;
    for (int i=1;i<=n;i++){
        dp[i]=-1*INF;
        dp[i]=max(dp[i],(a[i-1]>0 ? 1: a[i-1]==0 ? 0 : -1)+dp[i-1]);
        if (prefix[i]>0) dp[i]=i;
        dp[i]=max(dp[i],q(f[i-1])+i);
        mod(f[i-1],dp[i]-i);
    }
    print(dp[n]);
}
/*
   1
   6
   1 1 1 -1 -1 -1
*/
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
