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
int dp[50001][501];
vector<int> adj[50001];
int p[50001];
int dfs(int u, int k){
    
    if (k==0){
        
        dp[u][k]=1;
        return 1;
    }

    int ans=0; 

    for (int v:adj[u]){
        if (v!=p[u]){
            p[v]=u;
            if (dp[v][k]==-1){
            dfs(v,k-1);}


            ans+=dp[v][k-1];
        }}
    dp[u][k]=ans;
    return ans;}
int rest(int u,int k){

    long long ans=0;

    for (int x=1;x<k;x++){
        
        for (int v:adj[u]){
            if (v!=p[u]){
            long long add=(dp[v][x-1]*(dp[u][k-x]-dp[v][k-x-1]));
            
            ans+=add;}}
    
    }
    ans*=0.5;

    return ans;}
int main(){

    int n,k;
    cin>>n>>k;
    for (int i=1;i<n+1;i++){
        for (int j=0;j<k+1;j++){
            dp[i][j]=-1;}}
    for (int i=1;i<n+1;i++){
        p[i]=0;}

    for (int i=0;i<n-1;i++){
        
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for (int i=1;i<n+1;i++){
        
        for (int j=0;j<k+1;j++){
            dfs(i,j);
        }
    }
    
    long long ans=0;
    for (int i=1;i<n+1;i++){
        ans+=dp[i][k];
        }

    for (int i=1;i<n+1;i++){
        ans+=rest(i,k);}
    cout<<ans;
    return 0;
} 

