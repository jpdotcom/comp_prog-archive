#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<long long> vi;
typedef long long ll;
typedef std::pair<int,int> pi;
#define F first 
#define S second 
#define PI 3.14159265358979323846
//#define endl '\n'
#define print(x) cout<<x<<'\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18)
#define all(a) (a).begin(), (a).end()
#define MOD ((ll)1e9+7)

using namespace std::chrono;
using namespace std;
using namespace __gnu_pbds;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=4e5+1;
vector<int> a,b;
void find_equal(){
    map<int,int > fa,fb;
    for (auto x: a) fa[x]++;
    for (auto x: b) fb[x]++;

    vector<int> ka,kb;
    for (auto &it: fa){
        int v=min(it.S,fb[it.F]);
        it.S-=v;
        fb[it.F]-=v;
    }
    for (auto &it: fa){
        FOR(it.S){
            ka.pb(it.F);
        }
    }
    for (auto &it: fb){
        FOR(it.S){
            kb.pb(it.F);
        }
    }
    a=ka,b=kb;
}
int p10(int val){
    int ans=0;
    while (val){
        val/=10;
        ans++;
    }
    return ans;
}
void solve()
{
    int n; cin>>n;
    a.clear(),b.clear();
    FOR(n){
         int v; cin>>v; a.pb(v);
    }
    FOR(n){
        int v; cin>>v; b.pb(v);
    }
    find_equal();
    int ans=0;
    for (int i=0;i<a.size();i++){
        if (a[i]>10){
            a[i]=p10(a[i]);
            ans++;
        }
        if (b[i]>10){
            b[i]=p10(b[i]);
            ans++;
        }
    }
    find_equal();
    for (int i=0;i<a.size();i++){
        if (a[i]>=10){
            a[i]=p10(a[i]);
            ans++;
        }
        if (b[i]>=10){
            b[i]=p10(b[i]);
            ans++;
        }
    }
    find_equal();
    print(ans+a.size()+b.size()-count(all(a),1)-count(all(b),1));
    
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
    while (t--){
        solve();
    }
}
