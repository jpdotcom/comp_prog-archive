#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<long long> vi;
typedef std::pair<int,int> pi;
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
int a[maxN];
int b[maxN];
void solve(){
    int n,m; cin>>n>>m;
    FOR(n) cin>>a[i];
    FOR(n) cin>>b[i];
    priority_queue<int> pq;
    vi left;
    left.pb(0);
    FOR(n) {
        if (b[i]==2) pq.push(a[i]);
        else left.pb(a[i]);
    }

    sort(left.begin()+1,left.end());
    reverse(left.begin()+1,left.end());
    for (int i=1;i<left.size();i++) left[i]+=left[i-1];
    int ans=(lower_bound(left.begin(),left.end(),m)!=left.end() ? lower_bound(left.begin(),left.end(),m)-left.begin() : 1e9+7);
    ll s=0;
    int c=0;
    while (pq.size()){
        c++;
        s+=pq.top();
        pq.pop();
        int v=lower_bound(left.begin(),left.end(),m-s)-left.begin();
        if (v!=left.size()) ans=min(ans,2*c+v);
    }
    print((ans==(1e9+7) ?  -1 : ans));
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
    while (t--){
        solve();
    }
}
