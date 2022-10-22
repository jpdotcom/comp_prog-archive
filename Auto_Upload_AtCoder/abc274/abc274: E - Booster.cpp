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
#define bit(x,s) ((x>>(s))&1)
using namespace std;
using namespace __gnu_pbds;
using u64 = uint64_t;
using u128 = __uint128_t;
const int S=17;
long double dp[1<<S][S+1];
int need=0;
vector<vector<int>> p;
int get_cnt(int k){
    int ans=0;
    for (int i=0;i<p.size();i++){
        if (bit(k,p.size()-1-i)) ans+=p[i][2];
    }
    return ans;
}
void solve(){
    int n,m; cin>>n>>m;
    for (int i=0;i<n;i++){
        need|=(1<<(i+m));
        int a,b; cin>>a>>b;
        p.pb(vector<int>{a,b,0});
    }
    FOR(m){
        int a,b; cin>>a>>b;
        p.pb(vector<int>{a,b,1});
    }
    for (int i=(1<<(n+m))-1; i>=0; i--){
        for (int j=0;j<=(n+m);j++){
                dp[i][j]=INF;
                long double sx=(j==0 ? 0 : p[j-1][0]);
                long double sy=(j==0 ? 0 : p[j-1][1]);
                int v=get_cnt(i);
                if ((i&need)==need){
                    dp[i][j]=sqrt(sx*sx+sy*sy)/(1<<v);

                }
                for (int b=n+m-1,val=1;~b;val*=2,b--){
                    if (bit(i,n+m-1-b)==0){
                        long double dx=sx-p[b][0],dy=sy-p[b][1];
                        dp[i][j]=min(dp[i][j],sqrt(dx*dx+dy*dy)/(1<<v) + dp[i|val][b+1]);
                    }
                }
            }
        
    }
    long double ans=INF;
    print(dp[0][0]);
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

