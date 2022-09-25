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
#define INF ((ll)1e18+7)
#define MOD ((ll)998244353)
using namespace std;
using namespace __gnu_pbds;
const int maxN=2e5+10;
ll fac[maxN];
ll a[maxN];
pair<ll,ll> t[2*maxN];
int NN=2e5+1;
ll inv[maxN];
int cnt[maxN];
ll b[maxN];
ll binpow(ll a, ll b){
    if (b==0) return 1;
    ll val=binpow(a,b/2);
    val*=val;
    val%=MOD;
    if (b&1) return val*a%MOD;
    return val;
}
void update(int i, ll val){
    for (i+=NN,t[i].F=fac[val],t[i].S=val,i>>=1;i>=1;i>>=1){
        t[i].F=t[i<<1].F*t[(i<<1)|1].F;
        t[i].F%=MOD;
        t[i].S=t[i<<1].S+t[(i<<1)|1].S;
        t[i].S%=MOD;
    }
}
ll q1(int l, int r){
    ll ans=1;
    for (l+=NN,r+=NN;l<=r;l>>=1,r>>=1){
        if (l&1) {
            ans*=t[l++].F;
            ans%=MOD;
        }
        if ((r&1)==0){
            ans*=t[r--].F;
            ans%=MOD;
        }
    }
    return ans;
}
ll q2(int l, int r){
    ll ans=0;
    for (l+=NN,r+=NN;l<=r;l>>=1,r>>=1){
        if (l&1) {
            ans+=t[l++].S;
            ans%=MOD;
        }
        if ((r&1)==0){
            ans+=t[r--].S;
            ans%=MOD;
        }
    }
    return ans;
}
ll ginv(ll a){
    return binpow(a,MOD-2);
}
void solve(){
    int n,m; cin>>n>>m;
    ll mx=0;
    fill(cnt,cnt+NN+1,0);
    FOR(n){
        ll v; cin>>v;
        a[i]=v;
        cnt[v]++;
        mx=max(mx,v);
    }
    FOR(NN){
        update(i,cnt[i]);
    }
    FOR(m) cin>>b[i];
    ll ans=0;
    for (int i=0;i<min(n,m);i++){
        if (b[i]!=1){
            ll v1=q1(1,mx);
            ll v2=q2(1,b[i]-1);
            ll v3=q2(1,mx);
            ans+=fac[v3-1]*ginv(v1)%MOD*v2%MOD;
            ans%=MOD;

        }
        if (cnt[b[i]]>0){
            cnt[b[i]]--;
            update(b[i],cnt[b[i]]);
        }
        else{
            break;
        }
    }
    FOR(NN) cnt[i]=0;
    FOR(n) cnt[a[i]]++;
    if (n<m){
        bool ok=true;
        FOR(n){
            ok&=(cnt[b[i]]>0);
            cnt[b[i]]--;
        }
        print((ans+ok)%MOD);
    }
    else print(ans);
}
void precompute(){
    fac[0]=1;
    for (int i=1;i<maxN;i++)
        fac[i]=fac[i-1]*i%MOD;
}
int main(){
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
