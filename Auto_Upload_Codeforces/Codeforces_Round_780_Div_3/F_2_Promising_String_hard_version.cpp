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
#define MOD (ll)(998244353)
#define INF ((int)1e9+7)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
const int maxN=2e5+1;
void solve(){
    int n; cin>>n;
    string s; cin>>s;
    ll ans=0;
    iset cnt[3];
    ll sum=0;
    for (int i=0;i<n;++i){
        sum+=(s[i]=='+' ? 1 : -1);
        cnt[((sum%3)+3)%3].insert(mp(sum,i));
    }
    ans=cnt[0].order_of_key(mp(1,INF));
    sum=0;
    for (int i=0;i<n;++i){
        sum+=(s[i]=='+' ? 1: -1);
        cnt[((sum%3)+3)%3].erase(mp(sum,i));
        int v=cnt[((sum%3)+3)%3].order_of_key(mp(sum+1,INF));
        ans+=v;
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

