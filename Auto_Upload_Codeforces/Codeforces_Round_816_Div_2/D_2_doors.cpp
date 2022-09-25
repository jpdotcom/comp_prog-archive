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
#define INF ((int)1e9+10)
#define all(a) (a).begin(), (a).end()
#define MOD ((ll)998244353)
using namespace std;
using namespace __gnu_pbds;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=1e6+1;
vector<int>adj[maxN];
int a[maxN];
map<pair<int,int>,int> val;
void solve(){
    int n,q; cin>>n>>q;
    for (int i=0;i<n;i++) a[i]=(1<<30)-1;
    FOR(q){
        int v1,v2,x; cin>>v1>>v2>>x; v1--,v2--;
        for (int j=0;j<30;j++){
            if (bit(x,j)==0){
                if (bit(a[v1],j)) a[v1]-=(1<<j);
                if (bit(a[v2],j)) a[v2]-=(1<<j);
            }
        }
        adj[v1].pb(v2);
        adj[v2].pb(v1);
        val[make_pair(v1,v2)]=x;
        val[make_pair(v2,v1)]=x;
    }
    for (int i=0;i<n;i++){
        for (int j=29;~j;j--){
            if (bit(a[i],j)){
                bool can=true;
                for (int x: adj[i]){
                    if (x==i) can=false;
                    int v=val[mp(i,x)];
                    if (bit(v,j)==1 && bit(a[x],j)==0) can=false;
                }
                if (can) a[i]-=(1<<j);
            }
        }
    }
    FOR(n) cout<<a[i]<<' ';
    cout<<endl;
}
void precompute(){
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(15);
    precompute();
    int t=1;
    while (t--){
        solve();
        
    }
}
