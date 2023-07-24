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
void solve(){
    pair<int,int> a;
    pair<int,int> b;
    pair<int,int> c;
    cin>>a.first>>a.second>>b.first>>b.second>>c.first>>c.second;
    int x1=b.first-a.first;
    int y1=b.second-a.second;
    int x2=c.first-a.first;
    int y2=c.second-a.second;
    int ans=0;

    if ((x1<=0 && x2<=0) || (x2>=0 && x1>=0)){
        ans+=min(abs(x1),abs(x2));
    }

    if ((y1<=0 && y2<=0) || (y2>=0 && y1>=0)){
        ans+=min(abs(y1),abs(y2));
    }
    cout<<1+ans<<endl;
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
