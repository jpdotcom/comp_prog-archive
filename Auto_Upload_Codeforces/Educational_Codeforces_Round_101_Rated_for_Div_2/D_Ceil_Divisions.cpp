#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<long long,long long> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
#define MOD ((ll)1e9+7)
using namespace std;
const int maxN=2e5+1;
bool mark[maxN];
int times(double a, double b){
    int ans=0;
    while (b>1){
        b=ceil(b/a);
        ans++;
    }
    return ans;
}
void solve(){
    int n; cin>>n;
    bool mark[n+1];
    FOR(n+1) mark[i]=0;
    vector<pi> out;
    int v1=-1,v2=-1;
    for (int i=n-1;i>1;i--){
        if (i==2){
            if (times(2,n)<=9){
                v1=2,v2=n;
                mark[2]=mark[n]=true;
                break;
            }
        }
        else if (times(i,n)+times(2,i)<=9){
            mark[i]=mark[n]=true;
            v1=i,v2=n;
            break;
        }
    }
    for (int i=3;i<=n-1;i++){
        if (!mark[i]) out.pb(mp(i,i+1));
    }
    int add=times(v1,v2);
    FOR(add) out.pb(mp(v2,v1));
    add=times(2,v1);
    if (v1!=2)
        FOR(add)
            out.pb(mp(v1,2));
    print(out.size());
    for (pi x: out) cout<<x.F<<' '<<x.S<<endl;
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
