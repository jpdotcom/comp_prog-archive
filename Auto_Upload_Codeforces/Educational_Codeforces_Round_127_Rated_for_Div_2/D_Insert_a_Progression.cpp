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
ll mx1[maxN];
ll mxx[maxN];
void solve(){
  int n,x; cin>>n>>x;
  FOR(n) cin>>arr[i];
  mx1[n-1]=abs(arr[n-1]-1);
  mxx[n-1]=abs(arr[n-1]-x);
  ll norm=0;
  FOR(n-1){
    norm+=abs(arr[i]-arr[i+1]);
  }
  for (int i=n-2;i>=0;i--){
    mx1[i]=min(mx1[i+1],abs(arr[i]-1)+abs(arr[i+1]-1)-abs(arr[i]-arr[i+1]));
    mxx[i]=min(mxx[i+1],abs(arr[i]-x)+abs(arr[i+1]-x)-abs(arr[i]-arr[i+1]));
  }
  ll ans=1e9;
  FOR(n+1){
    ll c=0;
    if (i==0) c+=abs(arr[i]-1);
    else if (i==n) c+=abs(arr[i-1]-1);
    else c+=(abs(arr[i-1]-1)+abs(arr[i]-1)-abs(arr[i]-arr[i-1]));
    if (i!=n){
      c+=min(mxx[i],abs(arr[i]-x)+abs(x-1)-abs(arr[i]-1));
    }
    else{
      c+=abs(1-x);
    }
    ans=min(ans,c);
  }
  FOR(n+1){
    ll c=0;
    if (i==0) c+=abs(arr[i]-x);
    else if (i==n) c+=abs(arr[i-1]-x);
    else c+=(abs(arr[i-1]-x)+abs(arr[i]-x)-abs(arr[i]-arr[i-1]));
    if (i!=n) c+=min(mx1[i],abs(arr[i]-1)+abs(x-1)-abs(arr[i]-x));
    else c+=abs(1-x);
    ans=min(ans,c);
  }
  print(ans+norm);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t=1;
  cin>>t;
  while (t--) solve();
  return 0;
}
    
