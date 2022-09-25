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


const int N = 1e6;  // limit for array size

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

long long solve(){
    int n;
    cin>>n;
    build(n);
    map<int,int>idxof;
    int arr[n];
    int sorted[n];
    map<int,int>cnt;
    for (int i=0;i<n;i++){
        cin>>arr[i];
        sorted[i]=arr[i];
    }
    sort(sorted,sorted+n);

    for (int i=0;i<n;i++){
        if (idxof.find(sorted[i])==idxof.end()){
            idxof[sorted[i]]=i;
        }
        
    }
    long long ans=0LL;
    for (int i=0;i<n;i++){
        long long smaller=query(0,idxof[arr[i]],n);
        long long larger=query(idxof[arr[i]]+1,n,n);
        ans+=min(smaller,larger)*1LL;
        if (cnt.find(arr[i])==cnt.end()){
            cnt[arr[i]]=0;
        }
        cnt[arr[i]]++;
        modify(idxof[arr[i]],cnt[arr[i]],n);
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    vector<long long>ans;
    for (int i=0;i<t;i++){
    
        ans.push_back(solve());
      
    }
    for (long long x:ans){

        cout<<x<<endl;
    }
    
}









    









    
