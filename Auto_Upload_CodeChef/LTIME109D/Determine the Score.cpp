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
const int maxN=2e5+1;
vi adj[maxN];
int dfs(int u, vector<vi>&paths){
    print(u);
    if (adj[u].size()==0){
        paths[u].pb(u);
        return u;
    }
    int put=-1;
    for (int v: adj[u]){
        int orig=dfs(v,paths);
        if (put==-1){
            paths[orig].pb(u);
            put=orig;
        }
    }
    return put;
}
void solve(){
    int a,b;cin>>a>>b;
    print(a/10*b);
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