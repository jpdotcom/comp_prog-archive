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
typedef std::pair<long long, long long> pi;
typedef long long ll;
#define F first 
#define S second 
using namespace std;
ll modu(ll a,ll b){
    return (b+(a%b)) % b;}
ll root(ll x) {
	ll l = 0, r = 1e9 + 1;
	while (l < r - 1) {
		ll m = (l + r) / 2;
		if (m * m > x)
			r = m;
		else
			l = m;
	}
	return l;
}
int power(long long x, unsigned int y, ll p)
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


const int N=5;
int t[N];
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
bool isPerfectSquare(ll x){
    ll u=root(x);
    return (u*u==x);
}
const int maxN=1e5+5;
const int maxK=505;
int type[maxN];
vector<pi>adjsh[maxN];
ll adj[maxK][maxK];
bool zero[maxN];
bool visited[maxN];
void dfs(int i,int cost,int orig){
    visited[i]=true;
    if (i==orig){
        zero[i]=true;
    }
    if (type[i]==type[orig]){
        zero[i]=true;
    }

    for (pi p:adjsh[i]){
        ll v =p.F;
        ll w = p.S;
        if (cost+w==0 && !visited[v]){

            dfs(v,cost+w,orig);
        }
    }
    
}
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    int curr=1;
    for (int i=1;i<=k;i++){
        for (int j=1;j<=k;j++){
            adj[i][j]=1e12;
        }
    }
    for (int i=0;i<k;i++){
        int val;
        cin>>val;
        for (int j=1;j<=val;j++){
            type[curr]=i+1;
            curr++;
        }

    }
    for (int i=0;i<m;i++){
        int a,b;
        ll w;
        cin>>a>>b>>w;
        adj[type[a]][type[b]]=min(adj[type[a]][type[b]],w);
        adj[type[b]][type[a]]=adj[type[a]][type[b]];
        pi p;
        p.F=a;
        p.S=w;
        adjsh[b].push_back(p);
        pi p2;
        p2.F=b;
        p2.S=w;
        adjsh[a].push_back(p2);
    }
    
    int last_type=0;
    for (int i=1;i<=n;i++){
        if (type[i]!=last_type){
        adj[type[i]][type[i]]=0;
        dfs(i,0,i);
        for (int j=1;j<=n;j++){

            visited[j]=false;
        }
        last_type=type[i];
        }
    }
    for (int i=1;i<=n;i++){
        if (!zero[i]){
            cout<<"No"<<endl;
            return;
        }
    }
    for (int i=1;i<=k;i++){
        for (int j=1;j<=k;j++){
            for (int l=1;l<=k;l++){
                adj[j][l]=min(adj[j][l],adj[j][i]+adj[i][l]);
            }
        }
    }
    cout<<"Yes"<<endl;
    for (int i=1;i<=k;i++){
        for (int j=1;j<=k;j++){
            if (adj[i][j]==1e12){
                adj[i][j]=-1;
            }
            cout<<adj[i][j]<<' ';
        }
        cout<<endl;
    }
    return;
    
}
        
void precompute(){
}


int main(){
    precompute();
    int t=1;
    for (int i=0;i<t;i++){
        solve();
    }
}
    
