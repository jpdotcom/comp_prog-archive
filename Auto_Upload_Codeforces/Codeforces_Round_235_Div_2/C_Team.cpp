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


vector<int>solve(){
    int n,m;
    vector<int>ans;
    cin>>n>>m;
    if (n>m+1){
      ans.push_back(-1);
      return ans;
    }
    if (2*n+2<m){
      ans.push_back(-1);
      return ans;
    }
    else{
      if (n==m+1){
        ans.push_back(0);
        n--;
      }
      while (m>n){
        ans.push_back(1);
        ans.push_back(1);
        m-=2;
        if (m==0 and n==0){
          return ans;
        }
        
        ans.push_back(0);
        n--;
        if (m==1 && n==0){
          ans.push_back(1);
          return ans;
        }
      }
      
      while (m!=0 || n!=0){

        if (m!=0){
          
          ans.push_back(1);
          m--;
        }
        if (n!=0){
          ans.push_back(0);
          n--;
        }
      }

    }
    return ans;
}
    




int main(){
    int t;
    t=1;
    vector<vector<int>>ans;
    for (int i=0;i<t;i++){
    
        ans.push_back(solve());
      
    }
    for (vector<int> c: ans){

      for (int x:c){
        cout<<x;
      }
    }
    
  return 0;
}

