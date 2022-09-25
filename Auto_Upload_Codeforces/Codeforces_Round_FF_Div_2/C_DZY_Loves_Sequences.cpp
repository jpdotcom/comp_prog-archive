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
int larger[maxN];

void solve(){
    int n;
    cin>>n;
    int arr[n];
    int ans=1;
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    larger[n-1]=n-1;
    for (int i=n-2;i>=0;i--){
        if (arr[i]<arr[i+1]){
            larger[i]=larger[i+1];
        }
        else{
            larger[i]=i;
        }
    }
    for (int i=0;i<n;i++){
        int f=larger[i];
        if (f+1<n){

            ans=max(ans,f-i+2);
            ans=max(ans,larger[f+1]-larger[f]+1);
            bool can=false;
            if (f==0||arr[f+1]-arr[f-1]>=2){
                can=true;
            }
            if (f+2>=n|| arr[f+2]-arr[f]>=2){
                can=true;
            }
            if (can){
                f=larger[f+1];
            }
        }
        ans=max(ans,f-i+1);
    } 
    cout<<ans<<endl;
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
    
