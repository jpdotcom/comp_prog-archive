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
#define iset tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
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
const int maxN=1e6+5;
ll fac[maxN];
ll inv[maxN];
int nCr(ll a, ll b){
    return modu(modu(fac[a]*inv[b],MOD)*inv[a-b],MOD);
}
void solve(){
    int n,l,r;
    cin>>n>>l>>r;
    for (int i=l+n;i<=r+n;i++){
        if (i&1) cout<<0<<' ';
        else{
            cout<<nCr(n,i/2)<<' ';
        }
    }
    cout<<endl;
}
int get_inv(int a){
    return power(a,MOD-2,MOD);
}
void precompute(){
    fac[0]=1;
    inv[0]=get_inv(1);
    for (int i=1;i<maxN;i++){
        fac[i]=modu(fac[i-1]*i,MOD);
        inv[i]=get_inv(fac[i]);
    }
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
