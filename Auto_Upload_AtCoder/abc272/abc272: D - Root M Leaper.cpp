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
#define INF ((int)1e9+7)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=405;
int dist[maxN][maxN];
int n,m;
int valid(int val){
    return 1<=val && val<=n;
}
void solve(){
    cin>>n>>m;
    FOR(n+1){
        for (int j=0;j<n+1;j++)
        {
            dist[i][j]=INF;
        }
    }
    vector<vector<int>> next;
    for (int i=-1*n;i<n+1;i++){
        for (int j=-1*n;j<n+1;j++){
            if (i*i+j*j==m){
                next.pb(vector<int>{i,j});
            }
        }
    }
    queue<pi> q;
    q.push(mp(1,1));
    dist[1][1]=0;
    while (q.size()){
        pi u=q.front();
        q.pop();
        for (auto x: next){
            if (valid(u.F+x[0]) && valid(u.S+x[1]) && dist[u.F+x[0]][u.S+x[1]]>dist[u.F][u.S]+1){
                q.push(mp(u.F+x[0],u.S+x[1]));
                dist[u.F+x[0]][u.S+x[1]]=dist[u.F][u.S]+1;
            }
        }
    }
    for (int i=1;i<n+1;i++){
        for (int j=1;j<n+1;j++){
            cout<<(dist[i][j]==INF ? -1 : dist[i][j])<<' ';
        }
        cout<<endl;
    }
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
    while (t--){
        solve();
    }
}

