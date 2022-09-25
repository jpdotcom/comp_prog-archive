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
int a[maxN];
void solve(){
	int n,k;  cin>>n>>k;
	int mx=0;
	FOR(n){
		 cin>>a[i];
		 mx=max(mx,a[i]);
	} 
	sort(a,a+n);
	int ans=1;
	for (int i=1;i<=mx;i++){
		int sidx=0;
		for (int j=i;j<=mx;j+=i){
			if (sidx<n && a[sidx]>=j){
			int i1=lower_bound(a+sidx,a+n,j+k+1)-a;
			sidx=i1;
			}
		}
		if (sidx==n) ans=max(ans,i);
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
