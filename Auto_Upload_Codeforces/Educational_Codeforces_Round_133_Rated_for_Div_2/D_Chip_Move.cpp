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
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
#define endl '\n'
#define MOD ((int)998244353)
using namespace std;
void solve(){
    int n,k; cin>>n>>k;
    int end=sqrt(2*n)+1;
    vector<vector<int>> dp(2,vector<int>(n+1,0));
    vector<int> ans(n+1,0);
    dp[0][0]=1;
    for (int j=1,flag=1;j<end;j++,flag^=1){
        for (int i=0;i<=n;i++){
                int jump=j-1+k;
                if (i-jump>=0){
                    dp[flag][i]=(dp[flag][i-jump]+dp[flag^1][i-jump])%MOD;
                }
                else dp[flag][i]=0;
                ans[i]+=dp[flag][i];
                ans[i]%=MOD;
        }
    }
    for (int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    while (t--) solve();
}
