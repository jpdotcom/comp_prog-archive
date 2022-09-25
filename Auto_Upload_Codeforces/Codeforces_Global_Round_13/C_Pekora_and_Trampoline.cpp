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
using namespace __gnu_pbds;
const int maxN=1e6+1;
ll a[maxN];
ll prefix[maxN];
void solve(){
    ll n; cin>>n;
    FOR(n+10) prefix[i]=0;
    FOR(n){
        cin>>a[i+1];
    }
    ll ans=0;
    for (int i=1;i<=n;i++){
        prefix[i]+=prefix[i-1];
        ans+=max(0LL,a[i]-prefix[i]-1);
        prefix[i+1]+=max(0LL,prefix[i]-a[i]+1);
        prefix[i+2]-=max(0LL,prefix[i]-a[i]+1);
        if (a[i]!=1){
        prefix[i+2]+=1;
        prefix[min(n+1,i+a[i]+1)]-=1;
        }
    }
    print(ans);
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
