#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll modu(ll a,ll b){
    return (b+(a%b)) % b;}
 
int power(long long x, unsigned int y, int p)
{
    unsigned long long res = 1;     // initialize result
 
    x = x % p; // update x if it is more than or
                // equal to p
  
    if (x == 0) return 0; // in case x is divisible by p;
 
    while (y > 0)
    {
        // if y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;}
 
 
const int n = 1e6;  // limit for array size
 
int t[2 * n];
 
void build(int n) {  // build the tree
 
  for (int i = n - 1; i > 0; --i) t[i] = 0;
}
 
void modify(int p, int value,int n) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = max(t[p],t[p^1]);
}
 
int query(int l, int r,int n) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = max(res,t[l++]);
    if (r&1) res = max(res,t[--r]);
  }
  return res;
}
const int maxN=200005;
vector<int>adj[100];
bool seen[maxN];
bool pro[maxN];
int dp[maxN];
int rep[maxN];
int dfs(int u){
  seen[u]=true;

  for (int v:adj[u]){
    if (!pro[v] && seen[v]){
      return 1;
    }
    else if (!seen[v]){
      int val=dfs(v);
      if (val){
        return 1;
      }
    }
  }
  pro[u]=true;
  return 0;
}
int ans(int u){
  if (dp[u]!=-1){
    return dp[u];
  }
  int c=1;
  for (int v:adj[u]){
    int val=ans(v);
    rep[v]=rep[u];
    if (v>u){
      val++;
    }
    c=max(c,val);
  }
  dp[u]=c;
  return c;
}
  
  
int find_rep(int a){
  
  while (rep[a]!=a){
    a=rep[a];
  }
  return a;
}
int solve(){
  int n;
  cin>>n;
  for (int i=1;i<=n;i++){
    pro[i]=false;
    seen[i]=false;
    adj[i].clear();
  }
  for (int i=1;i<=n;i++){
    
    int k;
    cin>>k;
    for (int j=0;j<k;j++){
      int d=1;
      cin>>d;
      adj[i].push_back(d);
    }
  }
  for (int i=1;i<=n;i++){
    if (!seen[i]){
      int val=dfs(i);
      if (val){
        return -1;
      }
    }
  }
  int g=0;
  for (int v=1;v<=n;v++){
    dp[v]=-1;
    rep[v]=v;
    seen[v]=false;
  }
  for (int v=1;v<=n;v++){
    if (dp[v]==-1){
      ans(v);
    }
  }

  for (int i=0;i<=n;i++){
    
    int val=dp[i];
    int r=find_rep(i);
    if (!seen[r]){
      g=max(dp[r],g);
      seen[r]=true;

    }
  }
  return g;
}
      


  

  
    
  

int main(){
    int t;
    cin>>t;
    vector<int>out;
    while(t--){
      out.push_back(solve());
    }
    for (int ans:out){
      cout<<ans<<endl;
      }
    return 0;
}