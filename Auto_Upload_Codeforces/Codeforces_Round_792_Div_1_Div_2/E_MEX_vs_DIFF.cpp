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
#define INF ((ll)1e18+10)
#define all(a) (a).begin(), (a).end()
#define MOD ((ll)1e9+7)
using namespace std;
using namespace __gnu_pbds;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=2e5+1;
int a[maxN];
void solve(){
    int n,k; cin>>n>>k;
    FOR(n) cin>>a[i];
    int l=-1,r=n+1;
    int ans=n;
    while (l<=r){
        int m=l+(r-l)/2;
        map<int,int> cnt;
        FOR(n) cnt[a[i]]++;
        int mex=-1,diff=cnt.size();
        set<int> have;
        for (int i=0;i<=m;i++){
            if (cnt[i]!=0){
                cnt[i]--;
                mex++;
                have.insert(i);
            }
        }
        vector<int> freq;
        for (auto &x: cnt)
            if (have.find(x.F)==have.end() && x.S) freq.pb(x.S);
        sort(freq.begin(),freq.end());
        int s=freq.size();
        for (auto &x: cnt){
            if (have.find(x.F)!=have.end() && x.S) freq.pb(x.S);
        }
        int j=k;
        int idx=0;
        while (j>0 && mex<m && idx<freq.size()){
            freq[idx]--;
            mex++;
            assert(freq[idx]>=0);
            if (!freq[idx]){
                diff-=(idx<s);
                idx++;
            }
            diff++;
            j--;
        }
        while (j>0 && idx<freq.size()){
            freq[idx]--;
            assert(freq[idx]>=0);
            if (!freq[idx]){
                ++idx;
                diff-=(idx<s);
            }
            j--;
        }
        if (mex==m){
            ans=min(ans,diff-mex-1);
            l=m+1;
        }
        else r=m-1;
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
