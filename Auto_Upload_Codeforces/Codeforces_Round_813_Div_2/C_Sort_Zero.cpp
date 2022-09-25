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
const int INF=1e9+7;
set<int> vals;
bool bad[maxN];
vector<int> occ[maxN];
int a[maxN];
void solve(){
    int n; 
    cin>>n;
    fill(bad,bad+n+1,false);
    FOR(n+1) occ[i].clear();
    FOR(n){
        cin>>a[i];
        occ[a[i]].pb(i);
    }
    FOR(n-1) if (a[i]>a[i+1]) vals.insert(i);
    int ans=0;
    while (vals.size()){
        int v=*vals.begin();
        vals.erase(v);
        if (!bad[v]){
            ans++;
            for (auto x: occ[a[v]]){
                bad[x]=true;
                a[x]=0;
                if (x!=0 && a[x-1]>a[x]){
                    vals.insert(x-1);
                }
            }
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
