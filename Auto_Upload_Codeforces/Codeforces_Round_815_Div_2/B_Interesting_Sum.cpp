#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<long  long> vi;
typedef std::pair<int,int> pi;
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
const int maxN=1e5+1;
int a[maxN];
void solve(){
    int n; cin>>n;
    int ma=0,mi=INF;
    FOR(n){
        cin>>a[i];
        ma=max(ma,a[i]);
        mi=min(mi,a[i]);
    }
    int cnt1=0,cnt2=0;
    FOR(n){
        cnt1+=(a[i]==ma);
        cnt2+=(a[i]==mi);
    }
    if (cnt1>=2 && cnt2>=2){
        print(2*ma-2*mi);
    }
    else{
        sort(a,a+n);
        print(a[n-1]+a[n-2]-a[0]-a[1]);
    }
}
void precompute(){
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(15);
    precompute();
    int t=1;
    cin>>t;
    while (t--)
    {
        solve();
    }
}
