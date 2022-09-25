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
int l=20;
int up[maxN][20];
int depth[maxN];
int timer=1;
int tin[maxN];
int tout[maxN];
vi adj[maxN];
void dfs(int u, int p,int d=0){
	tin[u]=timer++;
	up[u][0]=p;
	depth[u]=d;
	for (int i=1;i<l;i++){
		up[u][i]=up[up[u][i-1]][i-1];
	}
	for (int v:adj[u]){
		if (v!=p) dfs(v,u,d+1);
	}
	tout[u]=timer++;
}

bool ancestor(int u,int v){
	return tin[u]<=tin[v] && tout[v]<=tout[u];
}
int ancestorof(int u, int v){
	if (ancestor(u,v)) return u;
	if (ancestor(v,u)) return v;
	for (int i=l-1;~i;i--){
		if (!ancestor(up[u][i],v)) u=up[u][i];
	}
	return up[u][0];
}
void solve(){
	int n; cin>>n;
	FOR(n-1){
		int a,b; cin>>a>>b; adj[a].pb(b),adj[b].pb(a);
	}
	int q; cin>>q;
	dfs(1,1);
	FOR(q){
		int k; cin>>k;
		vector<pair<int,int>> nodes(k);
		for(int j=0;j<k;j++){
			cin>>nodes[j].S;
			nodes[j].F=depth[nodes[j].S];
		}
		sort(nodes.begin(),nodes.end());
		int v1=nodes[k-1].S,v2=-1;
		for (int j=k-2;j>=0;j--){
			if (!ancestor(nodes[j].S,v1)){
				v2=nodes[j].S;
				break;
			}
		}
		if (v2==-1){
			print("YES");
			continue;
		}
		bool fok=true;
		int LCA=ancestorof(v1,v2);
		for (int j=k-1;j>=0;j--){
			fok&=(ancestor(LCA,nodes[j].S) && (ancestor(nodes[j].S,v1) || ancestor(nodes[j].S,v2)));
		}
		if (fok) print("YES");
		else print("NO");
	}

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
