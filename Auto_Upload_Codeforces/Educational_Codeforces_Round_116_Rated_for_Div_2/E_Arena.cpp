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
#define INF (1e18+10)
#define all(a) (a).begin(), (a).end()
#define MOD ((ll)998244353)
using namespace std;
using namespace __gnu_pbds;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=505;
ll dp[maxN][maxN];
ll P[maxN][maxN];
ll nCr[maxN][maxN];
void solve(){
    int n,k; cin>>n>>k;
    for (int i=0;i<=k;i++) dp[0][i]=1;
    for (int i=1;i<=n;i++){
        for (int j=0;j<=k;j++){
            dp[i][j]=0;
            for (int surv=0;surv<=i;surv++){
                if (surv==1) continue;
                ll died=i-surv;
                ll pvals=min((ll)i-1,(ll)j);
                dp[i][j]+=(nCr[i][died]*P[pvals][died])%MOD*dp[surv][max(0,j-i+1)]%MOD;
                dp[i][j]%=MOD;
            }
        }
    }
    print(dp[n][k]);
}
void precompute(){

    for (int i=0;i<maxN;i++){
        for (int j=0;j<maxN;j++){
            if (i==0) nCr[i][j]=(j==0);
            else{
                if (j!=0) nCr[i][j]+=nCr[i-1][j-1];
                nCr[i][j]%=MOD;
                nCr[i][j]+=nCr[i-1][j];
                nCr[i][j]%=MOD;
            }
            if (j!=0) P[i][j]=(i*P[i][j-1])%MOD;
            else P[i][j]=1;
        }
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(15);
    precompute();
    int t=1;
    while (t--){
        solve();
        
    }
}
