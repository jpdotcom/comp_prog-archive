#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<long long> vi;
typedef std::pair<int,int> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
#define MOD (2012)
using namespace std;
const int maxN=1e6+1;
ll a[maxN];
ll b[maxN];
ll use[maxN];
int k;
int get(ll n,ll m){
    ll p=0;
    ll tot=0;
    ll still=0;
    FOR(k){
        if (a[i]>=2*n){
            use[i]=1;
            p+=2;
            a[i]-=2*n;
            tot+=2;
            if (a[i]>=n) still++;
        }
    }
    if (p>m && (m&1)){
        if (still==0) return 0;
        else return 1;
    }
    FOR(k){
        if (use[i]) tot+=a[i]/n;
    }
    if (tot>=m) return 1;
    else return 0;

}
void solve(){
    int n,m; cin>>n>>m>>k;
    FOR(k){
        cin>>a[i];
        b[i]=a[i];
        use[i]=0;
    }
    int ans=get(n,m);
    FOR(k){
        use[i]=0;
        a[i]=b[i];
    }
    ans|=get(m,n);
    if (ans) print("YES");
    else print("NO");
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
    cin>>t;
    while (t--){
        solve();
    }
}
