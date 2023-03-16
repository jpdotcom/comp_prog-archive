#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(a) for(int i=0;i<(int)a;i++)
#define mp(a,b) make_pair(a,b)
#define all(a)  a.begin(),a.end()
typedef std::vector<long  long> vi;
typedef std::pair<int,int> pi;
typedef long long ll;
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
ll a[maxN];
ll b[maxN];
pi p1[maxN];
pi p2[maxN];
ll ia[maxN];
ll ib[maxN];
void solve(){
    int n; cin>>n;
    FOR(n) cin>>a[i];
    FOR(n) cin>>b[i];
    FOR(n) ia[a[i]]=i;
    FOR(n) ib[b[i]]=i;
    ib[n+1]=ia[n+1]=n;
    p1[1]={ia[1],ia[1]};
    p2[1]={ib[1],ib[1]};
    for (int i=2;i<=n;i++){
        int idx=ia[i];
        p1[i]={min(p1[i-1].F,idx),max(p1[i-1].S,idx)};
        idx=ib[i];
        p2[i]={min(p2[i-1].F,idx),max(p2[i-1].S,idx)};
    }
    ll ans=0;
    for (int i=2;i<=n+1;i++){
        ll lb=min(p1[i-1].F,p2[i-1].F);
        ll rb=max(p1[i-1].S,p2[i-1].S);
        int av=ia[i];
        int bv=ib[i];
        if ((lb<=av && av<=rb) || (lb<=bv && bv<=rb)) continue;
        int l=-1;
        int r=n+3;
        if (av<lb) l=max(l,av);
        if (bv<lb) l=max(l,bv);
        if (av>rb) r=min(r,av);
        if (bv>rb) r=min(r,bv);
        if (r==n+3) r=n;
        ans+=(lb-l)*(r-rb);
    }
    ll v1=min(ia[1],ib[1]);
    ll v2=max(ib[1],ia[1]);
    print(ans+v1*(v1+1)/2 + (n-1-v2)*(n-v2)/2 + (ll)max(0LL,(v2-v1-1)*(v2-v1)/2));
    
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
    int i=1;
    while (t--)
    {
        solve();
        ++i;
    }
}
