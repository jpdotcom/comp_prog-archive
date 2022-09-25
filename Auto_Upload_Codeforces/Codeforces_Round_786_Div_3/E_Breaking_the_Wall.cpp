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
#define MOD (ll)(998244353)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
const int maxN=2e5+1;
int a[maxN];
int find_t(int u, int v){
    int l=0, r=v;
    int ans=v;
    while (l<=r){
        int m=l+(r-l)/2;
        if (ceil(v-3*m)/2>=u-3*m){
            r=m-1;
            ans=m;
        }
        else l=m+1;
    }
    return ans;
}
void solve(){
    int n; cin>>n;
    FOR(n) cin>>a[i];
    vi b(n);
    FOR(n) b[i]=ceil(a[i]/2.0);
    sort(b.begin(),b.end());
    int ans=b[0]+b[1];
    FOR(n-2){
        int u=a[i],v=a[i+2];
        if (u>v) swap(u,v);
        ans=min(ans,u+(int)ceil((v-u)/2.0));
    }
    FOR(n-1){
        int u=a[i],v=a[i+1];
        if (u>v) swap(u,v);
        int t=find_t(u,v);
        ans=min(ans,2*t+(int)ceil((v-3*t)/2.0));
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
