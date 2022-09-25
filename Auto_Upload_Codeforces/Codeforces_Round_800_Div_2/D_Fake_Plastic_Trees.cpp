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
const int maxN=2e6+5;
vi adj[maxN];
ll L[maxN];
ll R[maxN];
ll dp[maxN];
ll dfs(int u){
  dp[u]=0;
  ll S=0;
  for (int v:adj[u]){
    ll out=dfs(v);
    S+=out;
    dp[u]+=dp[v];
  }
  if (S<L[u]){
    dp[u]++;
    return R[u];
  }
  else{
    return min(R[u],S);
  }
}
void solve(){
  int n;cin>>n;
  FOR(n+2){
    adj[i].clear();
  }
  FOR(n-1){
    int val;cin>>val;
    adj[val].pb(i+2);
  }
  FOR(n){
    int a,b;cin>>a>>b;
    L[i+1]=a,R[i+1]=b;
  }
  dfs(1);
  print(dp[1]);
  
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t=1;
  cin>>t;
  while (t--) solve();
  return 0;
}
    