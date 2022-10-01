#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<int,int> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<int> pq;
#define endl '\n'
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
const int maxN=2e5+1;
int a[maxN];
void solve(){
    int n,x; cin>>n>>x;
    int c=(int)(pow(2,(int)(log2(n)+1))-1)^x;
    if ((int)log2(n)==log2(n)){
        if (!bit(x,(int)log2(n))){
            print(-1);
            return;
        }
    }
    int cval=0;
    FOR(n+1) a[i]=0;
    if (n==2){
        if (x!=3) print(-1);
        else cout<<1<<' '<<1<<' '<<2<<endl;
        return;
    }
    vector<pi>out;
    for (int i=0;i<16;i++){
        if (bit(c,i) && (bit(c,i)<<i) <= n){
            if (cval==0) cval=(1<<i);
        
        else{
            out.pb(mp(cval,1<<i));
            cval^=(1<<i);
        }

            a[1<<i]=1;
        }
        else if (bit(c,i)){
            print(-1);
            return;
        }
    }
    for (pi v: out) cout<<2<<' '<<v.F<<' '<<v.S<<endl;
    cval=0;
    for (int i=1;i<=n;i++){
        if (!a[i]){
            if (cval) cout<<1<<' '<<cval<<' '<<i<<endl;
            cval|=i;
        }
    }
    if (c!=0) cout<<2<<' '<<c<<' '<<(int)pow(2,(int)(log2(n))+1)-1<<endl;

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
    while (t--){
        solve();
    }
}


