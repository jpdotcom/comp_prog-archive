#include <bits/stdc++.h>
typedef long long ll;
#define FOR(n) for (int i=0;i<n;i++)
typedef std::pair<long long, long long> pi;
typedef std::vector<long long> vi;
#define PI  3.14159265358979323846
#define F first
#define S second
#define endl '\n'
#define print(x) cout<<x<<'\n'

using namespace std;

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
    return res;
}
int op(int a,int b){
  return a+b;
}
const int N = 5;  // limit for array size
int n; // array size
int t[2 * N];

void build() {  // build the tree
  for (int i = 2*N-1;i>=0;i--) t[i]=0; }

void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = op(t[p],t[p^1]);
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = op(res,t[l++]);
    if (r&1) res = op(res,t[--r]);
  }
  return res;
}
ll modu(ll a,ll b){
    return (b+(a%b)) % b;}

int bin_search(int l,int r,int val,int prefix[]){
  int best=-1;
  int begin=l;
  while (l<=r){
    int m=(r-l)/2+l;
    if (prefix[m]-prefix[begin-1]<=val){
      best=m;
      l=m+1;
    }
    else{
      r=m-1;
    }
  }
  return best;
}

int nearest_val(int val){
  if (val<=1){
    return 1;
  }
  int x=1;
  while (2*x<val){
    x*=2;
  }
  return 2*x;

}
void precompute(){}


void solve(){
  cin>>n;
  int prefix[n+2];
  FOR(n+2){
    prefix[i]=0;
  }
  for (int i=0;i<n;i++){
    int val;
    cin>>val;
    prefix[val]++;
  }
  FOR(n+2){
    prefix[i]+=(i==0 ? 0 :prefix[i-1]);
  }
  int ans=1e9;
  for (int i=1;i<=2*n;i*=2){
    for (int j=1;j<=2*n;j*=2){
      int idx1=bin_search(1,n,i,prefix);
      if (idx1==-1){
        continue;
      }
      int idx2=bin_search(idx1+1,n+1,j,prefix);
      if (idx2==-1){
        continue;
      }
      int x=i-prefix[idx1];
      int y=j-(prefix[idx2]-prefix[idx1]);
      int z=nearest_val(prefix[n+1]-prefix[idx2])-(prefix[n+1]-prefix[idx2]);     
      ans=min(ans,x+y+z);
    }
  }
  print(ans);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t=1;
  cin>>t;
  FOR(t){
    solve();
  }
  return 0;
}
    