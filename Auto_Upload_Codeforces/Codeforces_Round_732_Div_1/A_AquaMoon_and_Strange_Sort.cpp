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
#define MOD (ll)(998244353)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
const int maxN=1e5+1;
int a[maxN];
int b[maxN];
unordered_map<int,int> p;
unordered_map<int,int> af;
void solve(){
    int n; cin>>n;
    p.clear(),af.clear();
    FOR(n){
        cin>>a[i];
        b[i]=a[i];
        p[a[i]]+=(i&1);
    }
    sort(b,b+n);
    FOR(n){
        af[b[i]]+=(i&1);
    }
    bool ok=true;
    FOR(n){
        ok&=(p[a[i]]==af[a[i]]);
    }
    if (ok) print("YES");
    else print("NO");
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
