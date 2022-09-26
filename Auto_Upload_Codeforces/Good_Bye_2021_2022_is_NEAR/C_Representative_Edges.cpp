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
const int maxN=71;
int a[maxN];
void solve(){
  int n;cin>>n;
  FOR(n) cin>>a[i];
  if (n<=2){
    print(0);
    return;
  }
  int ans=n-1;
  double epi=1e-8;
  for (int i=0;i<n;i++){
    for (int j=i+1;j<n;j++){
      double d=(a[j]-a[i])/(j-i+0.0);
      int cnt=0;
      double start=a[j];
      for (int k=j-1;k>=0;k--){
        start-=d;
        cnt+=(abs(a[k]-start)>epi);
      }
      start=a[j];
      for (int k=j+1;k<n;k++){
        start+=d;
        cnt+=(abs(a[k]-start)>epi);
      }
      ans=min(ans,cnt);
    }
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
    

