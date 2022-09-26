#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#define FOR(a,b) for (int i=a;i<b;++i)
 
typedef long long ll;
 
 
using namespace std;
ll modu(ll a,ll b){
    return (b+(a%b)) % b;}
 
int power(long long x, unsigned int y, int p)
{
    unsigned long long res = 1;     // Initialize result
 
    x = x % p; // Update x if it is more than or
                // equal to p
  
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;}
 
 
const int N = 1e6;  // limit for array size
 
int t[2 * N];
 
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
 
 
 
const int maxN=1e6;
int color[maxN];
bool seen[maxN];
int team[2];
vector<vector<int>>adj;
int dfs(int u,int c,int n){
  seen[u]=true;
  if (color[u]!=-1 && color[u]!=c){
    return -1;
  }
 
  color[u]=c;
  int valid=1;
  if (u<=n){
    team[c]++;
  }
 
  for (int v:adj[u]){
    
    if (!seen[v]){
      valid=min(valid,dfs(v,c^1,n));
    }
    else{
      if (color[v]==color[u]){
        return -1;
      }
    }
  }
  return valid;
 
}
 
int solve(){
    int n,m;
    cin>>n>>m;
    int fake_n=n+1;
    adj.assign(n+m+5,vector<int>());
    for (int i=0;i<m;i++){
      int a,b;
      string s;
      cin>>a>>b;
      getline(cin,s);
      if (s==" imposter"){
        adj[a].push_back(b);
        adj[b].push_back(a);
    
      }
      else{
        adj[a].push_back(fake_n);
        adj[fake_n].push_back(a);
        adj[b].push_back(fake_n);
        adj[fake_n].push_back(b);
        fake_n++;
      }
    }
 
    for (int i=1;i<fake_n;i++){
      color[i]=-1;
      seen[i]=false;
    }
    int ans=0;
    for (int i=1;i<n+1;i++){
      if (!seen[i]){
        team[0]=0;
        team[1]=0;
        int check=dfs(i,0,n);
        if (check==-1){
          return -1;
        }
        int a,b;
        a=team[0];
        b=team[1];
        ans+=max(a,b);
 
      }
    }
    return ans;
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