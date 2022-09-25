
using namespace std;
#include <bits/stdc++.h>
long mod(long a, long b)
{ return (a%b+b)%b; }

// long long dp[2][10000]={0};

int main(){
 
  long long m=pow(10,9)+7;
  long long arr[100001];
  
  arr[0]=1;
  
  
  
  long long t,k;
  cin>>t>>k;
  
  for (long long i=1;i<100001;i++){
    long long val=arr[i-1];
    
    if ((i-k)>=0){
      val+=arr[i-k];
    }
    val=mod(val,m);
    arr[i]=val;
    
  }
  for (long long i=1;i<100001;i++){
    arr[i]+=arr[i-1];
    arr[i]=mod(arr[i],m);
  }
  vector<long long> solve;
  long long i=0;
  while (t--){
    
    long long a,b;
    cin>>a>>b;
    
    solve.push_back(mod(arr[b]-arr[a-1],m));
    
  }
  for (long long i=0;i<solve.size();i++){
    cout<<solve[i]<<"\n";
  }
  return 0;
  
