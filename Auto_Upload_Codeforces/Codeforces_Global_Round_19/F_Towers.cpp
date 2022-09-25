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
#define MOD ((ll)1e9+7)
using namespace std;
using namespace __gnu_pbds;
const int maxN=2e5+5;
int a[maxN];
vi adj[maxN];
ll ans;
ll dp(int u,int p){
    ll diff;
    vi signals;
    for (int v: adj[u]){
        if (v!=p){
            signals.pb(dp(v,u));
        }
    }
    sort(signals.begin(),signals.end());
    if (signals.size()==0){
        ans+=a[u];
        return a[u];
    }
    if (p!=-1){
        diff=max(0LL,a[u]-signals[signals.size()-1]);
        ans+=diff;
        return signals[signals.size()-1]+diff;
    }
    else{
        diff=max(0LL,a[u]-signals[signals.size()-1]);
        ll diff2=(signals.size()>1 ? max(0LL,a[u]-signals[signals.size()-2]) : a[u]);
        ans+=diff+diff2;
        return ans;
    }
}
void solve(){
    int n; cin>>n;
    ans=0;
    FOR(n) cin>>a[i+1];
    int maxH=0;
    int idx=0;
    FOR(n-1){
        int a,b;cin>>a>>b;
        adj[a].pb(b),adj[b].pb(a);
    }
    FOR(n){
        if (a[i+1]>maxH){
            idx=i+1;
            maxH=a[i+1];
        }
    }
    print(dp(idx,-1));
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
