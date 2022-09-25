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
#define MOD ((ll)1e9+7)
using namespace std;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=1e6+10;
void solve(){
    int n; cin>>n;
    vector<int> p(n);
    FOR(n) cin>>p[i];
    int idx=0;
    for (int i=0;i<n;i++)
        if (p[i]!=i+1){
            idx=i;
            break;
        }
    int sidx=idx;
    int val=p[idx];
    for (int i=idx;i<n;i++){
        if (p[i]<val){
            sidx=i;
            val=p[i];
        }
    }
    reverse(p.begin()+idx,p.begin()+sidx+1);
    for (int x: p) cout<<x<<' ';
    cout<<endl;
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
