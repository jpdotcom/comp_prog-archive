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
#define INF ((ll)1e18)
#define MOD ((ll)998244353)
using namespace std;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=1e6+10;
vector<int> adj[maxN];
ll t[maxN];
int proc[maxN];
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
void dfs(int u){

    if (t[u]!=-1) return;
    proc[u]=1;
    ll upd=1;
    for (int v: adj[u]){
        if (proc[v]){
            t[u]=-2;
            return;
        }
        dfs(v);
        if (t[v]==-2){
            t[u]=-2;
            return;
        }
        upd+=t[v];
        upd%=MOD;
    }
    proc[u]=0;
    t[u]=upd;
    return;
}
void solve(){
    int n,m; cin>>n>>m;
    Prime p(1e6+10);
    p.linearSieve();
    FOR(1e6+10) t[i]=-1,proc[i]=0;
    FOR(m){
        int a,b; cin>>a>>b;
        vector<int> fac2=p.getPrimes(b);
        for (auto x: fac2){
            adj[a].pb(x);
        }
    }
    vector<int> facs=p.getPrimes(n);
    ll ans=0;
    for (int x: facs){
        dfs(x);
        if (t[x]==-2){
            print(-1);
            return;
        }
        ans+=t[x];
        ans%=MOD;
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
    while (t--)
    {
        solve();
    }
}
