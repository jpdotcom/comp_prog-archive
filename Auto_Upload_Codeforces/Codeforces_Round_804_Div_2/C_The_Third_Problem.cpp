#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<long long> vi;
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
const int maxN=1e5+1;
int pos[maxN];
void solve(){
    int n;
    cin>>n;
    FOR(n){
        int a;
        cin>>a;
        pos[a]=i;
    }
    int l=min(pos[0],pos[1]);
    int r=max(pos[0],pos[1]);
    ll ans=1;
    for (int i=2;i<n;i++){
        if (l<= pos[i] && pos[i]<=r){
            ans*=(r-l+1-i);
            ans%=MOD;
        }
        l=min(pos[i],l);
        r=max(pos[i],r);
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
    cin>>t;
    while (t--){
        solve();
    }
}
