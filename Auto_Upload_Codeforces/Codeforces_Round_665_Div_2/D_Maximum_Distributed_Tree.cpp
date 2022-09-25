#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)(b);i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<long long,long long> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((int)1e9)
#define MOD ((ll)1e9+7)
using namespace std;
const int maxN=1e6+1;
vector<ll> scores;
int cnt[maxN];
vi adj[maxN];
int n;
int dfs(int u, int p=-1){
	cnt[u]=1;
	for (int v: adj[u]){
		if (v!=p){
			cnt[u]+=dfs(v,u);
		}
	}
	return cnt[u];

}
void dfs2(int u, int p=-1){
	
	for (int v:adj[u]){
		if (v!=p){
			scores.pb((ll)(n-cnt[v])*cnt[v]);
			dfs2(v,u);
		}
	}
}
void solve(){
    cin>>n;
    FOR(n+1) adj[i].clear();
    scores.clear();
    FOR(n-1){
	int a,b; cin>>a>>b;
	adj[a].pb(b);
	adj[b].pb(a);
    }
    dfs(1);
    dfs2(1);
    int m; cin>>m;
    vector<ll> primes(m);
    FOR(m){
	cin>>primes[i];
    }
    
    if (scores.size()>primes.size()){
	int v=scores.size()-primes.size();
	FOR(v){
	
		primes.pb(1);
	}
    }
    sort(primes.begin(),primes.end());
    sort(scores.begin(),scores.end());
    ll q=0;
    for (int i=0;i<scores.size()-1;i++){
	q+=(primes[i]*scores[i])%MOD;
	q%=MOD;
    }
    ll bigPrime=1;
    for (int i=scores.size()-1;i<primes.size();i++){
	bigPrime*=primes[i];
	bigPrime%=MOD;
    }
    q+=scores[scores.size()-1]*bigPrime%MOD;
    q%=MOD;
    print(q);
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
    while (t--)
    {
        solve();
    }
