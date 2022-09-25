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
#define put push
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
const int maxN=2e5+1;
ll a[maxN];
void solve(){
    int n; cin>>n;
    FOR(n) cin>>a[i];
    int u,v;
    bool ok=false;
    for (int i=0;i<n-1;i++){
        if (a[i]>=1){
            u=i;
            v=i;
            ok=true;
            break;
        }
    }
    if (!ok){
        print(0);
        return;
    }
    ll s=0;
    while (v<=n-1){
        if (a[v]>=1) v++;
        else{
            s++;
            a[u]--;
            if (a[u]==0) u++;
            a[v]++;
            v++;
        }
    }
    for (int i=0;i<n-1;i++){
        if (a[i]>0) s+=a[i];
    }
    print(s);
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


