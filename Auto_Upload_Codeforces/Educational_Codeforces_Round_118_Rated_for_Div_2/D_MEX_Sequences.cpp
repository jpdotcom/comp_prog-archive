#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<long long> vi;
typedef std::pair<int,int> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define endl '\n'
#define print(x) cout<<x<<'\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18)
#define all(a) (a).begin(), (a).end()
#define MOD ((ll)998244353)
using namespace std;
using namespace __gnu_pbds;
const int maxN=5e5+100;
ll dp1[maxN];
ll dp2[maxN];
ll stagger[maxN][2];
ll a[maxN];
map<ll,ll> cnt;
map<ll,ll> cnt2;
ll binpow(ll a, ll b){
    if (b==0) return 1;
    ll val=binpow(a,b/2);
    if (b&1) return val*val%MOD*a%MOD;
    else return val*val%MOD;
}
void solve(){
    cnt.clear();
    cnt2.clear();
    int n; cin>>n;
    ll ones=0;
    FOR(n){
        cin>>a[i];
        ones+=a[i]==1;
    }
    ll ans=binpow(2,ones)-1;
    for (int i=0;i<n;i++){
        dp1[i]=0;
        dp1[i]+=cnt[a[i]]+cnt[a[i]-1];
        if (a[i]==0) dp1[i]++;
        dp1[i]%=MOD;
        cnt[a[i]]+=dp1[i];
        cnt[a[i]]%=MOD;
        ans+=dp1[i];
        ans%=MOD;
    }
    cnt.clear();
    for (int i=n-1;~i;i--){
        for (int j=0;j<2;j++){
            int v=(j ? 2: -2);
            if (j==0){
                stagger[i][j]=1+cnt[a[i]]+cnt2[a[i]+v];
                cnt[a[i]]+=stagger[i][j];
                cnt[a[i]]%=MOD;
            }
            else{
                stagger[i][j]=1+cnt[a[i]+v]+cnt2[a[i]];
                cnt2[a[i]]+=stagger[i][j];
                cnt2[a[i]]%=MOD;
            }
        }
    }
    cnt.clear();
    for (int j=n-1;~j;j--){
        dp2[j]=dp1[j]*cnt[a[j]+2];
        dp2[j]%=MOD;
        cnt[a[j]]+=stagger[j][0];
        cnt[a[j]]%=MOD;
        ans+=dp2[j];
        ans%=MOD;
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
