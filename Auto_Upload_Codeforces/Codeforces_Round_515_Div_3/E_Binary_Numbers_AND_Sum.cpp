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
    return res;
}
 
int main(){
    int n,m;
    cin>>n>>m;
    int fill;
    if (n>m){
        fill=n;}
    else{
        fill=m;}

    int mod=998244353;
    char s1[fill];
    char s2[fill];
    fill_n(s1,fill,'0');
    fill_n(s2,fill,'0');
    for (int i=0;i<n;i++){
        int diff=0;
        if (n<m){
            diff=max(n,m)-min(n,m);}
        cin>>s1[i+diff];}
    for (int i=0;i<m;i++){
        int diff=0;
        if (m<n){
            diff=max(n,m)-min(n,m);}
        cin>>s2[i+diff];}
    

    
    unsigned long long cnt=0;
    unsigned int p=fill-1;
    unsigned long long ans=0;
    for (int i=0;i<fill;i++){
        
            if (s2[i]=='1'){
                cnt++;}
        
    
        if (s1[i]=='1'){
        unsigned long long add;
        add=(power(2,p,mod)*cnt%mod)%mod;
        ans+=add;
        ans%=mod;
        ;}
        p--;



    }
    cout<<ans;
    return 0;}
