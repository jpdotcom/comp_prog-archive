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


const int N = 1001;

int t[2 * N];


void build(int n) {  // build the tree
  for (int i=2*N-1;i>=0;i--) t[i]=0;
}

void modify(int p, int value,int n) {  // set value at position p
  for (t[p += n]=value ; p > 1; p >>= 1) t[p>>1] = t[p]+t[p^1];
}

int query(int l, int r,int n) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res+=t[l++];
    if (r&1) res+=t[--r];
  }
  return res;
}
long long cost[N][N];
vector<pair<int,int>>adj[N];
void shortest(int v){
    priority_queue<pair<long long,long long>> h;
    bool seen[N];
    for (int i=0;i<N;i++){
        seen[i]=false;
    }
    pair<long long, long long>p;
    p.first=0;
    p.second=v;
    h.push(p);
    while (!h.empty()){
        pair<long long, long long>p = h.top();
        h.pop();
        long long c= -1*p.first;
        long long u = p.second;
        if (!seen[u]){
        seen[u]=true;
        cost[v][u]=c;
        for (pair<int,int> x : adj[u]){
            int node=x.first;
            int w = x.second;
            if (!seen[node]){
                pair<long long, long long> new_pair;
                new_pair.first=-1*(w+c);
                new_pair.second=node;
                h.push(new_pair);
            }
        }
        }
    }
    return;
}
long long shortest2(int s, int e,int n){
    priority_queue<pair<long long,long long>> h;
    bool seen[N];
    for (int i=0;i<N;i++){
        seen[i]=false;
    }
    pair<long long,long long>p;
    p.first=0;
    p.second=s;
    h.push(p);
    long long vals[N];
    while (!h.empty()){
        pair<long long, long long> p = h.top();
        h.pop();
        long long c = -1*p.first;
        int u=p.second;
        if (!seen[u]){
        vals[u]=c;
        seen[u]=true;
        for (int i=1;i<=n;i++){
            if (!seen[i]){
                pair<long long, long long>new_pair;
                new_pair.first=-1*(cost[u][i]+c);
                new_pair.second=i;
                h.push(new_pair);
            }
        }
        }
    }
    return vals[e];
}

        
long long solve(){
    long long max_val=1e12;
    int n,m,start,end;
    cin>>n>>m>>start>>end;
    long long info[n+1][2];
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cost[i][j]=max_val;
        }
    }
    for (int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        pair<int,int>p;
    
        p.first=v;
        p.second=w;
        adj[u].push_back(p);
        p.first=u;
        adj[v].push_back(p);
    }
    for (int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        info[i][0]=a;
        info[i][1]=b;
    }

    for (int i=1;i<=n;i++){
        shortest(i);
    }
    
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (info[i][0]>=cost[i][j]){
                cost[i][j]=info[i][1];
            }
            else{
                cost[i][j]=max_val;
            }
        }
    }
    long long ans=shortest2(start,end,n);
    if (ans>=max_val){
        return -1;
    }
    return ans;
}



int main(){
    vector<long long>ans;
    int t=1;
    for (int i=0;i<t;i++){
    
        ans.push_back(solve());
      
    }
    for (long long x:ans){

        cout<<x<<endl;
    }
    
}
    
