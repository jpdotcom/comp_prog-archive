#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<long long,long long> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((int)1e9+7)
#define MOD ((ll)1e9+7)
using namespace std;
const int maxN=32769;
int n;
int g[maxN];
void solve(){
    cin>>n;
    FOR(n){
        int v; cin>>v;
        int ans=INF;
        for (int j=v;j<=min(maxN-1,v+15);j++){
            ans=min(ans,15-g[j]+j-v);
        }
        cout<<ans<<' ';
    }
}
void precompute(){
    g[0]=15;
    for (int i=1;i<maxN;i++){
        if (i&1) g[i]=0;
        else g[i]=g[i/2]+1;
    }
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
