#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<long long, long long> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
using namespace std;
const int maxN=2e5+10;
ll a[maxN];
void solve(){
    ll n,m; cin>>n>>m;
    FOR(n) cin>>a[i];
    sort(a,a+n);
    ll curr=0;
    for (int i=1;i<n;i++){
        curr+=max(a[i],a[i-1])+1;
        if (a[i]>=m-1){
            print("NO");
            return;
        }
    }
    if (curr<=m && (m-1-a[0]>=curr) && (curr+a[n-1]+1)<=m) print("YES");
    else print("NO");
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
