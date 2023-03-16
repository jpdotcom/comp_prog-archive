#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(a) for(int i=0;i<a;i++)
#define mp(a,b) make_pair(a,b)
#define all(a)  a.begin(),a.end()
typedef std::vector<long  long> vi;
typedef long long ll;
typedef std::pair<ll,ll> pi;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>(s))&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+10)
#define MOD ((ll)1e9+7)
using namespace std;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=1e6+1;
vector<int> a[maxN];
vector<int> vals;
int dp[maxN];
int mp[maxN];
int c[maxN];
int to[maxN];
bool comp(vector<int> a, vector<int> b){
  return b[b.size()-1]>a[a.size()-1];
}
void solve(){
  int n; cin>>n;
  vals.clear();
  for (int i=0;i<n;i++) a[i].clear();
  int MX=0;
  for (int i=0;i<n;i++){
    int k; cin>>k;
    int my=0;
    to[i]=i;
    for (int j=0;j<k;j++){
      int v; cin>>v;
      if (v>my){
        a[i].pb(v);
        my=v;
      }
      vals.pb(v);
    }
  }
  sort(all(vals));
  int start=1;
  mp[vals[0]]=start;
  for (int i=1;i<vals.size();i++){
      if (vals[i]!=vals[i-1]) mp[vals[i]]=++start;
  }
  for (int i=0;i<n;i++){
      for (int j=0;j<a[i].size();j++){
          a[i][j]=mp[a[i][j]];
          MX=max(MX,a[i][j]);
      }
      c[i]=a[i].back();
  }
  sort(to,to+n,[](int i,int j){return c[i]<c[j];});
  sort(c,c+n);
  int ans=0;
  dp[0]=0;
  int ci=0;
  for (int i=1;i<=MX;i++){
    vector<int> idx;
    for (ci;ci<n && a[to[ci]][a[to[ci]].size()-1]==i;ci++){
        idx.pb(to[ci]);
    }
    dp[i]=dp[i-1];
    for (int id:idx){
      for (int j=a[id].size()-1,cnt=1;~j;j--,cnt++){
        dp[i]=max(dp[i],dp[a[id][j]-1]+cnt);
      }
    }
    ans=max(ans,dp[i]);
  }
  print(ans);
}
void precompute(){
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(15);
    precompute();
	
    int t=1;
    cin>>t;
    int i=1;
    while (t--)
    {
        solve();
        ++i;
    }
}
