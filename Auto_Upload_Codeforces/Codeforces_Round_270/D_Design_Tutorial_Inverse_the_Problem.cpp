#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef long long ll;
typedef std::pair<ll,ll> pi;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define INF (1000000009)
#define MOD ((ll)1e9+7)
using namespace std;
using namespace __gnu_pbds;
const int maxN=2005;
vector<pi> adj[maxN];
int dist[maxN][maxN];
int seen[maxN];
int ndist[maxN][maxN];
struct Edge{
	int x,y,w;
};
bool comp(Edge e1, Edge e2){
	return e2.w>=e1.w;
}
void bfs(int r){
	queue<int> q;
	q.push(r);
	ndist[r][r]=0;
	while (q.size()){
		int u=q.front();
		q.pop();
		for (pair<int,int> v:adj[u]){
			if (ndist[r][u]+v.S<ndist[r][v.F]){
				ndist[r][v.F]=v.S+ndist[r][u];
				q.push(v.F);
			}
		}
	}
}
void solve(){
	int n; cin>>n;
	priority_queue<pair<int,pair<int,int>>> q;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			cin>>dist[i+1][j+1];
			ndist[i+1][j+1]=INF;
		}
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (dist[i+1][j+1]!=dist[j+1][i+1]){
				print("NO");
				return;
			}
		}
	}
	q.push(mp(0,mp(1,-1)));
	while (q.size()){
		pair<int,pair<int,int>> t=q.top();
		q.pop();
		if (!seen[t.S.F]){
			if (t.S.S!=-1){
				adj[t.S.S].pb(mp(t.S.F,-1*t.F));
				adj[t.S.F].pb(mp(t.S.S,-1*t.F));
			}
			seen[t.S.F]=1;
			for (int i=1;i<=n;i++){
				if (!seen[i]) q.push(mp(-1*dist[t.S.F][i],mp(i,t.S.F)));
			}
		}
	}
	bool ok=true;
	for (int i=1;i<=n;i++){
		bfs(i);
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			ok&=(dist[i][j]==ndist[i][j]);
			ok&=(i==j || ndist[i][j]>0);
		}
	}
	if (ok) print("YES");
	else print("NO");
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
