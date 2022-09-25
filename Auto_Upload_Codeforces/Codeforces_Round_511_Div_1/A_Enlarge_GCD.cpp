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
const int maxA=2e7+1;
const int maxN=3e5+1;
int primes[maxA];
map<int,int> cnt;
int a[maxN];
int gcd(int a, int b){
	if (a>b) swap(a,b);
	if (a==0) return b;
	return gcd(b%a,a);
}
set<int> get_primes(int n){
	set<int> vals;
	while (n>1){
		vals.insert(primes[n]);
		n/=primes[n];
	}
	return vals;
}
void solve(){
	int n; cin>>n;
	int g=0;
	FOR(n){
		cin>>a[i];
		g=gcd(a[i],g);
	}
	FOR(n){
		 a[i]/=g;
	}
	set<int> tot;
	cnt.clear();
	FOR(n){
		set<int> add=get_primes(a[i]);
		for (auto x: add){
			 tot.insert(x);
			 cnt[x]++;
		}
	}
	
	
	int ans=n;
	for (auto x: tot){
		ans=min(ans,n-cnt[x]);
	}
	if (ans==n) print(-1);
	else print(ans);
	
}
void precompute(){
	FOR(maxA) primes[i]=i;
	for (int i=2;i<=(int)sqrt(maxA);i++){
		if (primes[i]==i){
			for (int j=i*i;j<maxA;j+=i){
				primes[j]=i;
			}
		}
	}
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
