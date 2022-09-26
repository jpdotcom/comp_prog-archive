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


const int N=1e6+5;
ll t[2*N][3];
void build(int n) {  // build the tree
  for (int i=2*N-1;i>=0;i--) {
      t[i][0]=0;
      t[i][1]=0;
      t[i][2]=1e12;
  }
}

void modify(int p, int value,int n) {  // set value at position p
  for (t[p += n][0]=value ; p > 1; p >>= 1){
      t[p>>1][0]= t[p][0]+t[p^1][0];
      t[p>>1][1]=max(t[p][1],t[p^1][1]);
      t[p>>1][2]=min(t[p][2],t[p^1][2]);
      
  }
}

int query(int l, int r,int n) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res+=t[l++][0];
    if (r&1) res+=t[--r][0];
  }
  return res;
}
int get_max(int val, int side,int idx,int n,int lval,int rval){
    if (lval==rval){
        return rval;
    }
    if (lval>rval){
        return -1;
    }
    int m=(lval+rval)/2;
    if (abs(t[idx][1]-val)>=2 || abs(t[idx][2]-val)>=2){
        if ((abs(t[2*idx][1]-val)>=2 || abs(t[2*idx][2]-val)>=2) && side==0){
           return get_max(val,side,2*idx,n,lval,m);
        }
        else{
           return get_max(val,side,2*idx+1,n,m+1,rval);
        }
    }
    return -1;
}
bool isPerfectSquare(ll x){
    ll u=root(x);
    return (u*u==x);
}

void solve(){
    ll n,m,k;
    cin>>n>>m>>k;
    ll l=1;
    ll r=n*m;
    ll ans=0;
    while (l<=r){
        ll mid=l+(r-l)/2;
        ll less=0;
        for (int i=1;i<=n;i++){
            less+=min((mid-1)/i,m);
        }
        if (less<k){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
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
    
