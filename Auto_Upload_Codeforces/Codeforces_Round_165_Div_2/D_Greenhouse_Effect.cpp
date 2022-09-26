#include <iostream>
#include <bits/stdc++.h>

using namespace std;
vector<pair<double,int>>arr;
const int maxN=5005,maxM=5005;
int dp[maxN][maxM];
void solve(){
  int n,m;
  cin>>n>>m;
  for (int i=0;i<n;i++){
    pair<double,int>p;
    cin>>p.second>>p.first;
    arr.push_back(p);
  }
  sort(arr.begin(),arr.end());
  int ans=1e9;
  dp[0][0]=0;
  for (int i=1;i<=n;i++){
    int min_prev=dp[i-1][1];
    for (int j=1;j<=m;j++){
      min_prev=min(min_prev,dp[i-1][j]);
      pair<double,int> p = arr[i-1];
      dp[i][j]=((p.second==j) ? 0 : 1 ) +min_prev;

      if (i==n){
        ans=min(ans,dp[i][j]);
      }
    }
  }
  cout<<ans;
  
}
int main() {

  int t=1;
  vector<int>o;
  while (t--){
    solve();
  }
