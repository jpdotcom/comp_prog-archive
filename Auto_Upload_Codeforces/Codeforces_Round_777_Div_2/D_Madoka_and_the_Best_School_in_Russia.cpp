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
bool isPrime(int n){
	bool p=true;
	for (int i=2;i<=(int)sqrt(n);i++){
		p&=(n % i !=0);
	}
	return p;
}
void solve(){
	int n,x; cin>>n>>x;
	int cnt=0;
	while (n%x==0){
		n/=x;
		cnt++;
	}
	if (cnt<=1) print("NO");
	else if (x>=2 && !isPrime(n)){
		 print("YES");
	}
	else if (cnt==2 && isPrime(n)) print("NO");
	else if (cnt>=3 && isPrime(n) && isPrime(x)) print("NO");
	else if (cnt>=4 && !isPrime(x)){
		 print("YES");
	}
	else if (cnt==3 && isPrime(n)){
		int v=x*n;
		vector<int> f;
		int cnt=0;
		for (int i=1;i<=(int)sqrt(v);i++){
			int j=v/i;
			if (i*j==v){
				f.pb(i);
				if (j!=i) f.pb(j);
			}
		}
		sort(f.begin(),f.end());
		for (int i=0,j=f.size()-1;i<=j;i++,j--){
			cnt+=(f[i]%x!=0 && f[j]%x!=0);
		}
		if (cnt) print("YES");
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
    cin>>t;
    while (t--){
        solve();
    }
}

