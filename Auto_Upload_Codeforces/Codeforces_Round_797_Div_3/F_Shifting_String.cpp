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
const int maxN=205;
int arr[maxN];
bool seen[maxN];
vi get_f(int x){
  vi ans;
  for (int i=1;i<=(int)sqrt(x);i++){
    int a=i,b=x/i;
    if (a*b==x){
      ans.pb(a);
      if (a!=b) ans.pb(b);
    }
  }
  return ans;
}
ll lcm(ll a,ll b){
  return a*b/gcd(a,b);
}
ll gcd(ll a, ll b){
  if (a>b) swap(a,b);
  if (a==0) return b;
  return gcd(b%a,a);
}
void solve(){
  FOR(maxN){
    arr[i]=seen[i]=0;
  }
  int n;
  string s;
  cin>>n>>s;
  FOR(n) cin>>arr[i+1];
  vi lcm_vals;
  for (int i=1;i<=n;i++){
    if (!seen[i]){
      vector<char> vals;
      int idx=i;
      while (!seen[idx]){
        vals.push_back(s[idx-1]);
        seen[idx]=true;
        idx=arr[idx];
      }
      vi factors=get_f(vals.size());
      sort(factors.begin(),factors.end());
      for (int x:factors){
        bool ok=true;
        for (int k=0;k<x;k++){
          for (int j=k;j<vals.size();j+=x){
            if (vals[k]!=vals[j]) ok=false;
          }
        }
        if (ok){
          lcm_vals.pb(x);
          break;
        }
      }
    }
  }
  ll ans=1;
  for (int x:lcm_vals){
    ans=lcm(ans,x);
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
    