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
const int maxN=3e5;
int arr[maxN];
int val[55][6];
void solve(){
    int n; cin>>n;
    for (int i=0;i<55;i++)
        for (int j=0;j<6;j++)
            val[i][j]=0;
    for (int i=0;i<n;i++){
        cin>>arr[i];
        int v=arr[i];
        string s=to_string(v);
        int sum=0;
        for (int j=0;j<s.length();j++){
            sum+=s[j]-'0';
        }
        val[sum][s.length()]++;
    }
    long long ans=0;
    for (int i=0;i<n;i++){
        string s = to_string(arr[i]);
        int sum_l,sum_r;
        sum_l=0;
        sum_r=0;
        for (int j=0;j<s.length();j++) sum_r+=s[j]-'0';
        for (int j=0;j<s.length();j++){
            sum_l+=s[j]-'0';
            sum_r-=s[j]-'0';
            if (2*(j+1)>=s.length() && sum_l>=sum_r){
                ans+=val[sum_l-sum_r][2*(j+1)-s.length()];
            }
        }
    }
    for (int i=0;i<n;i++){
        string s = to_string(arr[i]);
        int sum_l,sum_r;
        sum_l=0;
        sum_r=0;
        for (int j=0;j<s.length();j++) sum_l+=s[j]-'0';
        for (int j=s.length()-1,l=0;j>0;j--,l++){
            sum_r+=s[j]-'0';
            sum_l-=s[j]-'0';
            if (2*(l+1) >= s.length() && sum_r>=sum_l){
                ans+=val[sum_r-sum_l][2*(l+1) - s.length()];
            }
        }
    }
    cout<<ans<<endl;
    return;
}
int main(){
    int t=1;
    while (--t){
        solve();
    }
    solve();
    return 0;
}
