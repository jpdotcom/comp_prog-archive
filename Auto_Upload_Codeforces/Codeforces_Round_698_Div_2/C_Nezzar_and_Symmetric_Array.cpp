#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<int, int> pi;
typedef long long ll;
typedef std::priority_queue<int> pq;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define iset tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
const int maxN=1e6+1;
ll a[maxN];
map<ll,ll> cnt;
void solve(){
    int n; cin>>n;
    n*=2;
    FOR(n) cin>>a[i];
    cnt.clear();
    sort(a,a+n);
    bool ok=true;
    ok&=(a[n-1]%n==0 && (a[n-1])/n!=0);
    ll prev_val=a[n-1]/n;
    cnt[prev_val]++;
    for (int i=n-2,v=1;i>=0;i--,v++){
        if (v&1){
            ok&=a[i]==a[i+1];
            cnt[-1*a[i+1]]++;
        }
        else{
            ok&=((a[i]-2*prev_val)%(n-v)==0 && (a[i]-2*prev_val)/(n-v)>0);
            cnt[((a[i]-2*prev_val)/(n-v))]++;
            prev_val+=(a[i]-2*prev_val)/(n-v);
        }

    }
    for (auto &it: cnt) ok&=(it.S<=1);
    if (ok) print("YES");
    else print("NO");
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
    while (t--) solve();
}


