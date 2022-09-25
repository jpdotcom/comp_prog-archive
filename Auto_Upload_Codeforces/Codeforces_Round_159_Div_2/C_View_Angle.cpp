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
#define PI (long double)3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
#define MOD ((ll)1e9+7)
using namespace std;
using namespace __gnu_pbds;
const int maxN=1e5+1;
long double x[maxN],y[maxN];
long double angles[maxN];
long double eps=5e-8;
set<long double> seen;
void solve(){
	int n; cin>>n;
	vector<long double> angles;
	FOR(n){
		cin>>x[i]>>y[i];
		long double a=atan2l(y[i],x[i]);
		if (seen.find(a)==seen.end()){
			angles.pb(a);
		}
		seen.insert(a);
	}
	sort(angles.begin(),angles.end());
	long double angle=2*PI;
	for (int i=0;i<angles.size();i++){
		double prev=angles[(i-1+angles.size())%angles.size()];
		if (abs(angles[i]-prev)<=eps || prev>angles[i]){
			angle=min(angle,prev-angles[i]);
		}
		else angle=min(angle,2*PI-(angles[i]-prev));
	}
	print(angle*180/PI);
}
void precompute(){
}
int main(){
    cout<<setprecision(15)<<fixed;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    while (t--){
        solve();
    }
}
