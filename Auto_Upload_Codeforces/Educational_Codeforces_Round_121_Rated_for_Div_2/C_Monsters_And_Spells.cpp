#include <bits/stdc++.h>
typedef long long ll;
#define FOR(a,b) for(int i=0;i<b;i++)
typedef std::pair<long long, long long> pi;
typedef std::vector<long long> vi;
#define PI  3.14159265358979323846
#define F first
#define S second
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

void precompute(){

}
int bin_search(int x,int val){
  return x-val+1;
  
}
void solve(){
  cin>>n;
  vector<pi>larg;
  pi arr[n];
  pi intervals[n];
  for (int i=0;i<n;i++){
    int val;
    cin>>val;
    arr[i].F=val;
  }
  for (int i=0;i<n;i++){
    int val;
    cin>>val;
    arr[i].S=val;
  }
  int i=0;
  for (pi p:arr){ 
    int lower=bin_search(p.F,p.S);
    int upper=p.F;
    intervals[i].F=lower,intervals[i].S=upper;
    i++;
  }
  sort(intervals,intervals+n);
  for (int i=0;i<n;i++){
    if (larg.size()==0){
      larg.push_back(intervals[i]);

    }
    else{
      int y1=larg.back().S;
      int x2=intervals[i].F;
      if (x2<=y1){
        larg.back().F=min(larg.back().F,intervals[i].F);
        larg.back().S=max(larg.back().S,intervals[i].S);
      }
      else{
        larg.push_back(intervals[i]);
      }
    }
  }
  ll ans=0;
  for (pi p:larg){
    ans+=(p.S-p.F+1)*(p.S-p.F+2)/2;
  }
  cout<<ans<<endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t=1;
  cin>>t;
  while (t--){
    solve();
  }
  return 0;
}
    