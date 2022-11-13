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
    priority_queue<int> vals;
    map<int,int> cnt;
    FOR(2*n){
        int v; cin>>v;
        cnt[v]++;
    }
    for (auto x: cnt) vals.push(x.S);
    while (vals.size()>=2){
        int v1=vals.top();
        vals.pop();
        int v2=vals.top();
        vals.pop();
        if (v2==0){
            vals.push(v1);
        }
        else{
            v1--;
            v2--;
            vals.push(v1);
            vals.push(v2);
        }
    }
    if (vals.top()/2>(n+1)/2) print("NO");
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
