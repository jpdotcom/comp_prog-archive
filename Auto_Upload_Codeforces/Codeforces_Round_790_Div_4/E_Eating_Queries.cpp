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
ll prefix[maxN];
ll arr[maxN];
ll get_ans(int x,int n){
    int l=0;
    int r=n;
    ll best=-1;
    while (l<=r){
        int m=l+(r-l)/2;
        if (prefix[n]-prefix[m]>=x){
            l=m+1;
            best=n-m;
        }
        else{
            r=m-1;
        }
    }
    return best;
}
void solve(){
    int n,q;
    cin>>n>>q;
    FOR(n){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    prefix[0]=0;
    FOR(n) prefix[i+1]=arr[i]+prefix[i];
    FOR(q){
        int x; cin>>x;
        print(get_ans(x,n));
    }
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
