#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<int,int> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<int> pq;
#define endl '\n'
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define MOD (int)1e9+7
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
ll modu(ll a,ll b){
    return (b+(a%b)) % b;
}
ll power(ll x, ll y, ll p)
{
    ll res = 1;     
    x = x % p; 
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1) res=modu(res*x,p);
        y = y>>1; 
        x = modu((x*x),p);
    }
    return res;
}
void fileIO(string filename) {
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
const ll maxN=2e5+20;
ll a[maxN];
ll t[2*maxN];
void update(int i,ll val,int n){
    i+=n;
    t[i]=val;
    i/=2;
    for (int j=i;j>=1;j/=2) t[j]=gcd(t[2*j],t[2*j+1]);
}
ll query(ll a,ll b,ll n){
    a+=n,b+=n;
    ll ans=0;
    while (a<=b){
        if (a%2==1) ans=gcd(ans,t[a++]);
        if (b%2==0) ans=gcd(ans,t[b--]);
        a/=2,b/=2;
    }
    return ans;
}
ll gcd(ll a, ll b){
    if (a>b) swap(a,b);
    if (a==0) return b;
    return gcd(b%a,a);
}
void solve(){
    int n;cin>>n;
    ll prev; cin>>prev;
    FOR(n-1){
        ll val;cin>>val;
        a[i]=abs(val-prev);
        prev=val;
        update(i,a[i],n-1);
    }
    ll best=1;
    FOR(n-1){
        ll l=i,r=n-2;
        while (l<=r){
            ll m=l+(r-l)/2;
            if (query(i,m,n-1)>=2){
                best=max(best,m-i+2);
                l=m+1;
            }
            else r=m-1;
        }
    }
    print(best);
}
void precompute(){
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(15);
    precompute();
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }
}
