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
const int maxN=2005;
int dp[maxN][maxN];
void solve(){
  int n;cin>>n;
  int sum=0;
  FOR(n){
    string s;cin>>s;
    for (int j=0;j<n;j++){
      sum+=(int)s[j]-48;
      dp[i][j]=(int)s[j]-48;
    }
  }
  int mx=0;
  for (int j=0;j<n;j++){
    int idx=j;
    int curr=0;
    for (int i=0;i<n;i++){
      curr+=(dp[i][idx]);
      idx+=1;
      idx%=n;
    }
    mx=max(mx,curr);
  }
  print(sum+n-2*mx);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t=1;
  cin>>t;
  while (t--) solve();
  return 0;
}
    
