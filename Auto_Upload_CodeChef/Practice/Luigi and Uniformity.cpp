#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(a) for(int i=0;i<a;i++)
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
#define MOD ((ll)998244353)
#define int long long
using namespace std;
using u64 = uint64_t;
using u128 = __uint128_t;
void solve(){
    int n; cin>>n;
    int a[n];
    int g=0;
    map<int,int>  cnt;
    for (int i=0;i<n;i++){
        cin>>a[i];
        g=gcd(a[i],g);
        cnt[a[i]]++;
    }
    int ans=n;
    for (auto x: cnt){
        if (g%x.F==0) ans=min(ans,n-x.S);
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
    int i=1;
    cin>>t;
    while (t--)
    {
        solve();
        ++i;
    }
}
