#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<int,int> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((int)1e9+7)
#define MOD ((ll)1e9+7)
using namespace std;
using namespace __gnu_pbds;
const int maxN=4e5+1;
ll a[maxN];
void solve(){

    ll n,m; cin>>n>>m;
    ll fsum=1;
    ll ans=n*(n+1)/2;
    FOR(n) a[i]=0;
    FOR(n+m){
        int j,x;
        if (i>=n){
            cin>>j>>x; j--;
        }
        else{
            cin>>x;
            j=i;
        }
        ll l=j;
        ll r=n-(j+1);
        if (j!=0){
            if (a[j-1]==a[j] && x!=a[j]) ans+=(l*r+l);
            if (a[j-1]!=a[j] && x==a[j-1]) ans-=(l*r+l);
        }
        if (j!=n-1){
            if (a[j+1]==a[j] && x!=a[j]) ans+=l*r+r;
            if (a[j+1]!=a[j] && x==a[j+1]) ans-=l*r+r;
        }
        a[j]=x;
        if (i>=n) print(ans);
    }
}
void precompute(){
}
int main(){
    precompute();
    int t=1;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(15);
    while (t--) solve();
}
