#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<int, int> pi;
typedef long long ll;
typedef std::priority_queue<int> pq;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define iset tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
const int maxN=1e6+1;
ll a[maxN];
void solve(){
    ll n,m; cin>>n>>m;
    vi dist;
    FOR(m) cin>>a[i];
    sort(a,a+m);
    for (int i=0;i<m-1;i++){
        dist.pb(a[i+1]-a[i]-1);
    }
    dist.pb(n-a[m-1]+a[0]-1);
    sort(dist.begin(),dist.end());
    ll ans=0;
    for (int i=dist.size()-1,t=0;~i;i--){
        int add=dist[i]-2*t;
        if (add==2 || add==1){
            t+=1;
        }
        else if (add>0) t+=2;
        if (add>1) add--;
        ans+=max(0,add);
    }
    print(n-ans);
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    cin>>t;
    while (t--) solve();
}


