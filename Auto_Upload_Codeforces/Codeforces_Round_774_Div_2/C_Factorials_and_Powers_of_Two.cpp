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
ll fac[16];
void solve(){
  ll n; cin>>n;
  ll ans=__builtin_popcountll(n);
  FOR(65537){
    ll m=0;
    ll cnt=0;
    for (int j=0;j<16;j++){
      if ((i>>j) & 1){
        m+=fac[j];
        cnt++;

      }
    }
    if (m<=n){
      cnt+=__builtin_popcountll(n-m);
      ans=min(ans,cnt);
    }
  }
  print(ans);
  
}
void precompute(){
  fac[0]=1;
  for (int i=1;i<16;i++) fac[i]=i*fac[i-1];
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
    
