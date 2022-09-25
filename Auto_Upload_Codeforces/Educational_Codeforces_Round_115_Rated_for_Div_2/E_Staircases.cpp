#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll modu(ll a,ll b){
    return (b+(a%b)) % b;}
 
int power(long long x, unsigned int y, int p)
{
    unsigned long long res = 1;     // initialize result
 
    x = x % p; // update x if it is more than or
                // equal to p
  
    if (x == 0) return 0; // in case x is divisible by p;
 
    while (y > 0)
    {
        // if y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;}
 
 
const int n = 1e6;  // limit for array size
 
int t[2 * n];
 
void build(int n) {  // build the tree
 
  for (int i = n - 1; i > 0; --i) t[i] = 0;
}
 
void modify(int p, int value,int n) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = max(t[p],t[p^1]);
}
 
int query(int l, int r,int n) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = max(res,t[l++]);
    if (r&1) res = max(res,t[--r]);
  }
  return res;
}
const int maxN=1005;
int dp[maxN][maxN][2];
int on[maxN][maxN];
int solve(){

  int n,m,q;
  cin>>n>>m>>q;
  int ans=0;
  for (int i=1;i<=n;i++){
    for (int j=1;j<=m;j++){
      on[i][j]=1;
      for (int k=0;k<2;k++){
        dp[i][j][k]=1;
        if (i==1 && j==1){
          dp[i][j][k]=1;
        }

        else{
          if (k==0 && j>1){
            dp[i][j][k]+=dp[i][j-1][k^1];
          }
          else if (i>1 && k==1){
            dp[i][j][k]+=dp[i-1][j][k^1];
          }

        }

      }
      ans+=dp[i][j][0]+dp[i][j][1]-1;
    }
  }
  
  for (int i=0;i<q;i++){
    int a,b;
    cin>>a>>b;
    int f1=a;
    int f2=b; 
    int s=0;
    int sub=0;
    int mult=-1;
    if (on[a][b]){
      mult*=-1;
    }
    on[a][b]^=1;
    while (f1>=1 && f2>=1 && (on[f1][f2] || f1==a && f2==b)){
      if (s==0){
        f1-=1;
      }
      else{
        f2-=1;
      }
      s^=1;
      sub++;
    }
    f1=a;
    f2=b;
    s=1;
    int sub2=0;
    while (f1<=n && f2<=m && (on[f1][f2] || f1==a && f2==b)){
      if (s==0){
        f1++;
      }
      else{
        f2++;
      }
      s^=1;
      sub2++;
    }
    ans-=mult*sub*sub2;
    f1=a;
    f2=b;
    sub=0;
    sub2=0;
    s=0;
    while (f1>=1 && f2>=1 && (on[f1][f2] || f1==a && f2==b)){
      if (s==0){
        f2--;
      }
      else{
        f1--;
      }
      s^=1;
      sub++;
    }
    f1=a;
    f2=b;
    s=1;
    while (f1<=n && f2<=m && (on[f1][f2] || f1==a && f2==b)){
      if (s==0){
        f2++;
      }
      else{
        f1++;
      }
      s^=1;
      sub2++;
    }
    ans-=mult*sub*sub2;
    ans+=mult;
    cout<<ans<<endl;
  }
  return 0;
}


  

  
    
  

int main(){
    int t=1;
    while(t--){
      solve();
    }
    return 0;
}