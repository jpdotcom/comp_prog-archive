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
ll a[mxN];
void solve(){
  ll n,k;
  cin>>n>>k;
  ll s=0;
  ll m=1e9+1;
  FOR(n){
    cin>>a[i];
    s+=a[i];
    m=min(a[i],m);
  }
  if (s<=k) print(0);
  else{
    ll ans=s-k;
    sort(a,a+n);
    for (int j=n-1;j>0;j--){
      s-=a[j];
      ll r=floorl((k+m-s)/(n-j+1.0));
      ans=min(ans,max(0LL,m-r)+(n-j));
    }
    ll r=k/n;
    ans=min(ans,max(0LL,m-r)+n-1);
    print(ans);
  }

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
    

