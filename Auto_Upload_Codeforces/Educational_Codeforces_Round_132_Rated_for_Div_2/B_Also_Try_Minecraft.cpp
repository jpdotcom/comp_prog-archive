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
const int maxN=1e6+1;
ll s[maxN];
ll inv[maxN];
ll a[maxN];
void solve(){
    int n,m; cin>>n>>m;
    FOR(n){
        cin>>a[i];
    }
    s[0]=0;
    for (int i=1;i<n;i++) s[i]=max(a[i-1]-a[i],0LL);
    inv[n-1]=0;
    for (int i=n-2;i>=0;i--) inv[i]=max(0LL,a[i+1]-a[i]);
    for (int i=n-2;i>=0;i--) inv[i]+=inv[i+1];
    for (int i=1;i<n;i++) s[i]+=s[i-1];
    FOR(m){
        ll ans=0;
        int a,b; cin>>a>>b;a--,b--;
        if (a<b) ans+=s[b]-s[a];
        else ans+=inv[b]-inv[a];
        print(ans);
    }
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
