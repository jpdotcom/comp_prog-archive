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
const int maxN=2e5+1;
int a[maxN];
int lastocc[maxN];
set<int> vals;
int m[maxN];
void solve(){
    int n; cin>>n;
    vals.clear();
    FOR(n){
        cin>>a[i];
        lastocc[a[i]]=i;
    }
    m[n-1]=a[n-1];
    for (int i=n-2;~i;i--) m[i]=min(m[i+1],a[i]);
    int j=0;
    for (int i=0;i<n;i++){
        if (m[i]<a[i]){
            for (j;j<=lastocc[a[i]];j++) vals.insert(a[j]);
        }
    }
    j=0;
    for (int i=0;i<n;i++){
        if (vals.find(a[i])!=vals.end()){
            for (j;j<=lastocc[a[i]];j++) vals.insert(a[j]);
        }
    }
    print(vals.size());
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
