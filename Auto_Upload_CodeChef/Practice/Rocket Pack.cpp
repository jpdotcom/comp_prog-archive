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
#define INF ((ll)1e18)
#define MOD ((ll)1e9+7)
using namespace std;
const int maxN=3e5+10;
int n;
ll cost[maxN];
ll dist[maxN];
ll energy[maxN];
ll dp[maxN];
// hi + di must be increasing in an optimal solution. Why? 

// If it wasn't, we could construct a better solution. Let xi=hi+di.

// x1, x2, x3, x4, x5. 
// if x2>x3, for example, then we could eliminate x3 b/c since x3 would reach d4, x2 can as well. 
struct node{
    long long val=0;
    long long lazy=0;
    ll l,r;
    struct node *leftChild,*rightChild;
    node(int lv,int rv){
        l=lv,r=rv;
        if (l!=r){
            int m=(l+r)/2;
            leftChild=new node(l,m);
            rightChild=new node(m+1,r);
        }
    }
    void prop(){
        val+=lazy;
        if (l!=r){
            leftChild->lazy+=lazy;
            rightChild->lazy+=lazy;
        }
        lazy=0;
    }
    long long query(int ql, int qr){
        prop();
        if (qr<l || ql>r || l>r) return INF;
        if (ql<=l && r<=qr){
            return val;
        }
        return min(leftChild->query(ql,qr),rightChild->query(ql,qr));
    }
    void update(int ql, int qr, ll v){
        prop();
        if (qr<l || ql>r || l>r) return;
        if (ql<=l && r<=qr){
            val+=v;
            if (l!=r){
                leftChild->lazy+=v;
                rightChild->lazy+=v;
            }
        }
        else{
            leftChild->update(ql,qr,v),rightChild->update(ql,qr,v);
            val=min(leftChild->val,rightChild->val);
        }
    }
};
void solve(){
    ll x,y; cin>>x>>y>>n;
    vector<pair<ll,ll>> normal;
    for (int i=0;i<n;i++){
        ll a,b,c,d; cin>>a>>b>>c>>d;
        d+=(a+b);
        dist[i]=a+b;
        cost[i]=c;
        energy[i]=d;
        normal.pb(mp(d,i));
    }
    sort(normal.begin(),normal.end());
    ll ans=INF;
    ll min_val=INF;
    auto find=[&] (ll val, int idx){
        int low=0,high=idx;
        int ans=idx;
        while (low<=high){
            int mid=low+(high-low)/2;
            if (normal[mid].F>=val){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    };
    node st(0,n-1);
    for (int i=0;i<n;i++){
        dp[i]=INF;
        if (dist[normal[i].S]==0) dp[i]=cost[normal[i].S];
        int idx=normal[i].S;
        ll c=cost[idx];
        ll v=find(dist[idx],i-1);
        if (v>=0) dp[i]=min(st.query(v,i-1)+c,dp[i]);
        if (energy[idx]>=x+y) ans=min(ans,dp[i]);
        st.update(i,i,dp[i]);
    }
    print(ans);
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
    cin>>t;
    while (t--)
    {
        solve();
    }
}
