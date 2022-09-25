#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<long long> vi;
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
int a[maxN];
map<int,int> cnt;
void solve(){
    int n; cin>>n;
    n*=2;
    cnt.clear();
    FOR(n){
        cin>>a[i];
    }
    sort(a,a+n);
    for (int i=0;i<n-1;i++){
        for (int k=0;k<n;k++) cnt[a[k]]++;
        bool ok=true;
        vector<pi> out;
        out.pb(mp(a[i],a[n-1]));
        cnt[a[i]]--;
        cnt[a[n-1]]--;
        int mx_val=a[n-1];
        for (int j=n-2;j>=0;j--){
            if (cnt[a[j]]==0) continue;
            if (!cnt[mx_val-a[j]] || (mx_val-a[j]==a[j] && cnt[a[j]]<2)){
                ok=false;
            }
            else{
                cnt[a[j]]--;
                cnt[mx_val-a[j]]--;
                out.pb(mp(mx_val-a[j],a[j]));
                mx_val=a[j];
            }
        }
        if (ok){
            print("YES");
            cout<<a[n-1]+a[i]<<endl;
            for (pi x: out){
                cout<<x.F<<' '<<x.S<<endl;
            }
            return;
        }
        cnt.clear();
    }
    print("NO");
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
