#include <bits/stdc++.h>
#define FOR(b) for (int i=0;i<b;i++)
#define endl '\n';
#define F first
#define S second 
#define mp make_pair
#define print(x) cout<<x<<'\n'
#define pb push_back 
#define MOD (ll)1e9+7
typedef std::vector<long long> vi;
typedef std::pair<long long, long long> pi;
typedef long long ll;
using namespace std;
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
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; 
        x = (x*x) % p;
    }
    return res;
}
ll gcd(ll a,ll b){
    if (a>b) swap(a,b);
    if (a==0) return b;
    return gcd(b%a,a);
}
ll lcm(ll a,ll b){
    return (ll) a * (ll) b / gcd(a,b);
}

void solve(){
    ll b,q,y,c,r,z;
    cin>>b>>q>>y>>c>>r>>z;
    if (c<b || r%q!=0 || c+r*(z-1) > b+q*(y-1) || (c-b)/(double)q != (int)((c-b)/q)){
        print(0);
        return;
    }
    ll ans=0;
    for (ll i=1;i<=(ll)sqrt(r);i++){
        ll j=r/i;
        if (j*i==r && (lcm(i,q)==r || lcm(j,q)==r)){
            if (c-r<b){
                print(-1);
                return;
            }
            if (c+r*(z) > b+q*(y-1)){
                print(-1);
                return;
            }
            if (lcm(i,q)==r) ans+=modu(r*r/(i*i),MOD);
            ans=modu(ans,MOD);
            if (i!=j && lcm(j,q)==r) ans+=modu(r*r/(j*j),MOD);
            ans=modu(ans,MOD);
        }
    }
    print(ans);

}
void precompute(){
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
