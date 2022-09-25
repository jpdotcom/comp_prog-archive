#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<long long> vi;
typedef std::pair<int,int> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define endl '\n'
#define print(x) cout<<x<<'\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
#define all(a) (a).begin(), (a).end()
#define MOD ((ll)998244353)
using namespace std;
using namespace __gnu_pbds;
const int maxN=1e6+10;
map<ll,ll> a,b,c,d;
vector<int> ver,hor;
void solve(){
    int n,m,k; 
    cin>>n>>m>>k;
    a.clear(),b.clear(),c.clear(),d.clear(),ver.clear(),hor.clear();
    FOR(n){
        int v; cin>>v; ver.pb(v);
    }
    FOR(m){
        int v; cin>>v; hor.pb(v);
    }
    ll ans=0;
    FOR(k){
        int v1,v2;
        cin>>v1>>v2;
        int c1=*lower_bound(all(ver),v1);
        int c2=*lower_bound(all(hor),v2);
        if (c1!=v1){
            a[c1]++;
            b[1e7*c2+c1]++;
        }
        if (c2!=v2){
            c[c2]++;
            d[1e7*c1+c2]++;
        }
    }
    ll s=k*(k-1)/2;
    for (auto x:b){
        s+=x.S*(x.S-1)/2;
    }
    for (auto x: d){
        s+=x.S*(x.S-1)/2;
    }
    for (auto x:a){
        s-=x.S*(x.S-1)/2;
    }
    for (auto x: c){
        s-=x.S*(x.S-1)/2;
    }
    print(k*(k-1)/2-s);
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(15);
    precompute();
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }
