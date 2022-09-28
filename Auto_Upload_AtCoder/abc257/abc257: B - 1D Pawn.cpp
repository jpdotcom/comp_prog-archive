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
#define MOD (int)(1e9+7)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
const int maxN=1e5+1;
int a[maxN];
int idx[maxN];
void solve(){
    int n,k,q; cin>>n>>k>>q;
    FOR(k){
        int v; cin>>v;
        a[v]=1;
        idx[i+1]=v;
    }
    FOR(q){
        int v; cin>>v;
        int j=idx[v];
        if (j==n || a[j+1]) continue;
        a[j+1]=1;
        a[j]=0;
        idx[v]++;
    }
    for (int i=1;i<=k;i++) cout<<idx[i]<<' ';
    cout<<endl;
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    while (t--){
        solve();
    }
}
