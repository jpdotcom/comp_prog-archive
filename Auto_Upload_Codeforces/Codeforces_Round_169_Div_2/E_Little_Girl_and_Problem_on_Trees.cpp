#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<long long> vi;
typedef long long ll;
typedef std::pair<ll,ll> pi;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define endl '\n'
#define print(x) cout<<x<<'\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+10)
#define all(a) (a).begin(), (a).end()
#define MOD ((ll)998244353)
using namespace std;
using namespace __gnu_pbds;
using u64 = uint64_t;
using u128 = __uint128_t;
struct node{
    long long val=0;
    long long lazy=0;
    unsigned long long l,r;
    struct node *leftChild,*rightChild;
    node(){}
    node(ll lv,ll rv){
        l=lv,r=rv;
        if (l!=r){
            int m=(l+r)>>1;
            leftChild=new node(l,m);
            rightChild=new node(m+1,r);
        }
    }
    void prop(){
        val+=lazy*(r-l+1);
        if (l!=r){
            leftChild->lazy+=lazy;
            rightChild->lazy+=lazy;
        }
        lazy=0;
    }
    long long query(ll ql, ll qr){
        prop();
        if (qr<l || ql>r || ql>qr) return 0;
        if (ql<=l && r<=qr){
            return val;
        }
        return leftChild->query(ql,qr)+rightChild->query(ql,qr);
    }
    void update(ll ql, ll qr, ll v){
        prop();
        if (qr<l || ql>r || ql>qr) return;
        if (ql<=l && r<=qr){
            val+=v*(r-l+1);
            if (l!=r){
                leftChild->lazy+=v;
                rightChild->lazy+=v;
            }
        }
        else{
            leftChild->update(ql,qr,v),rightChild->update(ql,qr,v);
            val=leftChild->val+rightChild->val;
        }
    }
};
const int maxN=1e6+1;
struct node branch[maxN];
pair<ll,ll> toBranch[maxN];
vector<ll> adj[maxN];
vector<ll> branchD;
ll depth[maxN];
ll dfs(ll u=1,ll p=-1,ll d=0,ll bNum=0){
    ll ans=d;
    ll i=0;
    toBranch[u]=mp(bNum,d);
    depth[u]=d;
    for (int v: adj[u]){
        if (v!=p){
            ll td=dfs(v,u,d+1,(u==1 ? i++ : bNum));
            ans=max(td,ans);
            if (u==1) branchD.pb(td);
        }
    }
    return ans;
}
void solve(){
    ll n,q; cin>>n>>q;
    FOR(n-1){
        ll a,b; cin>>a>>b;
        adj[a].pb(b),adj[b].pb(a);
    }
    dfs();
    ll mxD=0;
    FOR(n+1) branch[i]=node(0,0);
    for (int i=0;i<branchD.size();i++){
        mxD=max(mxD,branchD[i]);
        branch[i]=node(0,branchD[i]);
    }
    branch[n]=node(0,mxD);
    FOR(q){
        ll v; cin>>v;
        if (!v){
            ll u,val,d; cin>>u>>val>>d;
            if (u!=1){
                ll bNum=toBranch[u].F;
                assert(bNum<=branchD.size());
                ll l=max(1LL,depth[u]-d), r=min((ll)branchD[bNum],depth[u]+d);
                branch[bNum].update(l,r,val);
                if (d>=depth[u]){
                    l=0,r=min((ll)mxD,d-depth[u]);
                    branch[n].update(l,r,val);
                    if (l!=r){
                        branch[bNum].update(1,min((ll)r,(ll)branchD[bNum]),-1*val);
                    }
                }
            }
            else{
                ll l=0,r=min((ll)mxD,d-depth[u]);
                branch[n].update(l,r,val);
            }
        }
        else{
            ll u; cin>>u;
            if (u!=1){
                ll bNum=toBranch[u].F;
                print(branch[bNum].query(depth[u],depth[u])+branch[n].query(depth[u],depth[u]));
            }
            else print(branch[n].query(0,0));
        }
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
