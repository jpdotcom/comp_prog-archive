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
#define INF ((int)1e9)
#define MOD ((ll)998244353)
using namespace std;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=1e6+10;
map<int,int> cnt;
void solve(){
    int n; cin>>n;
    cnt.clear();
    FOR(n){
        int v; cin>>v;
        cnt[v]++;
    }
    int cnt1=0;
    for (auto &it: cnt){
        if (it.S>1){
            print("YES");
            return;
        }
        cnt1+=it.S;
    }
    if (cnt1&1) print("NO");
    else print("YES");
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
