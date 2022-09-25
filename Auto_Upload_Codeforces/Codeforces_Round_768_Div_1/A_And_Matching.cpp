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
void solve(){
  int n,k; cin>>n>>k;
  int seen[n];
  FOR(n) seen[i]=0;
  if (k==0){
    FOR(n){
      if (!seen[i]) cout<<i<<' '<<(i^(n-1))<<endl;
      seen[i]=seen[i^(n-1)]=true;
    }
  }
  else if (k<n-1){
    FOR(n){
      if (i!=0 && i!=n-1 && i!=(k^(n-1)) && i!=k && seen[i]==0){
        cout<<i<<' '<<(i^(n-1))<<endl;
        seen[i]=seen[i^(n-1)]=1;
      }
    }
    cout<<n-1<<' '<<k<<endl;
    cout<<0<<' '<<(k^(n-1))<<endl;
  }
  else{
    if (n==4){
      print(-1);
      return;
    }
    FOR(n){
      if (i!=n-3&& i!=n-1 && i!=n-2 && i!=0 && i!=2 && i!=1&& !seen[i]){
        seen[i]=seen[i^(n-1)]=1;
        cout<<i<<' '<<(i^(n-1))<<endl;
      }
    }
    cout<<(n-1)<<' '<<(n-2)<<endl;
    cout<<(n-3)<<' '<<1<<endl;
    cout<<0<<' '<<2<<endl;
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
    
