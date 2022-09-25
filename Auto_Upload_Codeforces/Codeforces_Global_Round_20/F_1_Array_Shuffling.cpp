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
const int maxN=1e6+1;
int idx[maxN];
int a[maxN];
bool comp(vector<int> a, vector<int> b){
	return (b.size()<a.size());
}
void solve(){
	int n; cin>>n;
	vector<vector<int>> vals;
	FOR(n+1) idx[i]=-1;
	FOR(n){
		int v; cin>>v;
		a[i]=v;
		if (idx[v]==-1){
			idx[v]=vals.size();
			vi add; add.pb(i);
			vals.pb(add);
		}
		else vals[idx[v]].pb(i);
	}
	sort(vals.begin(),vals.end(),comp);
	int sz=vals[0].size();
	vector<int> b(n);
	for (int i=0;i<sz;i++){
		vi push;
		for (int j=0;j<vals.size() && vals[j].size()>0;j++){
			push.push_back(vals[j][vals[j].size()-1]);
			vals[j].pop_back();
		}
		for (int j=0;j<push.size();j++){
			b[push[j]]=a[push[(j+1)%push.size()]];
		}
	}
	for (int x: b) cout<<x<<' ';
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
    cin>>t;
    while (t--){
        solve();
    }
}
