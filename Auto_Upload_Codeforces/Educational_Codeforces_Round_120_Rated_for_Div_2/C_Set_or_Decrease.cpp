#include <bits/stdc++.h>
typedef long long ll;
#define FOR(n) for (int i=0;i<n;i++)
#define pb(x) push_back(x)
typedef std::pair<int,int> pi;
typedef std::vector<ll> vi;
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
ll a[mxN];

ll accurateFloor(ll a, ll b) {
	ll val = a / b;
	while (val * b > a)
		val--;
	return val;
}
void solve(){
  ll n,k;
  cin>>n>>k;
  vi p(n+1);
  vi a(n);
  p[0]=0;
  FOR(n) cin>>a[i];
  sort(a.begin(),a.end());
  FOR(n){
    p[i+1]+=p[i]+a[i];
  }
  if (p[n]<=k){
    print(0);
    return;
  }
  ll ans=1e18;
  for (int i=0;i<n;i++){
    ll x=accurateFloor(k-p[n-i]+a[0],i+1);
    ans=min(ans,i+max(0LL,a[0]-x));
  }
  print(ans);
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
    
