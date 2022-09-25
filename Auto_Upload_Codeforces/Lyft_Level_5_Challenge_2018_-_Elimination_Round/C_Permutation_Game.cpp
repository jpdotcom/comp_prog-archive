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
int dp[100001];

vector<int>adj[100001];

int dfs(int u){
    
    if (dp[u]!=-1){
        
        return dp[u];}
    if (adj[u].size()==0){
        dp[u]=0;
        
        return 0;}
    dp[u]=0;
    for (int v:adj[u]){
        
        if (dp[v]==-1){
            dfs(v);
    
        }
        if (dp[v]==0){
            dp[u]=1;}}
    return dp[u];
}
int main(){
    
    int n;
    cin>>n; 
    fill_n(dp,100001,-1);

    int arr[n+1]; 
    int idx[n+1];
    for (int i=0;i<n;i++){

        cin>>arr[i];
        idx[arr[i]]=i;
        }
    for (int i=0;i<n;i++){
        
        int val=arr[i];
        for (int j=i-val;j>=0;j-=arr[i]){
                if (arr[j]>val){
                    adj[val].push_back(arr[j]);}}
        for (int j=i+val;j<n;j+=val){
            if (arr[j]>val){
                adj[val].push_back(arr[j]);}}}
    
    dfs(1);
    int ans[n]={0};
    for (int i=1;i<n+1;i++){
        
        int win=dp[i];
        if (win){
            ans[idx[i]]=1;
            }}
    for (int x:ans){
        if (x){
            cout<<"A";}
        else{
         cout<<"B";}
    }
    return 0;
