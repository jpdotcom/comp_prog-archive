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
#define INF ((ll)1e18)
#define all(a) (a).begin(), (a).end()
#define MOD ((ll)1e9+7)

using namespace std::chrono;
using namespace std;
using namespace __gnu_pbds;
//using u64 = uint64_t;
//using u128 = __uint128_t;
const int maxN=2005;
int dp[maxN][maxN];
void solve()
{
    string s; cin>>s;
    int n=s.size();
    for (int i=0;i+1<n;i++){
        dp[i][i+1]=s[i]!=s[i+1];
    }
    for (int i=n-4;i>=0;i--){
        for (int j=i+3;j<n;j+=2){
            int v1=-1,v2=-1;
            dp[i][j]=-1;
            v1=max(min(dp[i+1][j-1],dp[i+2][j]),v1);
            if (v1==0){
                char c1=s[i];
                char c2=(dp[i+1][j-1]==0  && dp[i+2][j]==0 ? max(s[i+1],s[j]) : !(dp[i+1][j-1]) ? s[j] : s[i+1]);
                if (c2>c1) dp[i][j]=max(dp[i][j],-1);
                else if (c1>c2) dp[i][j]=1;
                else dp[i][j]=max(dp[i][j],0);
            }
            else dp[i][j]=max(dp[i][j],v1);
            v2=max(min(dp[i+1][j-1],dp[i][j-2]),v1);
            if (v2==0){
                char c1=s[j];
                char c2=(dp[i+1][j-1]==0 && dp[i][j-2] == 0 ? max(s[j-1],s[i]) : !(dp[i+1][j-1]) ? s[i] : s[j-1]);
                if (c2>c1) dp[i][j]=max(dp[i][j],-1);
                else if (c1>c2) dp[i][j]=1;
                else dp[i][j]=max(dp[i][j],0);
            }
            else dp[i][j]=max(dp[i][j],v2);
        }
    }
    if (dp[0][n-1]==-1) print("Bob");
    else if (!dp[0][n-1]) print("Draw");
    else print("Alice");
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
