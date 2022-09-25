#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<long long> vi;
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
#define MOD (2012)
using namespace std;
const int maxN=3e5+1;
const int maxC=1e6+10;
void solve(){
    ll n,c; cin>>n>>c;
    vi ans(c+1,0);
    vi mx_val(c+1,0);
    FOR(n){
        ll a,b,c; cin>>a>>b>>c;
        mx_val[a]=max(mx_val[a],b*c);
    }
    for (int i=1;i<=c;i++){
        for (int j=1;i*j<=c;j++){
            ans[i*j]=max(ans[i*j],mx_val[i]*j);
        }
    }
    for (int i=1;i<=c;i++)
        ans[i]=max(ans[i],ans[i-1]);
    int m; cin>>m;
    FOR(m){
        ll a,b; cin>>a>>b;
        a*=b;
        int val=upper_bound(ans.begin(),ans.end(),a)-ans.begin();
        cout<<(val==c+1 ? -1 : val)<<' ';
    }
    cout<<endl;
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
