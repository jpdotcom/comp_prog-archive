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


int dp[30001][501];


int main(){
    for (int i=0;i<30001;i++){
        for (int j=0;j<501;j++){
        dp[i][j]=0;}}

    int n,d;
    cin>>n>>d;
    int cnt[30001];
    for (int i=0;i<30001;i++){
        cnt[i]=0;
    }

    
    for (int i=0;i<n;i++){
        int val;
        cin>>val;
        cnt[val]++;}

    for (int i=30000;i>=0;i--){
        for (int j=0;j<501;j++){
            
            int dist=d+j-250;
            if (dist>0){
                
                int curr=i+dist-1;
                if (curr!=i && j>0 && curr>0 && curr<30001){
                    dp[i][j]=max(dp[i][j],dp[curr][j-1]);}
                curr++;
                if (curr!=i && curr<30001){
                    dp[i][j]=max(dp[i][j],dp[curr][j]);}
                curr++; 
                if (curr!=i && j<501 && curr<30001){
                    dp[i][j]=max(dp[i][j],dp[curr][j+1]);}



                    }
            dp[i][j]+=cnt[i];}}
    cout<<dp[d][250];
    return 0;}
