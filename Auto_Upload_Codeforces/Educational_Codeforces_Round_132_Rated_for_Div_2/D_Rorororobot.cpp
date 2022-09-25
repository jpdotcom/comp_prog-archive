#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<long long, long long> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
using namespace std;
const int maxN=2e5+10;
int t[2*maxN];
int n;
void build(){
    for (int i=1;i<2*n+1;i++){
        t[i]=0;
    }
}
void update(int a,int b){
    for (a+=n,t[a]=b,a>>=1;a>=1;a>>=1){
        t[a]=max(t[a<<1],t[(a<<1)|1]);
    }
}
int query(int a, int b){
    int ans=0;
    for (a+=n,b+=n;a<=b;a>>=1,b>>=1){
        if ((a&1)) ans=max(ans,t[a++]);
        if ((b&1)==0) ans=max(ans,t[b--]);
    }
    return ans;
}
void solve(){
    int m;
    cin>>m>>n;
    for (int i=0;i<n;i++){
        int v; cin>>v;
        update(i,v);
    }
    int q; cin>>q;
    FOR(q){
        int x1,y1,x2,y2,k; cin>>x1>>y1>>x2>>y2>>k;
        x1--;
        x2--;
        y1--;
        y2--;
        if (y1>y2) swap(y1,y2);
        bool ok=((y2-y1)%k==0);
        int row=query(y1,y2);
        if (x1>=row){
            ok&=abs(x2-x1)%k==0;
        }
        else{
            int next=x1+ceil((row-x1)/(k+0.0))*k;
            ok&=(abs(x2-next)%k==0 && (next<m));
        }
        if (ok) print("YES");
        else print("NO");
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
