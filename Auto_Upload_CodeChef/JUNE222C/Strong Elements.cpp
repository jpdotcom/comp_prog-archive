#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<long long, long long> pi;
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
const int maxN=3e5+5;
int a[maxN];
int gcdr[maxN];
int gcdl[maxN];
int gcd(int a, int b){
    if (a>b) swap(a,b);
    if (a==0) return b;
    return gcd(b%a,a);
}
void solve(){
    int n; cin>>n;
    int g=0;
    FOR(n){
        int val;cin>>val;
        a[i]=val;
        g=gcd(g,val);
    }
    if (g!=1){
        print(n);
        return;
    }
    gcdr[n+1]=gcdl[0]=0;
    for (int i=1;i<=n;i++){
        gcdl[i]=gcd(gcdl[i-1],a[i-1]);
    }
    for (int j=n;j>0;j--){
        gcdr[j]=gcd(gcdr[j+1],a[j-1]);
    }
    int ans=0;
    for (int i=0;i<n;i++){
        ans+=(gcd(gcdl[i],gcdr[i+2])>1);
    }
    print(ans);
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
