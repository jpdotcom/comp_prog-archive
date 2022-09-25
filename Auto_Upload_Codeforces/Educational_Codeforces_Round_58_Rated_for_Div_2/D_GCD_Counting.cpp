
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<long long> vi;
typedef std::pair<int,int> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define endl '\n'
#define print(x) cout<<x<<'\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18)
#define all(a) (a).begin(), (a).end()
#define MOD ((ll)998244353)
using namespace std;
using namespace __gnu_pbds;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=2e5+10;
namespace hash_tuple {
template <typename TT> struct hash {
    size_t operator()(TT const &tt) const { return std::hash<TT>()(tt); }
};

// from boost (functional/hash):
// see http://www.boost.org/doc/libs/1_35_0/doc/html/hash/combine.html template
template <class T> inline void hash_combine(std::size_t &seed, T const &v) {
    seed ^= hash_tuple::hash<T>()(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

// Recursive template code derived from Matthieu M.
template <class Tuple, size_t Index = std::tuple_size<Tuple>::value - 1>
struct HashValueImpl {
    void operator()(size_t &seed, Tuple const &tuple) const {
        HashValueImpl<Tuple, Index - 1>{}(seed, tuple);
        hash_combine(seed, std::get<Index>(tuple));
    }
};
template <class Tuple> struct HashValueImpl<Tuple, 0> {
    void operator()(size_t &seed, Tuple const &tuple) const {
        hash_combine(seed, std::get<0>(tuple));
    }
};

template <typename... TT> struct hash<std::tuple<TT...>> {
    size_t operator()(std::tuple<TT...> const &tt) const {
        size_t seed = 0;
        HashValueImpl<std::tuple<TT...>>{}(seed, tt);
        return seed;
    }
};
// auxiliary generic functions to create a hash value using a seed
template <typename T> inline void hash_val(std::size_t &seed, const T &val) {
    hash_combine(seed, val);
}

template <typename T, typename... Types>
inline void hash_val(std::size_t &seed, const T &val, const Types &... args) {
    hash_combine(seed, val);
    hash_val(seed, args...);
}

template <typename... Types>
inline std::size_t hash_val(const Types &... args) {
    std::size_t seed = 0;
    hash_val(seed, args...);
    return seed;
}

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const {
        return hash_val(p.first, p.second);
    }
};
}
unordered_map<pair<int,int>,int,hash_tuple::pair_hash> chain;
unordered_map<pair<int,int>,int,hash_tuple::pair_hash> path;
vector<int> adj[maxN];
vector<int> facs[maxN];
int a[maxN];
int p[maxN];
void getp(int u,int v){
    p[u]=v;
    for (int x: adj[u]){
        if (v!=x) getp(x,u);
    }
}
struct Prime{
    vector<int> primes;
    vector<int> composite;
    int sz;
	Prime(int s){
        sz=s;
        composite=vector<int> (sz+1);
	}
	void linearSieve(){
        FOR(sz+1) composite[i]=i;
        //composite[i] ==> smallest prime p that divides i
        for (int i=2;i<=sz;i++){
            if (composite[i]==i) primes.pb(i);
            for (int j=0;j<primes.size() && i*primes[j]<=sz; ++j){
                composite[i*primes[j]]=primes[j];
                if (i%primes[j]==0) break;
            }
        }
	}
    vector<int> getPrimes(int n){
        vector<int> out;
        while (n>1){
            out.pb(composite[n]);
            n/=composite[n];
        }
        return out;
    }
    set<int> uniquePrimes(int n){
        set<int> out;
        while (n>1){
            out.insert(composite[n]);
            n/=composite[n];
        }
        return out;
    }
    int cntPrimes(int n){
        int cnt=0;
        while (n>1){
            cnt++;
            n/=composite[n];
        }
        return cnt;
    }
    u64 binpower(u64 base, u64 e, u64 mod) {
        u64 result = 1;
        base %= mod;
        while (e) {
            if (e & 1)
                result = (u128)result * base % mod;
            base = (u128)base * base % mod;
            e >>= 1;
        }
        return result;
    }
    bool check_composite(u64 n, u64 a, u64 d, int s) {
        u64 x = binpower(a, d, n);
        if (x == 1 || x == n - 1)
            return false;
        for (int r = 1; r < s; r++) {
            x = (u128)x * x % n;
            if (x == n - 1)
                return false;
        }
        return true;
    };

    bool MillerRabin(u64 n){
        if (n < 2)
            return false;
        int r = 0;
        u64 d = n - 1;
        while ((d & 1) == 0) {
            d >>= 1;
            r++;
        }
        for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
            if (n == a)
                return true;
            if (check_composite(n, a, d, r))
                return false;
        }
        return true;
    } 
};

int dfs(int u,int p,int f,int r){
    if (r!=u && chain.find(mp(u,f))!=chain.end()) return 0;
    else if (r==u && path.find(mp(u,f))!=path.end()) return path[mp(u,f)];
    int tot=(a[u]%f==0);
    if (a[u]%f!=0){
        chain[mp(u,f)]=0;
        path[mp(u,f)]=0;
        return 0;
    }
    vector<int> ans(2,0);
    int upd=1;
    for (int v: adj[u]){
        if (v!=p && a[v]%f==0){
            dfs(v,u,f,r);
            int val=chain[mp(v,f)];
            upd=max(val+1,upd);
            vi next={ans[0],ans[1],val};
            sort(all(next));
            ans[0]=next[2],ans[1]=next[1];
        }

    }
    int ro=max(ans[0]+ans[1]+tot,upd);
    chain[mp(u,f)]=upd;
    path[mp(u,f)]=ro;
    return ro;
}
void solve(){
    int n; cin>>n;
    Prime ps(2e5+10);
    ps.linearSieve();
    for (int i=2;i<maxN;i++){
        set<int> vals=ps.uniquePrimes(i);
        for (auto x: vals) facs[i].pb(x);
    }
    FOR(n)
    {
        int v; cin>>v;
        a[i+1]=v;
    }
    FOR(n-1){
        int a,b; cin>>a>>b; adj[a].pb(b),adj[b].pb(a);
    }
    getp(1,-1);
    int ans=0;
    for (int i=1;i<=n;i++){
        for (int x: facs[a[i]]){
            ans=max(ans,dfs(i,p[i],x,i));
        }
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
    while (t--){
        solve();
        
    }
}
