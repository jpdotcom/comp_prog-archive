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
const int maxN=3e5+1;
vi adj[maxN];
int seen[maxN];
int child[maxN];
int dfs(int u){
  if (seen[u]) return child[u];
  seen[u]=true;
  child[u]=0;
  for (int v:adj[u]){
    if (!seen[v]) child[u]+=1+dfs(v);
  }
  return child[u];
}
int dfs2(int u){
  seen[u]=true;
  int ans=maxN;
  int o=(adj[u].size()==3 || (adj[u].size()==2 && u==1));
  for (int v:adj[u]){
    if (!seen[v]) ans=min(ans,1+o+dfs2(v));
  }
  if (u!=1 && adj[u].size()==1) ans=1;
  if (u!=1 && adj[u].size()==2) ans=2;
  if (u==1 && adj[u].size()==1) ans=2;
  return ans;
}
void solve(){
  int n;
  cin>>n;
  FOR(n+1){
    adj[i].clear();
    seen[i]=0;
    child[i]=0;
  }
  FOR(n-1){
    int a,b;cin>>a>>b;
    adj[a].pb(b), adj[b].pb(a);
  }
  dfs(1);
  FOR(n+1) seen[i]=0;
  print(n-dfs2(1));
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t=1;
  cin>>t;
  while (t--) solve();
  return 0;
}
    