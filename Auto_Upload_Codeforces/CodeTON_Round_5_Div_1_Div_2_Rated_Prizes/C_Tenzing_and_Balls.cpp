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
#include <iostream>
#define FOR(a,b) for (int i=a;i<b;++i)
typedef long long ll;
using namespace std;
const int maxN=1e6;
int a[maxN];
int mv[maxN];
int dp[maxN];
void solve(){
    int n; cin>>n;
    for (int i=0;i<n;i++) cin>>a[i];
    for (int i=0;i<=n;i++){
        mv[i]=-1*n-1;
        dp[i]=-0;
    }

    for (int i=0;i<n;i++){
        dp[i]=max(dp[i],i+mv[a[i]]+1);
        if (i!=0){
            dp[i]=max(dp[i],dp[i-1]);
            mv[a[i]]=max(mv[a[i]],dp[i-1]-i);
        }
        mv[a[i]]=max(mv[a[i]],-1*i);
    }
    cout<<dp[n-1]<<endl;
}
int main(){
    int t; 
    cin>>t;
    while (--t){
        solve();
    }
    solve();
    return 0;
}
