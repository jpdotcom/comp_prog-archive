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
const int maxN=2e5+1;
ll pos[maxN];
ll power[maxN];
pair<long long,long long> intersect(long long a, long long b, ll c, ll d){
	long double tx=max(a+b,c+d);
	long double ty=max(b-a,d-c);
	return make_pair((tx-ty)/2.0,(tx+ty)/2.0);
}
void solve(){
	ll n,m; cin>>n>>m;
	m*=2;
	vector<pair<ll,ll>> diffs;
	FOR(n){
		cin>>pos[i]>>power[i];
		pos[i]*=2,power[i]*=2;
		diffs.pb(mp(pos[i]-power[i],1));
		diffs.pb(mp(pos[i],-2));
		diffs.pb(mp(pos[i]+power[i],1));
	}
	sort(diffs.begin(),diffs.end());
	ll cx=INF,cy=INF;
	ll a=0, prev_pos=diffs[0].F,d=0;
	for (auto p: diffs){
		if (p.F!=prev_pos){
			a+=(p.F-prev_pos)*d;
			prev_pos=p.F;
			if (a>m){
				if (cx==INF){
					cx=p.F,cy=a-m;
				}
				else{
					pair<ll,ll> nc=intersect(cx,cy,p.F,a-m);
					cx=nc.F,cy=nc.S;
				}
			}
		}
		d+=p.S;
	}
	string out(n,'1');
	if (cx!=INF){
		FOR(n){
			pi cc=intersect(cx,cy,pos[i],power[i]);
			if (cc.F==pos[i] && cc.S==power[i]) out[i]='1';
			else out[i]='0';
		}
	}
	cout<<out<<endl;
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
