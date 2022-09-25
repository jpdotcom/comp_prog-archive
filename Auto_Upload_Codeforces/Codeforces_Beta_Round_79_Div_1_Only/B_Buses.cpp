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
    return res;
}
 
int main(){
    
    int n,m;
    cin>>n>>m;
    
    vector<pair<int,int>> arr;
    int dp[m+1]; 

    int sum_dp[m+1];
    fill_n(sum_dp,m+1,0);
    fill_n(dp,m+1,0);
    arr.push_back(make_pair(0,0));
    for (int i=1;i<m+1;i++){
        int a,b;
        cin>>a>>b;
        pair<int,int>p1;
        p1=make_pair(a,b);
        arr.push_back(p1);
    }
    sort(arr.begin(), arr.end(), [](auto &left, auto &right) {
    return left.second < right.second;
});
    
    dp[0]=1;
    sum_dp[0]=1;
    int modu=pow(10,9)+7;
    
    for (int i=1;i<m+1;i++){
        sum_dp[i]+=sum_dp[i-1];
        int best1,best2;
        int x,y;
        x=arr[i].first;
        y=arr[i].second;
    
        int l=0;
        int r=i-1;
        best1=-1;
        best2=-1;
        while (l<=r){
            
            int mid=l+(r-l)/2;
            
            int a,b;
            a=arr[mid].first;
            b=arr[mid].second;
            if (x<=b && b<y){
                
                best1=mid;
                r=mid-1;}
            else if (b>=y){
                r=mid-1;
            }
            else{
                l=mid+1;}
        }
        l=0;
        r=i-1;
        while (l<=r){
            
            int mid=(l+r)/2;
            
            int a,b;
            a=arr[mid].first;
            b=arr[mid].second;
            if (x<=b && b<y){
                best2=mid;
                l=mid+1;}
            else if (b>=y){
                r=mid-1;
            }
            else{
                l=mid+1;}
        }
        if (best1!=-1){
            int l_sum,r_sum;
            if (best1==0){
                l_sum=0;
            }
            
            else {l_sum=sum_dp[best1-1];}
            r_sum=sum_dp[best2];
            dp[i]=r_sum-l_sum;
            sum_dp[i]+=r_sum-l_sum;
            dp[i]=mod(dp[i],modu);;
            sum_dp[i]=mod(sum_dp[i],modu);
        }}
        
    int ans=0;
    for (int i=0;i<m+1;i++){
        int a;
        
        a=arr[i].second;
        if (a==n){
            ans+=dp[i];
            ans=mod(ans,modu);}


    }
    cout<<ans;
    return 0;
}
