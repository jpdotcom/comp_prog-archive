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
//#define endl '\n'
#define bit(x,s) ((x>>(s))&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((int)1e9+10)
#define MOD ((ll)998244353)
using namespace std;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=2e5+1;
int n; 
vector<ll> t1(2*(maxN+1),0);
vector<ll> t2(2*(maxN+1),0);
ll query(int sz,int a,int b, vector<ll> &t){
    a+=sz,b+=sz;
    ll ans=0;
    while (a<=b){
        if (a&1) ans+=t[a++];
        ans%=MOD;
        if ((b&1)==0) ans+=t[b--];
        ans%=MOD;
        a>>=1,b>>=1;
    }
    return ans;
}
void upd(int sz, int i, ll a, vector<ll> &t){
    i+=sz;
    t[i]=a;
    i>>=1;
    while (i>0){
        t[i]=t[2*i]+t[2*i+1];
        t[i]%=MOD;
        i>>=1;
    }
    return;
}
ll pow(ll a,ll b){
    if (b==0) return 1;
    ll v=pow(a,b/2);
    if (b&1) return v*v%MOD*a%MOD;
    return v*v%MOD;
}
ll inv(ll a){
    return pow(a,MOD-2);
}
void solve(){
    cin>>n;
    vector<int> arr(2e5+1,0);
    ll s=0;
    for (int i=0;i<n;i++){
        int a; cin>>a;
        s+=2*query(maxN,a+1,maxN-1,t1)%MOD;
        s%=MOD;
        s+=2*a*query(maxN,0,a,t2)%MOD+a%MOD;
        s%=MOD;
        arr[a]++;
        upd(maxN,a,(ll)(arr[a])*a%MOD,t1);
        upd(maxN,a,arr[a],t2);
        print(s*inv((ll)(i+1)*(i+1)%MOD)%MOD);
    }
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
    int i=1;
    while (t--)
    {
        solve();
        ++i;
    }
}
