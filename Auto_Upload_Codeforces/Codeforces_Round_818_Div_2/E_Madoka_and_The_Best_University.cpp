#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<long long,long long> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
#define MOD ((ll)1e9+7)
using namespace std;
const int maxN=2e5+10;
using u64 = uint64_t;
using u128 = __uint128_t;
vector<vector<int>> facs(maxN);
struct Prime{
    vector<int> primes;
    vector<int> composite;
    vector<int> tot;
    int sz;
	Prime(int s){
        sz=s;
        composite=vector<int> (sz+1);
        tot=vector<int>(sz+1);
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
    void totient(){
        tot[0]=0;
        tot[1]=1;
        for (int i=2;i<=sz;i++){
            tot[i]=i-1;
        }
        for (int i=2;i<=sz;i++){
            for (int j=2*i;j<=sz;j+=i){
                tot[j]-=tot[i];
            }
        }
        return;
    }
};
ll lcm(ll a, ll b){
    return a*b/(__gcd(a,b));
}
void solve(){
    int n; cin>>n;
    ll ans=0;
    Prime p(2e5+1);
    p.totient();
    for (int i=1;i<=n-2;i++){
        for (auto x: facs[n-i]){
            if (x==n-i) continue;
            ans+=(lcm(i,x)%MOD*p.tot[(n-i)/x]%MOD)%MOD;
            ans%=MOD;
        }
    }
    print(ans);
}
void precompute(){

    for (int i=1;i<maxN;i++){
        facs[i]=vector<int>();
        for (int j=1;j<=(int)sqrt(i);j++){
            int b=i/j;
            if (b*j==i){
                facs[i].pb(j);
                if (b!=j) facs[i].pb(b);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    while (t--) solve();
}
