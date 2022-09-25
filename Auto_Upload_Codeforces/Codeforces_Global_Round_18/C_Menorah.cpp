#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<int,int> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<int> pq;
#define endl '\n'
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define MOD (int)1e9+7
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
inline void hash_combine(std::size_t& seed) { }

template <typename T, typename... Rest>
inline void hash_combine(std::size_t& seed, const T& v, Rest... rest) {
    std::hash<T> hasher;
    seed ^= hasher(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    hash_combine(seed, rest...);
}
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {   
        size_t h=0;
        hash_combine(h,p.F,p.S);
        return h;
    }
};
ll modu(ll a,ll b){
    return (b+(a%b)) % b;
}
ll power(ll x, ll y, ll p)
{
    ll res = 1;     
    x = x % p; 
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1) res=modu(res*x,p);
        y = y>>1; 
        x = modu((x*x),p);
    }
    return res;
}
void fileIO(string filename) {
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
void solve(){
    int n; cin>>n;
    string a,b; cin>>a>>b;
    int same1=0,diff1=0;
    int same0=0,diff0=0;
    FOR(n){
        if (a[i]==b[i] && a[i]=='1') same1++;
        else if (a[i]==b[i] && a[i]=='0') same0++;
        else if (b[i]=='0') diff0++;
        else diff1++;
    }
    int ans=1e9+1;
    ans=min(ans,(diff1==diff0 ? diff1+diff0: ans));
    for (int i=0;i<n;i++){
        if (a[i]=='1'){
            if (b[i]=='0' && same0+1==same1) ans=min(ans,same0+same1+2);
            if (b[i]=='1' && same1-1==same0) ans=min(ans,same1+same0);
        }
    }
    print((ans==1e9+1 ? -1 : ans));
}
void precompute(){
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(15);
    precompute();
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }
}
