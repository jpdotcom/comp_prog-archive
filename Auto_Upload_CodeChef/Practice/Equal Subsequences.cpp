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
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
const ll maxN=4e5+100;

void clear(ll t[], ll n){
    for (ll i=0;i<=n;i++){
        t[i]=0;
    }
}
void update(ll v, ll i, ll t[], ll n){
    i+=n;
    t[i]=v;
    i>>=1;
    while (i!=0){
        t[i]=t[2*i]+t[2*i+1];
        t[i]%=MOD;
        i>>=1;
    }
}
ll query(ll a, ll b, ll t[], ll n){
    a+=n;
    b+=n;
    ll ans=0;
    while (a<=b){
        if (a&1){
            ans+=t[a++];
            ans%=MOD;
        }
        if ((b&1)==0){
            ans+=t[b--];
            ans%=MOD;
        }
        a/=2,b/=2;
    }
    return ans;
}
pi idx[maxN];
ll dp[maxN];
ll a[maxN];
void solve(){

    ll n; cin>>n;
    ll t1[4*n+10];
    ll t2[4*n+10];
    FOR(n+1) idx[i].F=idx[i].S=-1;
    FOR(2*n){
        ll v; cin>>v;
        a[i]=v;
        if (idx[v].F!=-1) idx[v].S=i;
        else idx[v].F=i;
    }
    clear(t1,4*n+10);
    clear(t2,4*n+10);
    ll ans=0;
    for (int i=0;i<2*n;i++){
        ll i2=idx[a[i]].F;
        dp[i]=0;
        if (i!=i2){
            dp[i]=((2*query(0,i2-1,t2,2*n)%MOD + query(i2+1,i-1,t2,2*n))%MOD-query(i2+1,i-1,t1,2*n)+1)%MOD;
            update(dp[i],i2,t1,2*n);
            update(dp[i],i,t2,2*n);
        }
    }
    FOR(2*n){
        ans+=(2*dp[i])%MOD;
        ans%=MOD;
    }
    if (ans<0) ans+=MOD;
    print(ans);
}
void precompute(){
}
int main(){
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


