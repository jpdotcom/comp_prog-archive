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
const int maxN=5005;
int sum[maxN][maxN];
int dp[maxN][maxN];
int arr[maxN];
void solve(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    FOR(n+3)
        for (int j=0;j<n+3;j++){
            dp[i][j]=0;
            sum[i][j]=0;
        }
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            dp[i][j]=(arr[i-1]>arr[j-1]);
        }
    }
    for (int i=1;i<=n;i++)
        for (int j=n;j>=1;j--){
            if (j!=n) dp[i][j]+=dp[i][j+1];
            sum[i][j]=dp[i][j]+sum[i-1][j];
        }
    ll ans=0;
    FOR(n){
        for (int j=i+1;j<n;j++){
            if (arr[i]<arr[j]){
                ans+=sum[j][j+2]-sum[i+1][j+2];
            }
        }
    }
    print(ans);


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
