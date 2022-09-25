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
int n;
void solve(){
  cin>>n;
  vector<int> first(n+1,-1);
  vector<int> arr(n);
  FOR(n){
    cin>>arr[i];
    if (first[arr[i]]==-1) first[arr[i]]=i;
  }

  int ans=0;
  int min_idx=n-1;
  int res=n-1;
  for (int i=n-1;i>-1;i--){
    min_idx=min(min_idx,first[arr[i]]);
    if (res<i) ans++;
    else res=min_idx;
  }
  print(ans);
}
void precompute(){
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  precompute();
  int t=1;
  while (t--) solve();
  return 0;
}
    

