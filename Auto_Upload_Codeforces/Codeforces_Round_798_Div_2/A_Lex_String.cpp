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
const int maxN=0;
void solve(){
  int n,m,k;cin>>n>>m>>k;
  string s,t;cin>>s>>t;

  sort(s.begin(),s.end());
  sort(t.begin(),t.end());
  int ks=0,kt=0;
  int i=0,j=0;
  string c="";
  while (i<s.size() && j<t.size()){
    if (s[i]<t[j] && ks<k){
      c+=s[i];
      ks++;
      kt=0;
      i++;
    }
    else if (s[i]<t[j]){
      c+=t[j];
      kt++;
      ks=0;
      j++;
    }
    else if (t[j]<s[i] && kt<k){
      c+=t[j];
      kt++;
      ks=0;
      j++;
    }
    else{
      c+=s[i];
      ks++;
      kt=0;
      i++;
    }
  }
  print(c);
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t=1;
  cin>>t;
  while (t--) solve();
  return 0;
}
    