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
ll power(ll x, ll y, ll  p)
{
    ll res=1;
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
const int maxN=1005;
int arr[maxN];
void solve(){

  int n;cin>>n;
  FOR(n){
    cin>>arr[i];
  }
  if (n==1){
    cout<<-1<<endl;
    return;
  }
  int seen[n+1];
  FOR(n+1) seen[i]=0;
  FOR(n){
    bool ok=false;
    for (int j=1;j<=n;j++){
      if (!seen[j] && arr[i]!=j){
        arr[i]=j;
        ok=seen[j]=1;
        break;
      }
    }
    if (!ok){
      swap(arr[i],arr[i-1]);
    }
  }
  FOR(n){
    cout<<arr[i]<<' ';
  }
  cout<<endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t=1;
  cin>>t;
  while (t--) solve();
  return 0;
}
    