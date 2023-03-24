#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(a) for(int i=0;i<(int)a;i++)
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
using namespace std;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=1e6+1;
int cnt[maxN];
ll dp[5050][5050];
ll fac[maxN];
ll inv[maxN];
bool isPrime(int v){
    if (v==1) return false;
    for (int i=2;i<=(int)sqrt(v);i++){
        if (v%i==0) return false;
    }
    return true;
}
void solve(){
    int n; cin>>n;
    vector<int> prime;
    vector<int> comp;
    int needed=n;
    FOR(2*n){
        int v; cin>>v;
        if (isPrime(v)){
            prime.pb(v);
        }
        else{
            needed--;
            comp.pb(v);
        }
        cnt[v]++;
    }
    if (prime.size()<n){
        print(0);
        return;
    }
    sort(all(prime));
    sort(all(comp));
    vector<int> t1,t2;
    if (prime.size()) t1.pb(prime[0]);
    if (comp.size()) t2.pb(comp[0]);
    for (int i=1;i<comp.size();i++){
        if (comp[i]!=comp[i-1]) t2.pb(comp[i]);
    }
    for (int i=1;i<prime.size();i++){
        if (prime[i]!=prime[i-1]) t1.pb(prime[i]);
    }
    prime=t1,comp=t2;
    ll C=fac[n];
    for (int co: comp){
        C*=inv[cnt[co]];
        C%=MOD;
    }
    for (int i=1;i<=n;i++) dp[0][i]=0;
    dp[0][0]=1;
    int i=1;
    for (int i=1;i<=prime.size();i++){
        for (int j=0;j<=n;j++){
            int c=prime[i-1];
            dp[i][j]=0;
            dp[i][j]=(j>=cnt[c]? (inv[cnt[c]]*dp[i-1][j-cnt[c]])%MOD : 0) + (j>=cnt[c]-1 ? (inv[cnt[c]-1])%MOD*dp[i-1][j-cnt[c]+1] : 0);
            dp[i][j]=(dp[i][j]%MOD);
        }
    }
    print((C*dp[prime.size()][needed])%MOD);
}
ll binpow(ll b, ll e){
	ll res = 1;
	while(e > 0){
		if(e % 2 == 1){
			res = res * b % MOD;
		}
		b = b * b % MOD;
		e /= 2;
	}
	return res;
}void precompute(){
    fac[0]=1;
    for (int i=1;i<6060;i++) fac[i]=(i*fac[i-1])%MOD;
    for (int i=0;i<6060;i++) inv[i]=binpow(fac[i],MOD-2);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(15);
    precompute();
    int t=1;
    int i=1;
    while (t--)
    {
        solve();
        ++i;
    }
}
