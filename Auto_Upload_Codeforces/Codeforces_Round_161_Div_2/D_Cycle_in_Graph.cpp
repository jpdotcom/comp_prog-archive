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
int power(long long x, unsigned int y, ll p)
{
    unsigned long long res = 1;     // Initialize result
 
    x = x % p; // Update x if it is more than or
                // equal to p
 
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
void precompute(){
}
const int maxN=1e5+5;
vi adj[maxN];
int arr[maxN];
int occ[maxN];
bool seen[maxN];
int dfs(int u,int idx){
    occ[u]=idx;
    seen[u]=true;
    arr[idx]=u;
    for (int v:adj[u]){
        if (!seen[v]){
            return dfs(v,idx+1);
        }
    }
    return u;
}
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    FOR(m){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b),adj[b].pb(a);
    }
    int u=dfs(1,0);
    int si=n;
    for (int v:adj[u]){
        si=min(si,occ[v]);
    }
    vi out;
    for (int i=si;i<maxN;i++){
        if (arr[i]==0) break;
        else out.pb(arr[i]);
    }
    print(out.size());
    for (int x:out) cout<<x<<' ';
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

