#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
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
#define INF ((int)1e9+10)
#define MOD ((ll)1e9+7)
using namespace std;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=1e6+10;
int a[maxN];
void solve(){
    int n; cin>>n;

    FOR(n) cin>>a[i];
    int me=(a[n-1]&1 ? INF : a[n-1]),mo=(a[n-1] & 1 ? a[n-1] : INF);
    bool ok=true;
    for (int i=n-2;~i;i--){
        if (a[i]&1){
            if (mo < a[i]) ok=false;
            mo=min(a[i],mo);
        }
        else{
            if (me < a[i]) ok=false;
            me=min(a[i],me);
        }
    }
    if (ok) print("yes");
    else print("no");

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
