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
const int maxN=2e5+1;
int a[maxN];
int cnt[maxN];
void solve(){
    int n; cin>>n;
    FOR(n+1) cnt[i]=0;
    FOR(n){
        cin>>a[i];
        cnt[a[i]]++;
    }
    sort(a,a+n);
    stack<int> vals;
    ll ans=cnt[0];
    cout<<ans<<' ';
    ans=0;
    int idx=0;
    FOR(n){
        while (idx<n && a[idx]<i+1) vals.push(a[idx++]);
        if (ans!=-1){
        if (vals.size()==0){
            ans=-1;
        }
        else{
            ll v=vals.top();
            vals.pop();
            ans+=(i-v);
        }
        }
        if (ans==-1) cout<<ans<<' ';
        else cout<<ans+cnt[i+1]<<' ';
    }
    cout<<endl;
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


