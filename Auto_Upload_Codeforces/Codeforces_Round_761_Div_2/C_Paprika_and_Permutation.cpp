#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<int,int> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((int)1e9)
#define MOD ((ll)1e9+7)
using namespace std;
const int maxN=2e5+1;
int a[maxN];
bool has[maxN];
void solve(){
    int n; cin>>n;
    FOR(n) cin>>a[i];
    sort(a,a+n);
    vi need,have;
    fill(has,has+n+1,0);
    FOR(n){
        if (a[i]>n || has[a[i]]) have.pb(a[i]);
        if (a[i]<=n) has[a[i]]=1;
    }
    FOR(n){
        if (!has[i+1]) need.pb(i+1);
    }
    sort(need.begin(),need.end());
    sort(have.begin(),have.end());
    bool ok=true;
    for (int i=0;i<need.size();i++){
        if (2*need[i]>=have[i]) ok=false;
    }
    if (ok) print(need.size());
    else print(-1);
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
    cin>>t;
    while (t--)
    {
        solve();
    }
}
