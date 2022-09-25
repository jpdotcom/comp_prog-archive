#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<int,int> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<int> pq;
#define endl '\n'
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
const int maxN=4e6+1;
ll a[maxN];
ll b[maxN];
void solve(){
    int n; cin>>n;
    FOR(n) cin>>a[i];
    FOR(n) cin>>b[i];
    vector<pi> out;
    bool ok =true;
    for (int i=1;i<n;i++){
        int k=i-1;
        for (int j=i-1 ; (j>=0 && a[j]>=a[j+1] && b[j]>=b[j+1]); j--){
            k=j-1;
            out.pb(mp(j+1,j+2));
            swap(a[j],a[j+1]);
            swap(b[j],b[j+1]);
        }
        if (k>=0 && (a[k]>a[k+1] || b[k]>b[k+1])){
            ok=false;
        }
    }
    if (ok){
        print(out.size());
        for (pi x: out) cout<<x.F<<' '<<x.S<<endl;
    }
    else print(-1);
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


