#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<long long> vi;
typedef std::pair<long long,long long> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<int> pq;
#define endl '\n'
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define MOD (ll)(1e9+7)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
const int maxN=2e5+1;
ll a[maxN];
void solve(){
    int n; cin>>n;
    FOR(n){
        cin>>a[i];
    }
    ll ans=0;
    ll finh=a[0];
    ll subl=0;
    ll subr=0;
    for (int i=1;i<n;i++){
        ans+=abs(a[i]-a[i-1]);
        if (a[i]>a[i-1]){
            subr+=a[i]-a[i-1];
            finh=a[n-1]-subr;
        }
        else{
            subl+=a[i-1]-a[i];
            finh=a[0]-subl;
        }
    }
    print(ans+abs(finh));
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
