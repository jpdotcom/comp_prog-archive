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
#define INF ((int)1e9)
#define MOD ((ll)1e9+7)
using namespace std;
const int maxN=2e5+1;
int a[maxN];
int n,d;
int calc(vi vals){
    int mn=vals[0]-1;
    int mx=vals[0]-1;
    for (int i=1;i<vals.size();i++){
        mn=min(mn,vals[i]-vals[i-1]-1);
        mx=max(mx,vals[i]-vals[i-1]-1);
    }
    return min(mn,max((mx-1)/2,d-vals[vals.size()-1]-1));
}
void solve(){
    cin>>n>>d;
    FOR(n) cin>>a[i];
    int mx=a[0]-1;
    int mxi=0;
    int ans=-1*INF;
    for (int i=1;i<n;i++){
        int v=a[i]-a[i-1]-1;
        if (v<mx){
            mx=v;
            mxi=i;
        }
    }
    vi vals;
    FOR(n){
        if (i!=mxi) vals.pb(a[i]);
    }
    ans=calc(vals);
    vals.clear();
    FOR(n){
        if (i!=mxi-1) vals.pb(a[i]);
    }
    ans=max(ans,calc(vals));
    print(ans);
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
    while (t--)
    {solve();
    }
}
