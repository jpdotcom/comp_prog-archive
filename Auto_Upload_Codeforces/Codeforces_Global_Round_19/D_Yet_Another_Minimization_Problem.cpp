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
const int maxN=105;
ll dp[maxN][10005];
ll a[maxN];
ll b[maxN];
void solve(){
  int n;cin>>n;
  ll S=0;
  FOR(n){
    cin>>a[i];
   S+=a[i];
  }
  FOR(n){
    cin>>b[i];
    S+=b[i];
  }
  if (n==1){
    print(0);
    return;
  }
  dp[0][0]=1;
  for (int i=1;i<=n;i++){
    for (int j=0;j<10005;j++){
      dp[i][j]=0;
      int v1=j-a[i-1];
      int v2=j-b[i-1];
      if (v1>=0) dp[i][j]|=dp[i-1][v1];
      if (v2>=0) dp[i][j]|=dp[i-1][v2];
    }
  }
  ll ans=1e18;
  for (ll j=0;j<10005;j++){
    if (dp[n][j]) ans=min(ans,(ll)pow(j,2)+(ll)pow(S-j,2));
  }
  FOR(n) ans+=(n-2)*((ll)pow(a[i],2)+(ll)pow(b[i],2));
  print(ans);
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t=1;
  cin>>t;
  while (t--) solve();
  return 0;
}
    