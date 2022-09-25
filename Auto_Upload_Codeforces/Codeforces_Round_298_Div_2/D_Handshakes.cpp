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


const int N = 1001;

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

        
vector<int> solve(){
    int n;
    cin>>n;
    int nums=0;
    
    map<int,vector<int>>idxof;
    for (int i=0;i<n;i++){
            int val;
            cin>>val;
            if (idxof.find(val)==idxof.end()){
                vector<int> p;
                idxof[val]=p;
            }
            idxof[val].push_back(i);

    }
    int total=n;
    vector<int>ans;
    while (total && nums>=0){
        if (idxof.find(nums)!=idxof.end() && idxof[nums].size()>0){
                int idx=idxof[nums].back()+1;
                idxof[nums].pop_back();
                ans.push_back(idx);
                nums++;
        }
        else{
            nums-=3;
        }
    }
    if (ans.size()!=n){
        ans.clear();
    }
    return ans;
}

            




int main(){
    vector<vector<int>>ans;
    int t=1;
    for (int i=0;i<t;i++){
    
        ans.push_back(solve());
      
    }
    for (vector<int> x : ans){
        if (x.size()>0){
            cout<<"Possible"<<endl;
            for (int e : x){
                cout<<e<<' ';
            }
        }
        else{
            cout<<"Impossible"<<endl;
        }
    }
    
}
    
