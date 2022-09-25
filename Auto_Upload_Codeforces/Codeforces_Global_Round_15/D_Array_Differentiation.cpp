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


const int N = 1e6;  // limit for array size

int t[2 * N];

void build(int n) {  // build the tree

  for (int i = n - 1; i > 0; --i) t[i] = 0;
}

void modify(int p, int value,int n) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = gcd(t[p],t[p^1]);
}

int query(int l, int r,int n) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = gcd(res,t[l++]);
    if (r&1) res = gcd(res,t[--r]);
  }
  return res;
}





        
const int maxN=1e5;
int freq[maxN][26];
int solve(){

    int n;
    cin>>n;
    map<int,int>s;
    int a[n];
    for (int i=0;i<n;i++){

        cin>>a[i];
    }

    for (int i=1;i<(1<<n)+1;i++){

        int sum=0;
        for (int j=0;j<n;j++){
            
            if ((i>>j)%2){
                sum+=a[j];
            }
        }
        s[sum]++;
    }

    for (auto x:s){

        if (x.second>1){
            return 1;
        }
    
    }
    return 0;
}




        




    


int main(){
    
    int t;
    cin>>t;
    vector<int>o;
    while (t--){

        o.push_back(solve());
    }

    for (int x:o){
        if (x==1){
            cout<<"YES"<<'\n';
        }
        else{
            cout<<"NO"<<'\n';
        }
    }
}








    
