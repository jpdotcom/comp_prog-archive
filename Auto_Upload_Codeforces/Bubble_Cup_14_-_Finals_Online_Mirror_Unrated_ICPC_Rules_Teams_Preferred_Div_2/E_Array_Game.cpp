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
const int maxN=1e6+5;
int arr[maxN];
int longest_l[maxN];
int longest_r[maxN];
int dfs(int l,int r,int val){
  int ans=0;
  if (l>r){
    return 0;
  }
  if (arr[l]<=val && arr[r]<=val){
    return ans;
  }
  else if (arr[l]>=arr[r] && arr[l]>val){
    ans|=(longest_r[l]%2);
    if (arr[r]>val){
    ans|=(dfs(l,r-1,arr[r])^1);
    }
  }
  else{
  ans|=(longest_l[r]%2);
  if (arr[l]>val){
    ans|=(dfs(l+1,r,arr[l])^1);
        }
        }
  return ans;
  }
int solve(){

  int n;
  longest_l[0]=1;
  cin>>n;
  for (int i=0;i<n;i++){
    cin>>arr[i];
    if (i!=0){
      if (arr[i]<arr[i-1]){
      longest_l[i]=longest_l[i-1]+1;
      }
      else{
        longest_l[i]=1;
      }
    }
    
  }
  longest_r[n-1]=1;
  for (int i=n-2;i>=0;i--){

    if (arr[i]<arr[i+1]){
      longest_r[i]=longest_r[i+1]+1;
    }
    else{
      longest_r[i]=1;
    }
  }
  return dfs(0,n-1,-1);
  
}

 
  
 
 
 
 
int main(){
    int t=1;
    vector<int>out;
    while(t--){
      out.push_back(solve());
    }
    for (int ans:out){
      if (ans){
        cout<<"Alice"<<endl;
      }
      else{
      cout<<"Bob"<<endl;
      }
    }
 
 
  return 0;
}