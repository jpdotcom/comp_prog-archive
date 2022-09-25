#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<long long,long long> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<int> pq;
#define endl '\n'
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define MOD (ll)(998244353)
#define INF ((int)1e9+7)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
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
const int maxN=2e5+1;
vector<vector<int>> adj[maxN];
vector<int> A(maxN,0);
vector<int> B(maxN,0);
vector<int> Ans(maxN,0);
vector<vector<int>> pvals(maxN);
ll ans,s;
Prime primes(maxN+1);
void upd1(vector<int> &curr, int val, int T=1){
    if (T) curr[val]++;
    else curr[val]--;
}
void upd2(vector<int> &curr, int val){
    curr[val]=max(curr[val],B[val]-min(B[val],A[val]));
}
void dfs(int u=1,int p=-1){
    for (auto &t: adj[u]){
        int v=t[0],v1=t[1],v2=t[2];
        if (v!=p){
            vector<int> p1=pvals[v1];
            vector<int> p2=pvals[v2];
            for (auto x:p1){
                upd1(A,x);
            }
            for (auto x: p2){
                upd1(B,x);
            }
            for (auto x: p1){
                upd2(Ans,x);
            }
            for (auto x: p2){
                upd2(Ans,x);
            }
            dfs(v,u);
            for (auto x: p2){
                upd1(B,x,0);
            }
            for (auto x: p1){
                upd1(A,x,0);
            }
        }
    }
}
void dfs2(int u=1,int p=-1,ll aval=1,ll bval=1){
    s+=ans*aval%MOD*primes.binpower(bval,MOD-2,MOD)%MOD;
    s%=MOD;
    for (auto &t: adj[u]){
        int v=t[0],v1=t[1],v2=t[2];
        if (v!=p){
            dfs2(v,u,aval*v1%MOD,bval*v2%MOD);
        }
    }
}
void solve(){
    int n; cin>>n;
    ans=1;
    s=0;
    A=B=Ans=vector<int>(n+1,0);
    FOR(n+1){
        adj[i].clear();
    }
    FOR(n-1){
        int a,b,c,d; cin>>a>>b>>c>>d;
        adj[a].pb(vector<int>{b,d,c});
        adj[b].pb(vector<int>{a,c,d});
    }
    dfs();
    for (int i=1;i<n+1;++i){
        ans*=primes.binpower(i,Ans[i],MOD);
        ans%=MOD;
    }
    dfs2();
    print(s);
}
void precompute(){
    primes.linearSieve();
    for (int i=1;i<maxN;i++){
        pvals[i]=(primes.getPrimes(i));
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }
}

