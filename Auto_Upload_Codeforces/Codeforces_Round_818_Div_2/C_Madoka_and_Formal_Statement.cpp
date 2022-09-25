#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<int, int> pi;
typedef long long ll;
typedef std::priority_queue<int> pq;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define iset tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
const int maxN=2e6;
int a[maxN];
int b[maxN];
void solve(){
    int n; cin>>n;
    FOR(n) cin>>a[i];
    FOR(n) cin>>b[i];
    bool ok=true;
    FOR(n){
        ok&=((a[i]==b[i]) || ((a[i]<=b[i] && a[i]<=b[(i+1)%n]) && b[i]-1<=b[(i+1)%n]));
    }
    if (ok) print("YES");
    else print("NO");
}
void precompute(){

}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    cin>>t;
    while (t--) solve();
}

