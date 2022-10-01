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
#define endl '\n'
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define MOD (ll)(1e9+7)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
const int maxN=1e6+100;
pi t[2*maxN];
int n;
pi inter(pi a, pi b){
    if (b.F<a.F) swap(a,b);
    int v1=max(a.F,b.F);
    int v2=min(a.S,b.S);
    if (a.S<b.F) return make_pair(-1,-1);
    else return make_pair(v1,v2);
}
void update(int i, pi p){
    i+=n;
    t[i]=p;
    for (i>>=1;i>0;i>>=1) t[i]=inter(t[i<<1],t[(i<<1)|1]);
    return;
}
pi query(int a,int b){
    pi ans=make_pair(0,n-1);
    for (a+=n,b+=n; a<=b; a>>=1,b>>=1){
        if (a&1) ans=inter(ans,t[a++]);
        if ((b&1)==0) ans=inter(ans,t[b--]);
    }
    return ans;
}
void solve(){
    cin>>n;
    FOR(2*n+1) t[i]=make_pair(0,n-1);
    FOR(n){
        pi p; cin>>p.F>>p.S;
        update(i,p);
    }
    int i=0;
    int j=0;
    int ans=0;
    while (j<n){
        pi v=query(i,j);
        if (v.F==-1 || v.S-v.F<j-i) i++;
        else ans=max(ans,j-i+1);
        j++;
    }
    print(ans);
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    while (t--){
        solve();
    }
}


