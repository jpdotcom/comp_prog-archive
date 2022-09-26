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
const int maxN=1e5+5;
vi cycle;
vi adj[maxN];
bool seen[maxN];
int dfs(int u,int c){
    if (seen[u]) return c;
    c++;
    seen[u]=true;
    return dfs(adj[u][0],c);
}
bool comp(int a,int b){
    return b%2<=a%2;
}
void solve(){
    int n;
    cin>>n;
    FOR(n+1){
        adj[i].clear();
        seen[i]=false;
    }
    pi arr[n];
    FOR(n) cin>>arr[i].F;
    FOR(n){
        cin>>arr[i].S;
        adj[arr[i].F].pb(arr[i].S);
    }
    int c=0;
    for (int i=1;i<n;i++){
        c+=dfs(i,0)/2;
    }
    ll ans=0;
    int val=n;
    FOR(c){
        ans+=2*(val--);
    }
    ans-=(ll) c * (ll) (c+1);
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
