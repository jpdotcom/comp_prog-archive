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
    ll n,k,b,s; cin>>n>>k>>b>>s;
    FOR(n) a[i]=0;
    int v=-1;
    for (int i=0;i<=n-1;i++){
        if ((s-(i*(k-1)))/k==b){
            v=i;
            break;
        }
    }
    if (v==-1) print(v);
    else{
        s-=(v*(k-1));
        FOR(v) a[i]=k-1;
        a[n-1]=s;
        FOR(n) cout<<a[i]<<' ';
        cout<<endl;
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
    cin>>t;
    while (t--) solve();
}
