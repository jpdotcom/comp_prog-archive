#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<int,char> pi;
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
const int maxN=4e5+1;
int prefix[maxN];
void solve(){
    int n,q; cin>>n>>q;
    string s; cin>>s;
    FOR(n){
        int a=(s[i]=='+' ? 1 : -1);
        prefix[i+1]=prefix[i]+((i&1) ? -1*a : a);
    }
    FOR(q){
        int l,r; cin>>l>>r;
        int s=(l&1 ? prefix[l-1]-prefix[r] : prefix[r]-prefix[l-1]);
        if (s==0) print(0);
        else if ((r-l+1) & 1) print(1);
        else print(2);
    }
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


