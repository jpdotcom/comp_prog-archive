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
const int mxN=2e5+1;
int n;
vector<ll> a(mxN);
vector<ll> b(mxN);
int best(vector<ll> &arr, int val){
  int b;
  ll d=1e9+1;
  for (int i=0;i<n;i++){
    if (abs(val-arr[i])<d){
      b=i;
      d=abs(val-arr[i]);
    }
  }
  return b;
}
void solve(){
  cin>>n;
  FOR(n) cin>>a[i];
  FOR(n) cin>>b[i];
  vi v1={0,best(b,a[0]),n-1};
  vi v2={0,best(b,a[n-1]),n-1};
  ll f=1e18+1;
  for (int x:v1){
    for (int y:v2){
      ll ans=abs(a[0]-b[x])+abs(a[n-1]-b[y]);
      if (x!=0 && y!=0) ans+=abs(b[0]-a[best(a,b[0])]);
      if (x!=n-1 && y!=n-1) ans+=abs(b[n-1]-a[best(a,b[n-1])]);
      f=min(ans,f);
    }
  }
  print(f);
}
void precompute(){
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
    
