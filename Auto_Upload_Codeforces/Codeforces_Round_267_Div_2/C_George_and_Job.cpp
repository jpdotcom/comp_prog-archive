#include <bits/stdc++.h>
using namespace std;
long long dp[2][10000]={0};
int main(){
  
  long long arr[10000]; 
  long long prefix[10000];
  
  long long n;
  long long m;
  long long k;
  cin>>n>>m>>k;
  
  for (long long i=0; i<n;i++){
    long long val; 
    cin>>val; 
    arr[i]=val;
    
  }
  prefix[0]=0;
  for (long long i=1; i<n+1;i++){
    prefix[i]=prefix[i-1]+arr[i-1];
  }
  long long flip=1;
  
  
  for (long long i=1;i<k+1;i++){
    
    for (long long j=0;j<n+1;j++){
      if (j>=m){
        long long val=prefix[j]-prefix[j-m];
      
        dp[flip][j]=max(dp[flip][j-1],val+dp[flip^1][j-m]);
      }
      else if (j>0){
        
        dp[flip][j]=dp[flip][j-1];
      }
     
    }
    flip^=1;
  }
  
 
  cout<<dp[flip^1][n];
  return 0;
  
  
  
  
 
  
  

