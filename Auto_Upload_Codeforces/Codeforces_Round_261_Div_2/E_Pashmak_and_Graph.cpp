#include <bits/stdc++.h>
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
# define PI 3.14159265358979323846
# define print(x) cout<<x<<'\n'
using namespace std;
ll modu(ll a,ll b){
    return (b+(a%b)) % b;
}
ll power(ll x, ll y, ll p)
{
    long long res = 1;     
    x = x % p; 
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; 
        x = (x*x) % p;
    }
    return res;
}
const int maxN=3*10e5+5;
int dp[maxN];
vector<vi>adj;
void solve(){
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        vi p;
        p.pb(w),p.pb(a),p.pb(b);
        adj.pb(p);
    }
    sort(adj.begin(),adj.end());
    int a=0,prev_val=0;
    vector<pi>upd;
    FOR(maxN) dp[i]=0;
    for (int i=0;i<adj.size();i++){
        if (adj[i][0]!=prev_val){
            while (upd.size()){
                pi p=upd.back();
                upd.pop_back();
                dp[p.F]=max(dp[p.F],p.S);
            }
            prev_val=adj[i][0];
        }
        int a=adj[i][1],b=adj[i][2];
        upd.pb(make_pair(b,dp[a]+1));
    }
    while (upd.size()){
        pi p=upd.back();
        upd.pop_back();
        dp[p.F]=max(dp[p.F],p.S);
    }
    FOR(maxN) a=max(a,dp[i]);
    print(a);
    return;
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    precompute();
    int t=1;
    while (t--){
        solve();
    }
}
