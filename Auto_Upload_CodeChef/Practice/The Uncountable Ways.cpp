#include <bits/stdc++.h>
#define FOR(b) for (int i=0;i<b;i++)
#define endl '\n';
#define F first
#define S second 
#define mp make_pair
#define print(x) cout<<x<<'\n'
#define pb push_back 
typedef std::vector<long long> vi;
typedef std::pair<long long, long long> pi;
typedef long long ll;
using namespace std;
ll modu(ll a,ll b){
    return (b+(a%b)) % b;
}
ll power(long long x, ll y, ll p)
{
    if (y==0) return 1;
    ll val=power(x,y/2,p);
    if (y&1) return x*val % p * val % p;
    else return val*val % p;
}
const ll maxN=800001;
const ll mm=1e9+7;
ll fac[maxN];
ll inv[maxN];
ll nCr(ll a,ll b){
  
  return (((fac[a] * inv[b]) % mm) * inv[a-b]) % mm;
}
ll get(ll x1,ll y1,ll x2, ll y2) {
    ll n=x2-x1;
    ll m=y2-y1;
    return nCr(n+m,m);
}
void precompute(){
    fac[0]=1;
    for (ll i=1;i<maxN;i++){
        fac[i]=(fac[i-1]*i) % mm;
    }
    inv[1] = 1;
    inv[0]=1;
    for(ll i = 2; i < maxN; ++i){
        inv[i] = mm - ((mm/i) * inv[(mm%i)] % mm);
    }
    for(ll i=1;i<maxN;i++){
        inv[i]=(inv[i-1]*inv[i])%mm;
    }

}
void solve(){
    ll n,m,a,b;
    cin>>n>>m>>a>>b;
    ll s1=a;
    ll s2=m-b;
    ll prev=0;
    ll ans=0;
    for (ll i=s1;i<=n;i++){
        ll curr=get(0,0, i, s2);
        ans+=modu(modu((curr-prev),mm)*(get(i,s2,n,m)),mm);
        ans=modu(ans,mm);
        prev=curr;
    }
    print(ans);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(25);
    precompute();
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }
}

