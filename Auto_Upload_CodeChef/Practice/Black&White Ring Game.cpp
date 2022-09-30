#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<long long> vi;
typedef long long ll;
typedef std::pair<ll,ll> pi;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define endl '\n'
#define print(x) cout<<x<<'\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+10)
#define all(a) (a).begin(), (a).end()
#define insert push
#define MOD ((ll)1e9+7)
using namespace std;
using namespace __gnu_pbds;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=2e5+1;
int win[maxN];
int a[maxN];
void solve(){
    int n; cin>>n;
    FOR(n) cin>>a[i];
    int tot=0,alter=0;
    vector<int> cnt(2,0);
    FOR(n){
        cnt[a[i]]++;
        alter+=(a[i]!=a[(i+1)%n]);
    }
    tot=2*min(cnt[0],cnt[1]);
    if (win[tot-alter]) print("Alice");
    else print("Bob");
}
void precompute(){
    win[0]=win[1]=0;
    for (int i=2;i<maxN;i++) win[i]=((win[i-2]^1));
}
int32_t main(){
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
