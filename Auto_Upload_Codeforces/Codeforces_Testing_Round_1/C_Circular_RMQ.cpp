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
#define INF ((int)1e9+7)
#define MOD ((ll)1e9+7)
using namespace std;
const int maxN=1e9+1;
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
        val+=lazy;
        if (l!=r){
            leftChild->lazy+=lazy;
            rightChild->lazy+=lazy;
        }
        lazy=0;
    }
    long long query(int ql, int qr){
        prop();
        if (qr<l || ql>r) return INF;
        if (ql<=l && r<=qr){
            return val;
        }
        return min(leftChild->query(ql,qr),rightChild->query(ql,qr));
    }
    void update(int ql, int qr, int v){
        prop();
        if (qr<l || ql>r) return;
       
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
    int n; cin>>n;
    node st(0,n-1);
    FOR(n){
        int v; cin>>v;
        st.update(i,i,v);
    }
    int m; cin>>m;
    string s;
    getline(cin,s);
    FOR(m){
        string s; 
        getline(cin,s);
        istringstream iss(s);
        vi vals;
        int num;
        while (iss >> num){
            vals.push_back(num);
        }
        if (vals.size()==2){
            int a=vals[0];
            int b=vals[1];
            if (b<a) print(min(st.query(a,n-1),st.query(0,b)));
            else print(st.query(a,b));
        }
        else{
            int a=vals[0],b=vals[1],c=vals[2];
            if (b<a){
                st.update(a,n-1,c);
                st.update(0,b,c);
            }
            else st.update(a,b,c);
        }
        
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
    while (t--){
        solve();
    }
}
