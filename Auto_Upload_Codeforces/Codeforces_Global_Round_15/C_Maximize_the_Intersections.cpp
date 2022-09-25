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
pi a[maxN];
bool occ[maxN];
void solve(){
    int n,k; cin>>n>>k;
    FOR(2*n+1) occ[i]=0;
    FOR(k){
        cin>>a[i].F>>a[i].S;
        occ[a[i].F]=occ[a[i].S]=1;
    }
    vi vals;
    for (int i=1;i<=2*n;i++){
        if (!occ[i]) vals.pb(i);
    }
    for (int i=0;i<(int) vals.size()/2;i++){
        a[k+i].F=vals[i], a[k+i].S=vals[i+(vals.size()/2)];
    }
    int ans=0;
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if (a[i].F>a[i].S) swap(a[i].F,a[i].S);
            if (a[j].F>a[j].S) swap(a[j].F,a[j].S);
            ans+=((a[i].F<=a[j].F && a[j].F<=a[i].S && !(a[i].F<=a[j].S && a[j].S<=a[i].S)) || (a[j].F<=a[i].F && a[i].F<= a[j].S && !(a[j].F<= a[i].S && a[i].S <=a[j].S)));
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
    while (t--){
        solve();
    }
}


