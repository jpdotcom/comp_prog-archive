#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<long  long> vi;
typedef std::pair<int,int> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>(s))&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((int)1e9+10)
#define MOD ((ll)1e9+7)
using namespace std;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=1e6+10;
int a[maxN];
struct DSU{
    vector<int> p;
    vector<int> s;
    vector<int> mi;
    vector<int> mx;
    int limit;
    DSU(int l){
        limit=l;
        p=vector<int>(limit+1);
        s=vector<int>(limit+1,1);
        mi=vector<int>(limit+1,0);
        mx=vector<int>(limit+1,0);
        p[0]=s[0]=0;
        mx[0]=mi[0]=0;
        for (int i=1;i<=limit;i++){
            p[i]=i;
            s[i]=1;
            mx[i]=a[i-1];
            mi[i]=a[i-1];
        }
    }
    int find(int a){
        return (p[a]==a ? a : p[a]=find(p[a]));
    }
    int unite(int a, int b){
        if ((a=find(a)) == (b=find(b))) return -1;
        else{
            if (s[a]>s[b]) swap(a,b);
            p[a]=b;
            s[b]+=s[a];
            mx[b]=max(mx[b],mx[a]);
            mi[b]=min(mi[b],mi[a]);
            return a;
        }
    }
    vector<vector<int>> get_components(){
        vector<vector<int>> c(limit+1);
        for (int i=1;i<=limit;i++){
            c[find(i)].pb(i);
        }
        vector<vector<int>> out;
        for (int i=1;i<=limit;i++){
            if (c[i].size()>=1) out.pb(c[i]);
        }
        return out;
    }
};
void solve(){
    int n; cin>>n;
    FOR(n) cin>>a[i];
    DSU dj(n);
    set<pair<int,int>> reps;
    reps.insert(make_pair(a[n-1],n));
    for (int i=n-2;~i;i--){
        int tot=0;
        for (auto x: reps){
            int r1=dj.find(x.S);
            int r2=dj.find(i+1);
            if (dj.mi[r1]<a[i]){
                int v=dj.unite(r2,r1);
                tot++;
            }
            else break;
        }
        reps.insert(mp(dj.mi[i+1],i+1));
        while (tot--){
            reps.erase(*reps.begin());
        }
    }
    print(reps.size());
}
void precompute(){
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(15);
    precompute();
    int t=1;
    int i=1;
    cin>>t;
    while (t--)
    {
        solve();
        ++i;
    }
}
