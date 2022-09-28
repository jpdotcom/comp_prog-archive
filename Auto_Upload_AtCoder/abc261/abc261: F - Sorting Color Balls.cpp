#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<int,int> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
#define MOD ((ll)1e9+7)
using namespace std;
using namespace __gnu_pbds;
const int maxN=4e5+1;
int a[maxN];
int b[maxN];
oset c[maxN];
struct node{
    long long val=0;
    long long lazy=0;
    int l,r;
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
        val+=(r-l+1)*lazy;
        if (l!=r){
            leftChild->lazy+=lazy;
            rightChild->lazy+=lazy;
        }
        lazy=0;
    }
    long long query(int ql, int qr){
        prop();
        if (qr<l || ql>r) return 0;
        if (ql<=l && r<=qr){
            return val;
        }
        return leftChild->query(ql,qr)+rightChild->query(ql,qr);
    }
    void update(int ql, int qr, int v){
        prop();
        if (qr<l || ql>r) return;
        if (ql<=l && r<=qr){
            val+=(r-l+1)*v;
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
void solve(){
    int n; cin>>n;
    node st(0,n);
    FOR(n){
        cin>>b[i];
    }
    FOR(n) cin>>a[i];
    ll ans=0;
    FOR(n){
        int sameColor=c[b[i]].size();
        int less=st.query(1,a[i]);
        int both=c[b[i]].order_of_key(make_pair(a[i],i));
        int tot=sameColor+less-both;
        ans+=i-tot;
        st.update(a[i],a[i],1);
        c[b[i]].insert(make_pair(a[i],i));
    }
    print(ans);
}
void precompute(){
}
int main(){
    precompute();
    int t=1;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(15);
    while (t--) solve();
}
