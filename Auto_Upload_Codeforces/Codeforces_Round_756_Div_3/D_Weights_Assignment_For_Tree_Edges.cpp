#include <bits/stdc++.h>
#define FOR(b) for (int i=0;i<b;i++)
#define endl '\n';
#define F first
#define S second 
#define mp make_pair
#define print(x) cout<<x<<'\n'
#define pb push_back 
#define MOD (ll)1e9+7
typedef std::vector<int> vi;
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
int dist[maxN];
int w[maxN];
int p[maxN];
int seen[maxN];
int get(int u, int prev_dist){
    if (!seen[p[u]] && p[u]!=u){
        return -1;
    }
    seen[u]=true;
    if (p[u]!=u){
        w[u]=max(1,prev_dist-dist[p[u]]+1);
        dist[u]=dist[p[u]]+w[u];
    }
    else{
        dist[u]=w[u]=0;
    }
    return w[u];
}
void solve(){
    int n; cin>>n;
    FOR(n) cin>>p[i+1];
    FOR(n+1){
        dist[i]=seen[i]=w[i]=0;
    }
    int prev_dist=0;
    bool ok=true;
    FOR(n){
        int next;
        cin>>next;
        if (ok){
        int val=get(next,prev_dist);
        if (val==-1){
            ok=false;
        }
        prev_dist=dist[next];
        }
    }
    if (!ok){
        print(-1);
        return;
    }
    FOR(n) cout<<w[i+1]<<' ';
    cout<<endl;
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }
}
