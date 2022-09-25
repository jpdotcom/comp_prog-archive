#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<long long,long long> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<int> pq;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define MOD (ll)(998244353)
#define INF ((int)1e9+7)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
using u64 = uint64_t;
using u128 = __uint128_t;
struct node{
    long long val=0;
    long long lazy=-1;
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
        if (lazy==-1) return;
        val=lazy;
        if (l!=r){
            leftChild->lazy=lazy;
            rightChild->lazy=lazy;
        }
        lazy=0;
    }
    long long query(int ql, int qr){
        prop();
        if (qr<l || ql>r) return 0;
        if (ql<=l && r<=qr){
            return val;
        }
        return gcd(leftChild->query(ql,qr),rightChild->query(ql,qr));
    }
    void update(int ql, int qr, int v){
        prop();
        if (qr<l || ql>r) return;
        if (ql<=l && r<=qr){
            val=v;
            if (l!=r){
                leftChild->lazy=v;
                rightChild->lazy=v;
            }
        }
        else{
            leftChild->update(ql,qr,v),rightChild->update(ql,qr,v);
            val=gcd(leftChild->val,rightChild->val);
        }
    }
};
void solve(){
    int n; cin>>n;
    vector<int> a(n),left(n);
    node st(0,n-1);
    FOR(n){
        cin>>a[i];
        st.update(i,i,a[i]);
    }
    for (int i=0;i<n;i++){
        int lo=i,hi=n-1,best=-1;
        while (lo<=hi){
            int mid=(lo+hi)>>1;
            int val=st.query(i,mid);
            if (val>mid-i+1){
                lo=mid+1;
            }
            else if (val<mid-i+1){
                hi=mid-1;
            }
            else{
                best=mid;
                break;
            }
        }
        left[i]=best;
    }
    int ans=0;
    int idx=0;
    vector<int> marked(n,0);
    for (int i=0;i<n;){
        if (left[i]==-1){
            i++;
        }
        else{
            marked[left[i]]=1;
            i =left[i]+1;
        }
    }
    FOR(n){
        if (marked[i]) ans++;
        cout<<ans<<' ';
    }
    cout<<endl;
}
void precompute(){
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    //cin>>t;
    while (t--){
        solve();
    }
}

