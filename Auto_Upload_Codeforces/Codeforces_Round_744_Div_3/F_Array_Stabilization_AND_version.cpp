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
bool seen[maxN];
vector<int>num1;
int longest[maxN];
int dfs(int i, int n, int d){
    seen[i]=true;
    int ans=1;
    if (arr[i]==0){
      ans=-1;
    }
    num1.push_back(arr[i]);
  
    if (!seen[(i+n-d)%n]){
    ans=min(dfs((i+n-d)%n,n,d),ans);}
    return ans;
 }


int solve(){
   int n,m;
   cin>>n>>m;
   int ans=0;
   for (int i=0;i<n;i++){
     cin>>arr[i];
     seen[i]=false;
   }

   for (int l=0;l<n;l++){
     if (!seen[l]){
       num1.clear();
       int check=dfs(l,n,m);
       if (check==1){
         return -1;
       }
       else{
         for (int i=num1.size()-1;i>=0;i--){
           if (i==num1.size()-1){
             longest[i]=num1[i];
           }
           else{
             if (num1[i]==0){
               longest[i]=0;
             }
             else{
               longest[i]=longest[i+1]+1;
             }
           }

         } 
         for (int i=0;i<num1.size();i++){

           int val=longest[i];
           if (val==num1.size()-i){
             val+=longest[0];
           }
           ans=max(ans,val);
       }
     }
   }
   }
   return ans;
}
 
  
 
 
 
 
int main(){
    int t;
    cin>>t;
    vector<int>out;
    while(t--){
      out.push_back(solve());
    }
    for (int ans:out){
      cout<<ans<<endl;
    }
 
 
  return 0;
}