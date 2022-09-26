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
pair<int,int> solve(){
  int n;
  long long s;
  cin>>n>>s;
  int arr[n];
  long long orig=s;
  for (int i=0;i<n;i++){
    cin>>arr[i];
  }
  int i=0,j=0;
  int len=0;
  pair<int,int>p;
  p.first=-1;
  int flag=0;
  while (i!=n && j!=n){
    if (flag==0){
      s+=arr[j];
    }
    if (s<0){
      flag=1;
      if (i!=j){
        s-=arr[i];
        i++;
      }
      else{
        i++;
        j=i;
        s=orig;
        flag=0;
      }
    }
    else{
      flag=0;
      if (j-i+1>len){
        p.first=i+1;
        p.second=j+1;
        len=j-i+1;
      }
      j++;

    }

  }
  return p;
    
}
  

int main(){
    int t;
    cin>>t;
    vector<pair<int,int>>out;
    while(t--){
      out.push_back(solve());
    }
    for (pair<int,int> p: out){
      if (p.first==-1){
        cout<<-1<<endl;
      }
      else{
      cout<<p.first<<' '<<p.second<<endl;
      }

    }

    return 0;
}