#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<long long> vi;
typedef long long ll;
typedef std::pair<int,int> pi;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define endl '\n'
#define print(x) cout<<x<<'\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+10)
#define all(a) (a).begin(), (a).end()
#define MOD ((ll)1e9+7)
using namespace std;
using namespace __gnu_pbds;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=2e5+1;
map<int,int> idxOf;
void solve(){
    set<int> a,b;
    int av,bv;
    int n; cin>>n>>av>>bv;
    FOR(n){
        int v;cin>>v;
        a.insert(v);
        idxOf[v]=i;
    }
    set<int> move;
    for (auto x: a){
        if (a.find(av-x)==a.end()){
            move.insert(x);
            b.insert(x);
        }
    }
    for (int x: move) a.erase(x);
    move.clear();
    for (auto x: b){
        int val=x;
        while (b.find(bv-val)==b.end() && a.find(bv-val)!=a.end()){
            move.insert(bv-val);
            a.erase(bv-val);
            val=av-(bv-val);;
        }
    }
    for (int x: move) b.insert(x);
    bool ok=true;;
    for (auto x: a){
        ok&=(a.find(av-x)!=a.end());
    }
    for (auto x: b){
        ok&=(b.find(bv-x)!=b.end());
    }
    if (!ok) print("NO");
    else{
        vector<int> out(n);
        for (auto x: a){
            out[idxOf[x]]=0;
        }
        for (auto x:b){
            out[idxOf[x]]=1;
        }
        print("YES");
        FOR(n) cout<<out[i]<<' ';
        cout<<endl;
    }
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
    while (t--){
        solve();
        
    }
}
