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
void solve(){
  ll n; cin>>n;
  vi zeros;
  zeros.pb(-1);
  FOR(n){
    cin>>arr[i];
    if (!arr[i]) zeros.pb(i);
  }
  zeros.pb(n);
  pi idx;
  ll ans=0;
  for (int i=1;i<(int)zeros.size();i++){
    ll m=1;
    ll neg=0;
    for (int j=zeros[i-1]+1;j<zeros[i];j++){
      if (arr[j]<0) neg^=1;
      if (abs(arr[j])==2) m++;
    }
    if (neg==0 && ans<m){
      ans=m;
      idx=make_pair(zeros[i-1]+1,n-zeros[i]);
    }
    else if (neg){
      ll sub=0;
      for (int j=zeros[i-1]+1;j<zeros[i];j++){
        if (abs(arr[j])==2) sub++;
        if (arr[j]<0 && m-sub>ans){
          ans=m-sub;
          idx=make_pair(j+1,n-zeros[i]);
          break;
        }
      }
      sub=0;
      for (int j=zeros[i]-1;j>=zeros[i-1]+1;j--){
        if (abs(arr[j])==2) sub++;
        if (arr[j]<0 && m-sub>ans){
          ans=m-sub;
          idx=make_pair(zeros[i-1]+1,n-j);
          break;
        }
      }
    }
  }
  cout<<idx.F<<' '<<idx.S<<endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t=1;
  cin>>t;
  while (t--) solve();
  return 0;
}
    
