#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<long long> vi;
typedef long long ll;
typedef std::pair<int,int> pi;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define endl '\n'
#define print(x) cout<<x<<'\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e9+1)
#define all(a) (a).begin(), (a).end()
#define MOD ((ll)1e9+7)

using namespace std::chrono;
using namespace std;
using namespace __gnu_pbds;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=1e6+1;
int a[maxN];
int n;
ll need(vector<int> &cnt){
    ll ans=0;
    for (int i=0;i<n;i++){
        ll temp=INF;
        for (int j=0;j<=cnt[0];j++){
            for (int k=0;k<=cnt[1];k++){
                int v=j+2*k;
                if (a[i]>=v && (a[i]-v)%3==0){
                    temp=min(temp,(a[i]-v)/3LL);
                }
            }
        }
        ans=max(ans,temp);
    }
    return ans;
}
void solve(){
    cin>>n;
    ll ans=INF;
    FOR(n) cin>>a[i];
    vector<int> cnt(2,0);
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            cnt[0]=i,cnt[1]=j;
            ans=min(ans,i+j+need(cnt));
        }
    }
    print(ans);
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
    while (t--){
        solve();
    }
}
