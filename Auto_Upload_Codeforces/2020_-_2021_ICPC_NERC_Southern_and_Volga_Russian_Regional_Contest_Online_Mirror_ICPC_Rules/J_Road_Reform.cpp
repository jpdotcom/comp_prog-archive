#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
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
int s[maxN];
int p[maxN];
vector<vector<int>> edges;
int rep(int a){
    if (p[a]==a) return a;
    return p[a]=rep(p[a]);
}
void un(int a, int b){
    a=rep(a),b=rep(b);
    if (a==b) return;
    if (s[a]>=s[b]) swap(a,b);
    p[a]=b;
    s[b]+=s[a];
}
void solve(){
    int n,m,k; cin>>n>>m>>k;
    edges.clear();
    FOR(n+1){
        p[i]=i;
        s[i]=1;
    }
    FOR(m){
        int a,b,c; cin>>a>>b>>c;
        vi p={max(0,abs(c-k)),a,b,c};
        edges.pb(p);
    }
    sort(edges.begin(),edges.end());
    ll ans=0;
    for (int i=1;i<edges.size();i++){
        edges[i][0]=max(edges[i][3]-k,0);
    }
    sort(edges.begin()+1,edges.end());
    int redo=false;
    for (int i=0;i<edges.size();i++){
        vi x=edges[i];
        int a=x[1],b=x[2],c=x[0];
        if (rep(a)!=rep(b)){
            if (i>=1 && c>0) redo=true;
            ans+=c;
            un(a,b);
        }
    }
    ll sans=0;
    if (redo){
        FOR(n+1){
            p[i]=i;
            s[i]=1;
        }
        edges[0][0]=max(0,edges[0][3]-k);
        sort(edges.begin(),edges.end());
        FOR(edges.size()){
            vi x=edges[i];
            int a=x[1],b=x[2],c=x[0];
            if (rep(a)!=rep(b)){
                sans+=c;
                un(a,b);
            }
        }
        print(min(sans,ans));
    }
    else{
        print(ans);
    }
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
