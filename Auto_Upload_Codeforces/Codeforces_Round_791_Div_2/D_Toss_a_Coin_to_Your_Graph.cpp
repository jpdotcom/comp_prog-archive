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
const int maxN=2e5+5;
pi edges[maxN];
vi adj[maxN];
bool seen[maxN];
bool c[maxN];
ll ans[maxN];
ll vals[maxN];
bool dfs(int u,ll k){
    if (c[u]){
        ans[u]=k;
        return true;
    }
    if (seen[u]) return ans[u]>=k;
    seen[u]=c[u]=true;
    ans[u]=1;
    for (int v:adj[u]){
        dfs(v,k);
        ans[u]=max(ans[u],1+ans[v]);
    }
    c[u]=false;
    return ans[u]>=k;
}
void solve(){
    ll n,mo,k;
    cin>>n>>mo>>k;
    FOR(n) cin>>vals[i+1];
    FOR(mo){
        cin>>edges[i].F>>edges[i].S;
    }
    int l=0,r=1e9+1;
    int a=-1;
    while (l<=r){
        int m=l+(r-l)/2;
        for (int i=1;i<=n;i++){
            c[i]=ans[i]=seen[i]=0;
            adj[i].clear();
        }

        FOR(mo){
            if (vals[edges[i].F]<=m && vals[edges[i].S]<=m){
                adj[edges[i].F].pb(edges[i].S);
            }
        }
        bool ok=false;
        for (int i=1;i<=n;i++){
            if (vals[i]<=m) ok|=dfs(i,k);
        }
        if (ok){
            a=m;
            r=m-1;
        }
        else l=m+1;
    }
    print(a);
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(25);
    precompute();
    int t=1;
    while (t--){
        solve();
    }
}
