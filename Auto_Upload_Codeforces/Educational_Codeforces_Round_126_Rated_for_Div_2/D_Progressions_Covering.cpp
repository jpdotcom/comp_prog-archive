#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<long long,long long> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
#define MOD ((ll)1e9+7)
using namespace std;
const int maxN=3e5+1;
int n;
ll a[maxN];
ll cnt[maxN];
void solve(){
   int k;
   cin>>n>>k;
   FOR(n) cin>>a[i];
   ll curr_s=0;
   FOR(n+1) cnt[i]=0;
   ll ans=0;
   for (int i=n-1; ~i;i--){
       cnt[i]+=cnt[i+1];
       curr_s-=cnt[i];
       a[i]=max(0LL,a[i]-curr_s);
       ll d=max(0,i-k+1);
       ll s=i-d+1;
       ll times=ceil(a[i]/(double) s);
       ans+=times;
       curr_s+=times*s;
       if (i-1>=0) cnt[i-1]+=times;
       if (d-2>=0) cnt[d-2]-=times;;
   }
   print(ans);
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(15);
    precompute();
    int t=1;
    while (t--){
        solve();
    }
}
