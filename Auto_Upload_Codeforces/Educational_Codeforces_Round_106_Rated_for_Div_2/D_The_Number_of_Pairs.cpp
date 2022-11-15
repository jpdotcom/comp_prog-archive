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
    void __factorize(vector<pair<int,int>> &cnt,int idx,vector<int> &vals,int cval=1){
        if (idx==-1){
            vals.pb(cval);
            return;
        }
        __factorize(cnt,idx-1,vals,cval);
        int ccval=cval;
        for (int i=0;i<cnt[idx].S;i++){
            ccval*=cnt[idx].F;
            __factorize(cnt,idx-1,vals,ccval);
        }
    }
    vector<int> factorize(int n){
        vector<int> pf=getPrimes(n);
        sort(pf.begin(),pf.end());
        vector<pair<int,int>> cnt;
        pi c=mp(pf[0],1);
        for (int i=1;i<pf.size();i++){
            if (pf[i]!=pf[i-1]){
                cnt.pb(c);
                c=mp(pf[i],1);
            }
            else c.S++;
        }
        cnt.pb(c);
        vector<int> vals;
        __factorize(cnt,cnt.size()-1,vals);
        return vals;
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
    vector<vector<int>> factorizeTo(int n){
        vector<vector<int>> out(n+1);
        for (int i=1;i<=n;++i){
            for (int j=i;j<=n;j+=i){
                out[j].pb(i);
            }
        }
        return out;
    }
};
const int maxN=2e7+6;
Prime p(maxN);
ll cnt[maxN];
void solve(){
    int c,d,x;
    cin>>c>>d>>x;
    // c*ABg-d*g=x
    // g*(cAB-d)=x
    // cAB-d=v
    // AB=(v+d)/c
    ll ans=0;
    for (int i=1;i<=sqrt(x);i++){
        if (x%i==0){
            int f1=i;
            int f2=x/i;
            if ((f1+d)%c==0) ans+=cnt[(f1+d)/c];
            if (f2!=f1 && (f2+d)%c==0) ans+=cnt[(f2+d)/c];
        }
    }
    print(ans);
}
void precompute(){
    p.linearSieve();
    FOR(maxN) cnt[i]=1;
    for (int i=2;i<maxN;i++){
        if (p.composite[i]==i){
            for (int j=i;j<maxN;j+=i){
                cnt[j]*=2;
            }
        }
    }
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
