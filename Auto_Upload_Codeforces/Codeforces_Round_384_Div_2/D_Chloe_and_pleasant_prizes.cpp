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
vector<int> adj[200001];
int arr[200001];
long long sum[200001];
long long one_tree[200001];
long long dp[200001];

long long dfs(int u,int p){

    long long ans=arr[u]; 

    for (int v:adj[u]){
        if (v!=p){
            ans+=dfs(v,u);}}

    sum[u]=ans;
    return ans;}

long long dfs2(int u,int p){
    long long ans=sum[u];

    for (int v:adj[u]){
        if (v!=p){
            ans=max(ans,dfs2(v,u));
        }}
    one_tree[u]=ans;
    return ans;
    }
long long dfs3(int u, int p){
    long long inf=-100000000000;

    long long ans=inf;
    long long a=inf;
    long long b=inf;

    for (int v:adj[u]){
        if (v!=p){
            ans=max(ans,dfs3(v,u));
            
            if (one_tree[v]>a){
                b=a;
                a=one_tree[v];}
            else if (one_tree[v]>b){
                b=one_tree[v];}
        }}
    if (b!=inf){
        ans=max(ans,a+b);
        }
    
    dp[u]=ans;
    return ans;}





int main(){

    int n;
    cin>>n;
    long long inf=-100000000000;
    for (int i=1;i<n+1;i++){
        cin>>arr[i];}
    for (int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        
        adj[a].push_back(b);
        adj[b].push_back(a);}
    dfs(1,0);
    dfs2(1,0);
    dfs3(1,0);

    if (dp[1]==inf){
        cout<<"Impossible";}
    else{ 
        cout<<dp[1];}
    return 0;}



