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
map<pi,int>vals;
int g(int a, int b){
  if (vals.find(make_pair(a,b))!=vals.end()) return vals[make_pair(a,b)];
  int ans=1e9;
  bool ok=true;
  FOR(32){
    if (((b>>i)&1)==0 && ((a>>i)&1)==1){
      ok=false;
      int new_val=a+pow(2,i)-a%(int)pow(2,i);
      int new_valb=b+pow(2,i)-b%(int)pow(2,i);
      ans=min(ans,new_val-a+g(new_val,b));
      ans=min(ans,new_valb-b+g(a,new_valb));
    }
  }
  if (ok) ans=0;
  vals[make_pair(a,b)]=ans;
  return ans;
}
void solve(){
  vals.clear();
  int a,b;cin>>a>>b;
  print(min((b-a),g(a,b)+1));
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
    
