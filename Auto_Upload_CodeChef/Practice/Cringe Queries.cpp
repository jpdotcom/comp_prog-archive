#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<long long> vi;
typedef std::pair<int,int> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<int> pq;
#define endl '\n'
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define MOD (ll)(998244353)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
const int maxN=1e6+2;
int s[maxN];
int p[maxN];
int rep(int a){
    if (p[a]==a) return a;
    return p[a]=rep(p[a]);
}
void un(int a, int b){
    a=rep(a);
    b=rep(b);
    if (a!=b){
        if (s[a]>s[b]) swap(a,b);
        p[a]=b;
        s[b]+=s[a];
        s[a]=s[b];
    }
    return;
}
void solve(){
    int n,q; cin>>n>>q;
    ll ans=1;
    FOR(n+2) p[i]=i;
    FOR(q){
        int l,r; cin>>l>>r;
        if (rep(l)!=rep(r+1)){
            un(l,r+1);
            ans*=2;
            ans%=MOD;
        }
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
