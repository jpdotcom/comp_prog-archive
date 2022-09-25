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
const int maxN=90005;
int occ[maxN];
map<int,int> idx;
int a[maxN];
int b[maxN];
void solve(){
    int n,m; cin>>n>>m;
    idx.clear();
    FOR(n*m+1) occ[i]=0;
    for (int i=0;i<n*m;i++){
        int v; cin>>v;
        a[i]=v;
        b[i]=v;
    }
    sort(a,a+n*m);
    FOR(n*m){
        if (idx[a[i]]==0) idx[a[i]]=i+1;
    }
    ll ans=0;
    for (int i=0;i<n*m;i++){
        int v=b[i];
        int j=idx[v];
        for (int k=m*((j-1)/m)+1;k<j;k++){
            if (occ[k] && occ[k]!=v){
                ans++;
            }
        }
        occ[idx[v]]=v;
        idx[v]++;
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
    while (t--){
        solve();
    }
}


