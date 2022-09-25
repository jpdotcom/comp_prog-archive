#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<long long, long long> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<int> pq;
#define put push
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
const int maxN=2e5+1;
int n;
pi a[maxN];
string s;
int c;
char get(ll k){
    if (k<s.size()){
        return s[k];
    }
    ll l=s.size()-1;
    ll idx=0;
    for (int i=0;i<c;i++){
        if (l+a[i].S-a[i].F+1<k){
            l+=(a[i].S-a[i].F+1);
            idx=i+1;
        }
        else break;
    }
    return get(a[idx].F+k-l-1);
}
void solve(){
    cin>>n>>c;
    int q; cin>>q;
    cin>>s;
    FOR(c){
        ll u,v; cin>>u>>v; u--,v--;
        a[i].F=u;
        a[i].S=v;
    }
    FOR(q){
        ll k; cin>>k; k--;
        print(get(k));
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


