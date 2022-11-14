#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<long long,long long> pi;
#define mp(a,b) make_pair(a,b)
#define all(a) a.begin(),a.end()
typedef long long ll;
typedef std::priority_queue<int> pq;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define MOD (ll)(998244353 )
#define INF ((int)1e9)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>(s))&1)
using namespace std;
using namespace __gnu_pbds;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=2e5+1;
int a[maxN];
void solve(){
    int n,m; cin>>n>>m;
    for (int i=0;i<n;i++) cin>>a[i];
    
    vector<vector<pair<int,int>>> p;
    vector<int> vals;
    vector<pair<int,int>> first;
    int c=a[0];
    for (int i=2;i<=sqrt(a[0]);i++){
        int v=1;
        int cnt=0;
        while (c%i==0){
            c/=i;
            v*=i;
            cnt++;
        }
        if (cnt){
            first.pb({i,cnt});
            vals.pb(v);
        }
    }
    int ok=(true && c!=1);
    for (int i=2;i<=sqrt(c);i++){
        if (c%i==0) ok=false;
    }
    if (ok){
        first.pb({c,1});
        vals.pb(c);
    }
    p.pb(first);
    ok=1;
    for (int i=1;i<n;i++){
        if (a[i-1]%a[i]!=0){
            print(0);
            return;
        }
        for (int j=0;j<first.size();j++){
            while (a[i]%vals[j]){
                vals[j]/=first[j].F;
                first[j].S--;
            }
        }
        p.push_back(first);
    }
    ll ans=1;
    int g=a[0];
    int one_val=-1;
    map<pair<int,int>,int> calc;
    for (int i=1;i<n;i++){
        vector<int> primes;
        if (calc.find({a[i-1],a[i]})!=calc.end()){
            ans*=calc[mp(a[i-1],a[i])];
            ans%=MOD;
        }
        else{
            for (int j=0;j<first.size();j++){
            if (p[i-1][j].S-p[i][j].S) primes.pb(p[i][j].F);
        }
        int mx=m/a[i];
        int curr=mx;
        for (int j=1;j<(1<<primes.size());j++){
            int num=1;
            for (int k=0;k<primes.size();k++){
                if (bit(j,k)) num*=primes[k];
            }
            curr-=(mx/num)*(__builtin_popcount(j) & 1 ? 1: -1);
            curr=((curr%MOD)+MOD)%MOD;
        }
        calc[mp(a[i-1],a[i])]=curr;
        ans*=curr;
        ans%=MOD;
        }
    }
    print(ans);
}
void precompute(){
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cout<<setprecision(15);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    cin>>t;
    int i=0;
    while (t--){
        //cout<<"Case #" << (i+1) << ": ";
        solve();
        ++i;
    }
}

