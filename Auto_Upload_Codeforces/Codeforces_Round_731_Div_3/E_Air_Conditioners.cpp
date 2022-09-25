#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<long long> vi;
typedef std::pair<int,int> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<int> pq;
#define endl '\n'
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define MOD (int)(1e9+7)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
const int maxN=3e5+1;
int ans[maxN];
int t[maxN];
int a[maxN];
void solve(){
    priority_queue<pi> q;
    int n,k; cin>>n>>k;
    FOR(n) ans[i]=-1;
    FOR(k) cin>>a[i];
    FOR(k) cin>>t[i];
    FOR(k){
        q.push(make_pair(-1*t[i],a[i]-1));
    }
    while (q.size()){
        pi v=q.top();
        v.F*=-1;
        q.pop();
        if (ans[v.S]==-1){
            ans[v.S]=v.F;
            if (v.S!=0 && ans[v.S-1]==-1) q.push(make_pair(-1*(v.F+1),v.S-1));
            if (v.S!=n-1 && ans[v.S+1]==-1) q.push(make_pair(-1*(v.F+1),v.S+1));
        }
    }
    FOR(n) cout<<ans[i]<<' ';
    cout<<endl;
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
    while (t--){
        solve();
    }
}
