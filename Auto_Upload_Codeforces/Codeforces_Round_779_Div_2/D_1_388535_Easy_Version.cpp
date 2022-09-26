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
int arr[maxN];
void solve(){
  int l,r;cin>>l>>r;
  int n=r-l+1;
  int cnt[32];
  FOR(n) cin >> arr[i];
  FOR(32) cnt[i]=0;
  FOR(32){
    for (int j=0;j<r+1;j++){
      cnt[i]+=((j>>i)&1);
    }
  }
  int ans=0;
  FOR(32){
    int c=0;
    for (int j=0;j<r+1;j++){
      c+=((arr[j]>>i)&1);
    }
    ans+=(c!=cnt[i])*(1<<i);
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
    
