#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<int, int> pi;
typedef long long ll;
typedef std::priority_queue<int> pq;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
const int maxN=5500;
int dp[maxN][maxN];
int t[2*maxN][2];
const int INF=1e9+7;
int n;
void build(int n){
    for (int i=0;i<2*n+10;i++){
        t[i][0]=t[i][1]=INF;
    }
}
int query(int a, int b, int idx){
    int ans=INF;
    for (a+=n,b+=n; a<=b; a>>=1,b>>=1){
        if (a&1) ans=min(ans,t[a++][idx]);
        if ((b&1)==0) ans=min(ans,t[b--][idx]);
    }
    return ans;
}
void update(int a, int idx, int val){
    a+=n;
    t[a][idx]=val;
    for (a/=2; a>0;a>>=1){
      t[a][idx]=min(t[a*2][idx],t[a*2+1][idx]);
    }
}
void solve(){
    cin>>n;
    build(n);
    vector<int> v(n);
    build(n);
    FOR(n){
        int a; cin>>a;
        v[i]=a^1;
    }
    for (int j=0;j<=n;j++){
            dp[0][j]=0;
    }
    int prev_idx=0;
    int min_vals[n+1];
    FOR(n+1) min_vals[i]=INF;
    for (int i=1;i<=n;i++){
        if (v[i-1]==0){
            min_vals[0]=dp[prev_idx][0];
            for (int j=1;j<=n;j++){
                min_vals[j]=INF;
                if (v[j-1]) min_vals[j]=dp[prev_idx][j];
                min_vals[j]=min(min_vals[j],min_vals[j-1]);
            }
            dp[i][0]=INF;
            for (int j=1;j<=n;j++){
                if (v[j-1]) dp[i][j]=abs(i-j)+min_vals[j-1];
                else dp[i][j]=INF;
            }
            prev_idx=i;
        }
    }
    int ans=INF;
    FOR(n) ans=min(ans,dp[prev_idx][i+1]);
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
    while (t--){
        solve();
    }
}


