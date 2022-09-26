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
map<pi,int> cnt;
void solve(){
  cnt.clear();
  int n; cin>>n;
  pi min_val;
  pi max_val;
  FOR(n){
    int a,b,c; cin>>a>>b>>c;
    pi p=make_pair(a,b);
    if (i==0){
      cnt[p]=c;
      max_val=make_pair(b,-1*c);
      min_val=make_pair(a,c);
      print(c);
    }
    else{
      if (cnt.find(p) == cnt.end()) cnt[p]=c;
      cnt[p]=min(cnt[p],c);
      if (max_val<make_pair(b,-1*c)){
        max_val=make_pair(b,-1*c);
      }
      if (min_val>make_pair(a,c)) min_val=make_pair(a,c);
      int c=min_val.S-max_val.S;
      if (cnt.find(make_pair(min_val.F,max_val.F))!=cnt.end()) c=min(c,cnt[make_pair(min_val.F,max_val.F)]);
      print(c);
    }
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
    

