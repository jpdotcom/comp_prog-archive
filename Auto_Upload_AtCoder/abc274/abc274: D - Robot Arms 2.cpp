#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<long long,long long> pi;
#define mp(a,b) make_pair(a,b)
#define all(a) a.begin(),a.end()
typedef long long ll;
typedef std::priority_queue<int> pq;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define MOD (ll)(998244353)
#define INF ((ll)1e18)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=1e6;
vector<int> v1;
vector<int> v2;
int dp(vector<int> a, int n, int val){
    vector<vector<int>> can(n+1,vector<int>(2e4+2,0));
    can[0][1e4+1]=1;
    for (int i=1;i<n+1;i++){
        for (int j=0;j<2e4+2;j++){
        int v=a[i-1];
        int shift=1e4+1;
        if (j-v>=0 && (j-v < 2e4+2)) can[i][j]|=can[i-1][j-v];
        if (j+v>= 0 && j+v < 2e4+2) can[i][j]|=can[i-1][j+v];
        }

    }
    return can[n][val+1e4+1];
}
void solve(){
    int n,x,y; cin>>n>>x>>y;
    int sz1=0;
    int sz2=0;
    for (int i=0;i<n;i++){
        int v; cin>>v;
        if (i&1){
            sz2++;
            v2.pb(v);
        }
        else{
            if (i){
            sz1++;
            v1.pb(v);
            }
            else x-=v;
        }
    }
    int ok1=dp(v1,sz1,x);
    int ok2=dp(v2,sz2,y);
    if (ok1 && ok2) print("Yes");
    else print("No");
}
void precompute(){
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cout<<setprecision(15);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    int i=0;
    while (t--){
        //cout<<"Case #" << (i+1) << ": ";
        solve();
        ++i;
    }
}

