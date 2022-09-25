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
#define INF ((ll)1e18+7)
#define MOD ((ll)1e9+7)
using namespace std;
map<ll,int> cnt;
void solve(){
    int n,m; cin>>n>>m;
    cnt.clear();
    vector<ll> vals;
    for (int i=0;i<n;i++){
        ll v=0;
        for (int j=0;j<m;j++){
            ll a; cin>>a;
            v+=a*j;
        }
        vals.pb(v);
        cnt[v]++;
    }
    for (int i=0;i<vals.size();i++){
        if (cnt[vals[i]]==1){
            cout<<(i+1)<<' '<<(vals[i]-vals[(i+1)%n])<<endl;
            return;
        }
    }
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
