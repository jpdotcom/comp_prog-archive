#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
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
const int maxN=1e6+1;
ll a[maxN];
void solve(){
    int n,x; cin>>n>>x;
    FOR(n) cin>>a[i];
    int l=a[0]-x;
    int r=a[0]+x;
    int ans=0;
    for (int i=1;i<n;i++){
        int l2=a[i]-x;
        int r2=a[i]+x;
        int nl=max(l,l2);
        int nr=min(r,r2);
        if (nr<nl){
            ans++;
            l=l2;
            r=r2;
        }
        else{
            l=nl;
            r=nr;
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
    precompute();
    int t=1;
    cin>>t;
    while (t--) solve();
}


