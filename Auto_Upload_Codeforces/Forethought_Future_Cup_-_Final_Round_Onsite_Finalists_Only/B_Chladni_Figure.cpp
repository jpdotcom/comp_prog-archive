#include <bits/stdc++.h>
typedef long long ll;
#define FOR(n) for (int i=0;i<n;i++)
#define pb(x) push_back(x)
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
#define PI  3.14159265358979323846
#define F first
#define S second
#define endl '\n'
#define print(x) cout<<x<<'\n'
using namespace std;
int power(long long x, unsigned int y, int p)
{
    unsigned long long res = 1;   
    x = x % p;
    if (x == 0) return 0; 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
const int N = 5;  // limit for array size
int n; // array size
ll modu(ll a,ll b){
    return (b+(a%b)) % b;}
void precompute(){
}
const int maxN=1e5+5;
vector<int> get_div(int n){
  
  vi div;
  int end=sqrt(n);
  for(int i=2;i<=end;i++){
    int a=n/i;
    if (a*i==n){
      div.pb(i);
      if (i!=a){
        div.pb(a);
      }
    }
  }
  div.pb(1);
  return div;
}
void solve(){
  int m;
  scanf("%d%d",&n,&m);

  set<pi>points;
  FOR(m){
            int a,b;
        scanf("%d%d",&a,&b);
    if (a>b){
      swap(a,b);
    }
    points.insert(make_pair(a,b));
  }
  vi divs=get_div(n);
  for (int p:divs){
    int ok=1;
    for (auto x:points){
      int v1=x.F+p;
      if (v1>n) v1-=n;
      int v2=x.S+p;
      if (v2>n) v2-=n;
      if (v1>v2){
        swap(v1,v2);
      }
      ok&=(points.find(make_pair(v1,v2))!=points.end());
    }
    if (ok){
      print("YES");
      return;
    }
  }
  print("NO");
  return;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t=1;
  FOR(t){
    solve();
  }
  return 0;
}
    