#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(a) for(int i=0;i<a;i++)
#define mp(a,b) make_pair(a,b)
#define all(a)  a.begin(),a.end()
typedef std::vector<long  long> vi;
typedef std::pair<int,int> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>(s))&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+10)
#define MOD ((ll)998244353)
using namespace std;
using u64 = uint64_t;
using u128 = __uint128_t;
void solve(){
    int n; cin>>n;
    string a;
    string b;
    cin>>a>>b;
    int eq=0;
    FOR(n) eq+=(a[i]==b[i]);
    if (eq!=n && eq!=0){
        print("NO");
        return;
    }
    int ans=0;
    vector<pair<int,int>> tot;
    if (!eq) tot.pb({1,n});
    a=b;
    int cnt=0;
    for (int i=0;i<n;i++){
        if (a[i]=='1'){
            tot.pb({i+1,i+1});
            cnt+=(i!=0);
        }

    }
    int c=(b[0]-'0');
    if (cnt&1) c^=1;
    if (c){
        tot.pb({1,1});
        tot.pb({2,n});
        tot.pb({1,n});
    }
    print("YES");
    print(tot.size());
    for (auto x: tot) cout<<x.F<<' '<<x.S<<endl;

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
    int i=1;
    cin>>t;
    while (t--)
    {
        solve();
        ++i;
    }
}
