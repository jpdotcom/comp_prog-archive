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
const int N = 1e5;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}
const int maxN=1e5+5;
int opposite[maxN];
int rep[maxN];
map<string,int>tonum;
int find(int a){
    if (rep[a]!=a){
        rep[a]=find(rep[a]);
    }
    return rep[a];
}
int find_opp(int a){
    if (opposite[rep[a]]==-1){
        return -1;
    }
    else{
        opposite[a]=find(opposite[rep[a]]);
    }
    return opposite[a];
}
int un(int a, int b){
    int ra=find(a);
    int rb=find(b);
    int rA=find_opp(a);
    int rB=find_opp(b);
    if (ra==rB || rb==rA){
        return -1;
    }
    else{
        rep[ra]=rb;
        if (rA!=-1 && rB!=-1){
            rep[rA]=rB;
        }
        else{
            opposite[rb]=max(rA,rB);
        }
    }
    return 0;
}
    
int br(int a,int b){
    int ra=find(a);
    int rb=find(b);
    int rA=find_opp(a);
    int rB=find_opp(b);
    if (ra==rb || (rA==rB && rA!=-1)){
        return -1;
    }
    else{
        if (rB!=-1){
            rep[rB]=ra;
        }
        if (rA!=-1){
          rep[rA]=rb;
        }
        opposite[ra]=rb;
        opposite[rb]=ra;
    }
    return 0;
}
void solve(){
    int m,q;
    cin>>n>>m>>q;
    for (int i=0;i<n;i++){
        string s;
        cin>>s;
        tonum[s]=i;
        rep[i]=i;
        opposite[i]=-1;
    }
    for (int i=0;i<m;i++){
        int t;
        string a,b;
        cin>>t>>a>>b;
        if (t==1){
            cout<<(un(tonum[a],tonum[b]) == -1 ? "NO" : "YES")<<'\n';
        }
        else{
            cout<<(br(tonum[a],tonum[b]) == -1? "NO": "YES")<<'\n';
        }
    }
    for (int i=0;i<q;i++){
        string a,b;
        cin>>a>>b;
        if (find(tonum[a])==find(tonum[b])){
            cout<<1<<'\n';
        }
        else if (find_opp(tonum[a])==find(tonum[b])){
            cout<<2<<'\n';
        }
        else{
            cout<<3<<'\n';
        }
    }
    return;
    
}

void precompute(){

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    precompute();
    int t=1;
    while (t--){
        solve();
    }


}
