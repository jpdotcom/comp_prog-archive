#include <bits/stdc++.h>
typedef long long ll;
#define FOR(n) for (int i=0;i<n;i++)
#define pb(x) push_back(x)
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
#define PI  3.14159265358979323846
#define F first
#define S second
#define endl '\n'
#define print(x) cout<<x<<'\n'
using namespace std;
ll power(ll x, ll y, ll  p)
{
    ll res=1;
    x = x % p;
    if (x == 0) return 0; 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
ll dp[(int)1e3+1];
const int mxN=1e3+1;
ll kp[mxN][12*mxN];
ll b[mxN];
ll c[mxN];
void solve(){
  int n,k; cin>>n>>k;
  k=min(k,12*n);
  FOR(k+1){
    kp[0][i]=0;
  }
  FOR(n) cin>>b[i];
  FOR(n) cin>>c[i];
  for (int i=1;i<=n;i++){
    for (int j=0;j<=k;j++){
      kp[i][j]=kp[i-1][j];
      if (j-dp[b[i-1]]>=0) kp[i][j]=max(kp[i][j],c[i-1]+kp[i-1][j-dp[b[i-1]]]);
    }
  }
  print(kp[n][k]);
}
void precompute(){
  for (int i=1;i<mxN;i++) dp[i]=1e9;
  for (int i=1;i<mxN;i++){
    if (i==1) dp[i]=0;
    for (int j=1;j<=i;j++){
        if (i+(i/j)<mxN){
        dp[i+(i/j)]=min(dp[i+(i/j)],dp[i]+1);
        }
    }
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  precompute();
  int t=1;
  cin>>t;
  while (t--) solve();
  return 0;
}
    
