#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<long long, long long> pi;
typedef long long ll;
typedef std::priority_queue<int> pq;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((int)1e9+7)
using namespace std;
using namespace __gnu_pbds;
const int maxN=1e6+1;
ll cnt[maxN];
void solve(){
    int n,m; cin>>n>>m;
    FOR(n+1) cnt[i]=0;
    FOR(m){
        int v;cin>>v;
        cnt[v]++;
    }
    ll l=0, r=2*m+1;
    ll ans=2*m+1;
    while (l<=r){
        ll mid=l+(r-l)/2;
        ll textra=0;
        ll tneed=0;
        for (int j=1;j<=n;j++){
            if (mid<cnt[j]) tneed+=cnt[j]-mid;
            else textra+=max(0LL,(mid-cnt[j])/2);
        }
        if (textra>=tneed){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
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
    cin>>t;
    while (t--){
        solve();
    }
}
