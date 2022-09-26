#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<int,int> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<pi> pq;
#define endl '\n'
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define MOD (int)1e9+7
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
ll modu(ll a,ll b){
    return (b+(a%b)) % b;
}
ll power(ll x, ll y, ll p)
{
    ll res = 1;     
    x = x % p; 
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1) res=modu(res*x,p);
        y = y>>1; 
        x = modu((x*x),p);
    }
    return res;
}
void fileIO(string filename) {
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
const int maxN=2e5+5;
int dp[maxN][2][2];
string arr[2];
void solve(){
    int n;
    cin>>n;
    cin>>arr[0];
    cin>>arr[1];
    dp[0][0][0]=0;
    dp[0][0][1]=0;
    dp[0][1][0]=0;
    dp[0][1][1]=1;
    bool contains=(arr[0][0]=='*'||arr[1][0]=='*');
    for (int i=1;i<n;i++){
        for (int j=0;j<2;j++){
            for (int k=0;k<2;k++){
                if (j==0 && k==0){
                    dp[i][j][k]=dp[i-1][arr[0][i-1]=='*'][arr[1][i-1]=='*'];
                }
                if (j==0 && k==1){
                    dp[i][j][k]=min(1+dp[i-1][arr[0][i-1]=='*'][1],2+dp[i-1][1][arr[1][i-1]=='*']);
                    if (!contains) dp[i][j][k]=0;
                }
                if (j==1 && k==0){
                    dp[i][j][k]=min(1+dp[i-1][1][arr[1][i-1]=='*'],2+dp[i-1][arr[0][i-1]=='*'][1]);
                    if (!contains) dp[i][j][k]=0;
                }
                if (j==1 && k==1){
                    dp[i][j][k]=(contains ? 2 : 1)+min(dp[i-1][1][arr[1][i-1]=='*'],dp[i-1][arr[0][i-1]=='*'][1]);
                }
            }
        }
        contains|=arr[0][i]=='*';
        contains|=arr[1][i]=='*';
    }
    print(dp[n-1][arr[0][n-1]=='*'][arr[1][n-1]=='*']);
}
void precompute(){
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(15);
    precompute();
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }
}
