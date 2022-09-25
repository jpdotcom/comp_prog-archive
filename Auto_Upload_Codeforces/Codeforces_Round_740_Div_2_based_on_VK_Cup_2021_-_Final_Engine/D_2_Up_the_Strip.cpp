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
#define endl '\n'
#define print(x) cout<<x<<'\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e9+1)
#define all(a) (a).begin(), (a).end()
#define MOD ((ll)1e9+7)

using namespace std::chrono;
using namespace std;
using namespace __gnu_pbds;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=4e6+5;
ll dp[maxN];
ll curr[maxN];
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

};
void solve(){
    int n,m; cin>>n>>m;
    Prime p(n+10);
    p.linearSieve();
    FOR(n+1) dp[i]=curr[i]=0;
    dp[1]=1;
    ll s=1;
    ll fs=0;
    for (int i=2;i<=n;i++){
        dp[i]+=s;
        dp[i]%=m;
        vector<int> facs=p.factorize(i);
        for (int x: facs){
            if (x==1) continue;
            fs-=curr[x];
            fs=(fs+m)%m;
            curr[x]=dp[i/x];
            fs+=curr[x];
            fs%=m;
        }
        
        dp[i]+=fs;
        dp[i]%=m;
        s+=dp[i];
        s%=m;
    }
    print(dp[n]);
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
