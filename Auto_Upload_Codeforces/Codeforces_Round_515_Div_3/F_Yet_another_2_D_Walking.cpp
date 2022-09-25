#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<long long> vi;
typedef std::pair<long long,long long> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
#define MOD ((ll)1e9+7)
using namespace std;
const int maxN=2e5+1;
map<int,vector<pi>> lvl;
ll dp[maxN][2];
ll dist(pi a, pi b){
    return abs(a.F-b.F)+abs(a.S-b.S);
}
bool comp (pi a, pi b){
    return (b.F<a.F || (b.F==a.F && b.S>a.S));
}
void solve(){
    int n; cin>>n;
    FOR(n){
        int a,b; cin>>a>>b;
        lvl[max(a,b)].pb(mp(a,b));
    }
    vector<pair<int,vector<pi>>> vals;
    for (auto &it : lvl){
        sort(it.S.begin(),it.S.end(),comp);
        vals.pb(mp(it.F,it.S));
    }
    vector<pi> zero={mp(0,0)};
    vals.pb(mp(0,zero));
    sort(vals.begin(),vals.end());
    dp[0][0]=0;
    dp[0][1]=0;
    for (int i=1;i<vals.size();i++){
        for (int j=0;j<2;j++){
            int k=(j==0 ? 0 : vals[i].S.size()-1);
            int l=(j==0 ? vals[i].S.size()-1 : 0);
            ll d=dist(vals[i].S[k],vals[i].S[l]);
            dp[i][j]=INF;
            dp[i][j]=d+min(dist(vals[i].S[l],vals[i-1].S[0])+dp[i-1][0],dist(vals[i].S[l],vals[i-1].S[vals[i-1].S.size()-1])+dp[i-1][1]);
        }
    }
    print(min(dp[vals.size()-1][0],dp[vals.size()-1][1]));
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
    while (t--){
        solve();
    }
}
