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
#include <iomanip>
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
double getDense(int i,int j){
    double ans=0;
    if (j==0){
        return ans;
    }
    ans=i;
    return ans/j;
}
const int maxN=505;
double d[maxN][2];
int cost[maxN];
vector<pi> adj[maxN];
void dfs(int u){
    if (d[u][0]!=-1){
        return;
    }
    d[u][0]=-2;
    d[u][0]=-2;
    double best=0;
    int w=cost[u];
    for (pi p:adj[u]){
        int v=p.F;
        int e=p.S;
        if (d[v][0]==-2){
            continue;
        }
        else{
            dfs(v);
            double pos=getDense(d[v][0]+w,d[v][1]+e);
            if (pos>best){
                d[u][0]=w+d[v][0];
                d[u][1]=d[v][1]+e;
                best=pos;
            }
            pos=getDense(cost[v]+w,e);
            if (pos>best){
                d[u][0]=cost[v]+w;
                d[u][1]=e;
                best=pos;
            }

        }
        
    }
    if (d[u][0]==-2){
        d[u][0]=w;
        d[u][1]=0;
    }
    return;
}


void solve(){
    int n,m;
    cin>>n>>m;
    for (int i=0;i<maxN;i++){
        d[i][1]=-1;
        d[i][0]=-1;
    }
    for (int i=0;i<n;i++){
        cin>>cost[i+1];
    }
    for (int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        pi p;
        p.F=v;
        p.S=w;

        adj[u].push_back(p);
        p.F=u;
        adj[v].push_back(p);
    }
    double ans=0;
    for (int i=1;i<=n;i++){
        if (d[i][0]==-1){
            dfs(i);
        }
    }
    for (int i=1;i<=n;i++){
        ans=max(ans,getDense(d[i][0],d[i][1]));
    }

    cout<<ans<<endl;
}




    


void precompute(){
}


int main(){

    cout<<setprecision(15);
    precompute();
    int t=1;
    for (int i=0;i<t;i++){
        solve();
    }
}
    
