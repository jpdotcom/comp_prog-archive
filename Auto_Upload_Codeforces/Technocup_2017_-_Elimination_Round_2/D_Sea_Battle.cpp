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

    int n,a,b,k;
    cin>>n>>a>>b>>k;
    char s[n];
    for (int i=0;i<n;i++){
        cin>>s[i];}

    vector<int> ans;
    int cnt=0;
    for (int i=0;i<n;i++){
        
        if (s[i]=='1'){
            cnt=0;
        }
        else{cnt++;}

        if (cnt==b){
            cnt=0;
            ans.push_back(i+1);}
    }
    
    cout<<ans.size()-a+1<<"\n";
    
    for (int i=0;i<ans.size()-a+1;i++){
        cout<<ans[i]<<' ';
    }
    return 0;}
