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
#define INF ((int)1e9+7)
#define MOD ((ll)1e9+7)
using namespace std;
using namespace __gnu_pbds;
const int maxN=5001;
int dp[maxN][maxN];
int trace[maxN][maxN];
int T;
int n;
vector<pair<int,int>> adj[maxN];
void solve(){
	int m; cin>>n>>m;
	cin>>T;
	for (int i=0;i<=n;i++){
		for (int j=0;j<=n;j++){
			dp[i][j]=INF;
		}
	}
	FOR(m){
		int a,b,w; cin>>a>>b>>w;
		adj[a].pb(mp(b,w));
	}
	dp[n][1]=0;
	trace[n][1]=-1;
		for (int j=1;j<=n;j++){
			for (int i=1;i<n;i++){
			for (pi a: adj[i]){
				if (dp[a.F][j-1]+a.S<dp[i][j]){
					dp[i][j]=dp[a.F][j-1]+a.S;
					trace[i][j]=a.F;
				}
			}
		}
	}
	int ie=0;
	for (int j=1;j<=n;j++){
		if (dp[1][j]<=T) ie=j;
	}
	print(ie);
	int is=1;
	while (is!=-1){
		cout<<is<<' ';
		is=trace[is][ie--];
	}
	
	cout<<endl;
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
