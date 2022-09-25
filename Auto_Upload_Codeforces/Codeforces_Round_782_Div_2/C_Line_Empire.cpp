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
const int maxN=2e5+1;
ll arr[maxN];
ll prefix[maxN];
void solve(){
  int n,a,b;cin>>n>>a>>b;
  prefix[0]=0;
  FOR(n){
    cin>>arr[i];
    prefix[i+1]=prefix[i]+arr[i];
  }
  ll i=-1,j=0;
  ll dist=0;
  ll ans=0;
  while (j<n){
    ll p=prefix[n]-prefix[j];
    if (i!=j-1 && b*(p-(n-j)*dist)>a*(arr[i+1]-dist)+b*(p-(n-j)*(arr[i+1]))){
      ans+=a*(arr[i+1]-dist);
      dist=arr[++i];
    }
    ans+=(arr[j]-dist)*b;
    j++;
  }
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
    
