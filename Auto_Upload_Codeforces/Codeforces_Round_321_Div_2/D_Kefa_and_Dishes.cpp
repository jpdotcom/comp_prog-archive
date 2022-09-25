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
const int maxN=3e5+1;
const int maxD=19;
ll dp[maxN][18];
void solve(){
	int n,m,k; cin>>n>>m>>k;

	vector<int> vals;
	vector<vector<int>>match(n+1,vector<int>(n+1,0));
	int end=(1<<n);
	FOR(n){
		int v; cin>>v; vals.push_back(v);
	}
	FOR(k){
		int a,b,val; cin>>a>>b>>val;
		match[a][b] = val;
	}
	ll ans=0;
	for (int i=0;i<end;i++){
		int cnt=__builtin_popcount(i);
		for (int j=1;j<=n;j++){
			dp[i][j]=0;
			if (bit(i,j-1)){
				dp[i][j]=vals[j-1];
				for (int k=1;k<=n;k++){
					if (k!=j && bit(i,k-1)){
						dp[i][j]=max(dp[i-(1<<(j-1))][k]+vals[j-1]+match[k][j],dp[i][j]);
					}
				}
				if (cnt==m) ans=max(ans,dp[i][j]);
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
    cout.tie(NULL);
    cout<<setprecision(15);
    precompute();
    int t=1;
    while (t--){
        solve();
    }
}
