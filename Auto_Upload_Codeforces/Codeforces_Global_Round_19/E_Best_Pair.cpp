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
#define INF ((ll)1e18+7)
#define MOD ((ll)1e9+7)
using namespace std;
using namespace __gnu_pbds;
map<ll,ll> cnt;
set<pi> seen;
bool comp(ll a, ll b){
	return a>=b;
}
void solve(){
	int n,m; cin>>n>>m;
	cnt.clear(),seen.clear();
	FOR(n){
		ll v; cin>>v;
		cnt[v]++;
	}
	vector<vector<int>> cntof(n+1);
	for (auto it: cnt){
		cntof[it.S].pb(it.F);
	}
	for (auto &x: cntof){
		sort(x.begin(),x.end(),comp);
	}
	ll ans=0;
	FOR(m){
		int x,y; cin>>x>>y;
		seen.insert(mp(x,y));
		seen.insert(mp(y,x));
	}
	for (int i=1;i<=n;i++){
		for (int x: cntof[i]){
			for (int j=1;j<=i;j++){
				int idx=0;
				while (idx<cntof[j].size() && (cntof[j][idx]==x || seen.find(mp(x,cntof[j][idx]))!=seen.end())) idx++;
				if (idx<cntof[j].size()) ans=max(ans,(ll)(j+i)*(ll)(x+cntof[j][idx]));
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
    cin>>t;
    while (t--){
        solve();
    }
}
