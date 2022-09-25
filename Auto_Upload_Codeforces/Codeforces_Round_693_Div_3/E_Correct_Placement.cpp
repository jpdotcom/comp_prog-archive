#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<long long,long long> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
#define MOD ((ll)1e9+7)
using namespace std;
const int maxN=2e5+1;
void solve(){
    int n; cin>>n;
    set<vector<int>> vals;
    vector<vector<int>> p;
    FOR(n){
        int a,b; cin>>a>>b;
        vi v1={a,b,i};
        vi v2={b,a,i};
        p.pb(v1);
        p.pb(v2);
    }
    sort(p.begin(),p.end());
    int ans[n];
    FOR(n) ans[i]=-1;
    vector<vector<int>> topush;
    int prev_val=-1;
    FOR(2*n){
        vi v1=p[i];
        if (v1[0]!=prev_val){
            prev_val=v1[0];
            while (topush.size()){
                vi add=topush[topush.size()-1];
                topush.pop_back();
                swap(add[1],add[0]);
                vals.insert(add);
            }
        }
        if (vals.size()>0){
            vi check=*vals.begin();
            if (v1[0]>check[1] && v1[1]>check[0]) ans[v1[2]]=check[2]+1;
        }
        topush.pb(v1);
    }
    FOR(n) cout<<ans[i]<<' ';
    cout<<endl;
    return;
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(15);
    precompute();
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }
}
