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
 
int t[2 * n][2];

void build(int n) {  // build the tree
 
  for (int i =2*n - 1; i > 0; --i){
    t[i][0]=10000;
    t[i][1]=10000;
  }
}
 
void modify(int p, vector<int> value,int n) {  // set value at position p
  
  p+=n;
  int c=p;
  t[p][0]=value[0];
  t[p][1]=value[1];
  
  for (int d=c ; d > 1; d >>= 1){
      p=d;
      if (t[p][0]>t[p^1][0]){
        t[p>>1][0]=t[p^1][0];
        t[p>>1][1]=t[p^1][1];
      }
      else{
        t[p>>1][0]=t[p][0];
        t[p>>1][1]=t[p][1];
      }
  }

}
 
int query(int l, int r,int n) {  // sum on interval [l, r)
  int res = 1e9;
  int idx=100;
  int prev_res=res;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    cout<<l<<r<<endl;
    if (l&1){ res = min(res,t[l++][0]);
    if (prev_res!=res){
      
      idx=t[l-1][1];
      prev_res=res;
    }}
    if (r&1){ res =min(res,t[--r][0]);
    if (prev_res!=res){
      idx=t[r+1][1];
      prev_res=res;
    }

    }
    cout<<res<<endl;

  }
  return idx;
}
long long NCR(int n, int r)
{
    if (r == 0) return 1;

    /*
     Extra computation saving for large R,
     using property:
     N choose R = N choose (N-R)
    */
    if (r > n / 2) return NCR(n, n - r); 

    long long res = 1; 

    for (int k = 1; k <= r; ++k)
    {
        res *= n - k + 1;
        res /= k;
    }

    return res;
}
long long solve(){
  int n;
  cin>>n;
  long long ans=n*1LL*(n-1)*(n-2)/6;
  int colors[n+1];
  int diff[n+1];
  map<pair<int,int>,int> both;
  for (int i=1;i<=n;i++){
    colors[i]=0;
    diff[i]=0;
  }
  int arr[n][2];
  for (int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    colors[a]++;
    diff[b]++;
    arr[i][0]=a;
    arr[i][1]=b;
  }
  for (int i=0;i<n;i++){
    int color=arr[i][0];
    int d=arr[i][1];
    long long sub=(colors[color]-1)*1LL*(diff[d]-1);
    ans-=sub;
  }
  return ans;

}
  
  
  
  



  

  
    
  

int main(){
    int t;
    cin>>t;
    vector<long long> out;
    while(t--){
      out.push_back(solve());
    }
    for (long long x: out){
      cout<<x<<endl;
    }

    return 0;
}