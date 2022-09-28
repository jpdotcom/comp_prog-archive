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
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
const int maxN=3005;
ll a[maxN][3];
vi adj[maxN];
int seen[maxN];
bool inter(int i,int j){
    ll v=powl(a[i][0]-a[j][0],2)+powl(a[i][1]-a[j][1],2);
    return !(powl(a[i][2]-a[j][2],2)> v  || v>powl(a[i][2]+a[j][2],2));
}
int dfs(int p1,int p2){
    seen[p1]=true;
    if (p1==p2) return true;
    bool ok=false;
    for (int v:adj[p1]){
        if (!seen[v]) ok|= dfs(v,p2);
    }
    return ok;
}
void solve(){
    int n; cin>>n;
    ll x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
    int p1,p2;
    FOR(n+1) seen[i]=0;
    FOR(n){
        cin>>a[i][0]>>a[i][1]>>a[i][2];
        if (powl(x1-a[i][0],2)+powl(y1-a[i][1],2)==powl(a[i][2],2)) p1=i;
        if (powl(x2-a[i][0],2)+powl(y2-a[i][1],2)==powl(a[i][2],2)) p2=i;
    }
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if (inter(i,j)){
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }
    }
    if ((dfs(p1,p2))) print("Yes");
    else print("No");
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
    while (t--){
        solve();
    }
}


