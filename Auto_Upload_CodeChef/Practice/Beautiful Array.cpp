#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<int,int> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
#define MOD ((ll)1e9+7)
using namespace std;
using namespace __gnu_pbds;
const int maxN=1e4+1;
ll dp[maxN][20];
int a[maxN];
ll gcd(ll a, ll b){
	if (a>b) swap(a,b);
	if (a==0) return b;
	return gcd(b%a,a);
}
void solve(){
	int n; cin>>n;
	FOR(n) cin>>a[i];
	FOR(20){
		dp[0][i]=1<<abs(i-10);
	}
	for (int i=1;i<n;i++){
		for (ll j=0;j<20;j++){
			dp[i][j]=INF;
			for(int k=0;k<20;k++){
				if (a[i]>=j-10 && a[i-1]>=k-10 && gcd(a[i]-(j-10),a[i-1]-(k-10))==1){
					dp[i][j]=min(dp[i][j],(1LL<<abs(j-10))+dp[i-1][k]);
				}
			}
		}
	}
	ll ans=INF;
	for (int i=0;i<20;i++) ans=min(ans,dp[n-1][i]);
	print((ans%MOD));
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
