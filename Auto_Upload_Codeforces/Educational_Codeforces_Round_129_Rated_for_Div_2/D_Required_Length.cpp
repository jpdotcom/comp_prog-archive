#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<int,int> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<pi> pq;
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
map<ll,ll> seen;
ll n;
ll dfs(ll u){
    if (seen.find(u)!=seen.end()) return seen[u];
    ll p=u;
    ll l=0;
    ll ans=1e18+1;
    if (to_string(u).size()==n){
        seen[u]=0;
        return seen[u];
    }
    while (p!=0){
        l++;
        ll d=p%10;
        p/=10;
        if (d!=1){
            ans=min(ans,1+dfs(u*d));
        }
    }
    seen[u]=ans;
    return seen[u];
}
void solve(){
    ll x;
    cin>>n>>x;
    ll ans=dfs(x);
    if (ans==1e18) print(-1);
    else print(ans);
}
void precompute(){
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(15);
    precompute();
    int t=1;
    while (t--){
        solve();
    }
}
