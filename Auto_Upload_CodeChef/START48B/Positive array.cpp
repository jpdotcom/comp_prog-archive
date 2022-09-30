#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<long long, long long> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1LL)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
using namespace std;
using namespace __gnu_pbds;
const int maxN=1e6+1;
int a[maxN];
void solve(){
    int n; cin>>n;
    FOR(n) cin>>a[i];
    sort(a,a+n);
    int l=1,r=n;
    int ans=0;
    while (l<=r){
        int m=l+(r-l)/2;
        int j=0;
        vi arr[m];
        bool ok=true;
        for (int i=0;i<n;i++,j=(j+1)%m){
            if (a[i]<arr[j].size()+1){
                ok=false;
                break;
            }
            else arr[j].pb(a[i]);
        }
        if (ok){
            ans=m;
            r=m-1;
        }
        else l=m+1;
    }
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
    while (t--){
        solve();
    }
}
