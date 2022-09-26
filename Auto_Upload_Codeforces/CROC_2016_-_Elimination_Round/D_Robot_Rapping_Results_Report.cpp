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

const int maxN=200000;
vector<pair<int,int>>adj[maxN];
int chain[maxN][2];

void dfs(int u){

  if (chain[u][0]!=-1){
    return;
  }
  chain[u][0]=1;
  chain[u][1]=0;
  for (pair<int,int> v:adj[u]){

    dfs(v.first);
    int val,time;
    val=chain[v.first][0];
    time=max(chain[v.first][1],v.second);
    if ((val+1)>chain[u][0]){
      chain[u][0]=val+1;
      chain[u][1]=time;
    }
    else if ((val+1)==chain[u][0]){
      chain[u][1]=min(time,chain[u][1]);
    }
  }
  return;
}


int solve(){

  int n,m;
  cin>>n>>m;

  for (int i=0;i<m;i++){

    int a,b;
    cin>>a>>b;

    pair<int,int>p;
    p.first=a;
    p.second=i+1;
    adj[b].push_back(p);
  }

  for (int i=1;i<n+1;i++){

    chain[i][0]=-1;
    chain[i][1]=0;
  
  }
  int ans=0;
  int time=maxN;
  for (int u=1;u<n+1;u++){
    dfs(u);
    if (chain[u][0]==n){
      ans++;
      time=min(time,chain[u][1]);
    }
  }

  if (ans==1){
      return time;
  }
  else{
    return -1;
  }
}
      







  
  




int main(){
    int t;
    t=1;
    vector<int>ans;
    for (int i=0;i<t;i++){
    
        ans.push_back(solve());
      
    }
    for (int c:ans){
      cout<<c<<endl;
    }

  return 0;
}

