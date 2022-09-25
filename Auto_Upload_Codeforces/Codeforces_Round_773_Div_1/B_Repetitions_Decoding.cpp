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
const int maxN=505;
int a[maxN];
map<int,int> cnt;
void solve(){
	cnt.clear();
	int n; cin>>n;
	FOR(n) cin>>a[i];
	FOR(n) cnt[a[i]]^=1;
	for (auto &it : cnt){
		if (it.S&1){
			print(-1);
			return;
		}
	}
	vector<int> curr(n);
	FOR(n) curr[i]=a[i];
	int prev=0;
	vector<pair<int,int>> q;
	vi out;
	while (curr.size()){
		int idx=0;
		for (int i=1;i<curr.size();i++){
			if (curr[i]==curr[0]){
				idx = i;
				break;
			}
		}
		for (int j=1;j<idx;j++){
			q.pb(make_pair(idx+prev+j,curr[j]));
		}
		out.pb(2*idx);
		prev+=2*idx;
		vi new_curr;
		for (int i=1;i<idx;i++) new_curr.pb(curr[i]);
		reverse(new_curr.begin(),new_curr.end()); 
		for (int i=idx+1;i<curr.size();i++) new_curr.pb(curr[i]);
		curr=new_curr;
	}
	print(q.size());
	for (auto x: q){
		cout<<x.F<<' '<<x.S<<endl;
	}
	print(out.size());
	for (int x: out) cout<<x<<' ';
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
