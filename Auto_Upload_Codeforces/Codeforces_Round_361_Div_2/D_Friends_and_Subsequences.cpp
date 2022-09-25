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
using namespace std;
int mod(int a,int b){
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

const int N = 1e6+1;  // limit for array size
int n;  // array size
long long t[2 * N][2];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) {
      t[i][0] = min(t[i<<1][0],t[i<<1|1][0]);
      t[i][1] = max(t[i<<1][1],t[i<<1|1][1]);
    }
}

void modify(int p, long long value,int id) {  // set value at position p
  for (t[p += n][id] = value; p > 1; p >>= 1){
      long long s;
      if (id==0){
          s=min(t[p][id],t[p^1][id]);
        }
      else{
          s=max(t[p][id],t[p^1][id]);}
      t[p>>1][id] = s;
}}

long long query(int l, int r, int id) {  // sum on interval [l, r)
  long long res; 
  if (id){
    res=-10e9+10;}
  else{
      res=10e9+10;}
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1){
        if (id){
        res=max(res,t[l++][id]); }
        else{
        res=min(res,t[l++][id]);}}
    if (r&1){ 
        if (id){
        res=max(res,t[--r][id]);
        }
        else{
        res=min(res,t[--r][id]);}}}
  return res;}


int main() {
    cin>>n;
    build();
    
    int arr1[n];
    int arr2[n];
    
    for (int i=0;i<n;i++){
        cin>>arr1[i];
        modify(i+1,arr1[i],1);}

    for (int i=0;i<n;i++){
        cin>>arr2[i];
        modify(i+1,arr2[i],0);}
    
    long long ans=0; 

    for (int i=0;i<n;i++){
        int l=i+1;
        int r=n+1;
        int best=-1;
        while (l<=r){
            int m=(l+r)/2;
            long long val1=query(i+1,m,0);
            long long val2=query(i+1,m,1);
            if (val1==val2){
                l=m+1;
                best=m;
        }
            else if (val1>val2){
                l=m+1;}
            else{
                r=m-1;}
        }
        l=i+1;
        r=n+1;
        int best2=-1;
        while (l<=r){
            int m=(l+r)/2;
            long long val1=query(i+1,m,0);
            long long val2=query(i+1,m,1);

            if (val1==val2){
                r=m-1;
                best2=m;

        }
            else if (val1>val2){
                l=m+1;}
            else{
                r=m-1;}
        }
        
        if (best!=-1 && best2!=-1){
            ans+=(best-best2+1);}
    }

    cout<<ans;
    return 0;}
    
