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
void solve(){
	ll a[3];
	FOR(3) cin>>a[i];
	bool ok=false;
	if ((a[1]-(a[2]-a[1]))%a[0]==0 && (a[1]-(a[2]-a[1])>0)) ok=true;
	
	if ((a[1]+(a[1]-a[0]))%a[2]==0 && (a[1]+(a[1]-a[0])>0)) ok=true;
	if (((a[2]-a[0])&1)==0  && (a[2]-(a[2]-a[0])/2)%a[1]==0 && (a[2]-(a[2]-a[0])/2)>0) ok=true;
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
    cin>>t;
    while (t--){
        solve();
    }
}
