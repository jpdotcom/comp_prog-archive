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
        
pi line[4];
const int maxN=1e5+5;
pi points[maxN];
bool isline(pi a, pi b, pi c){
    ll ans=(a.F-c.F)*(b.S-c.S)-(b.F-c.F)*(a.S-c.S);
    return ans==0;
}
void solve(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        pi p;
        cin>>p.F;
        cin>>p.S;
        points[i]=p;
    }
    if (n<=2){
        cout<<"YES"<<endl;
        return;
    }
    int next_idx;
    for (int i=0;i<3;i++){
        for (int j=i+1;j<3;j++){
            line[0]=points[i];
            line[1]=points[j];
            next_idx=2;
            bool isValid=true;
            for (int k=0;k<n;k++){
                if (!isline(line[0],line[1],points[k])){
                    if (next_idx==-1){
                        if (!isline(line[2],line[3],points[k])){
                            isValid=false;
                            break;
                        }
                    }
                    else{
                        line[next_idx]=points[k];
                        if (next_idx==3){
                            next_idx=-1;
                        }
                        else{
                            next_idx++;
                        }
                    }
                }
            }
            if (isValid){
                cout<<"YES"<<endl;
                return;
            }

        }
    }
    cout<<"NO"<<endl;

}

void precompute(){

}


int main(){

    cout<<setprecision(15);
    precompute();
    int t=1;
    while (t--){
        solve();
    }


}
