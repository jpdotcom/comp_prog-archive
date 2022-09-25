#include <bits/stdc++.h>
#define pb push_back
#define FOR(a,b) for (int i=a;i<b;i++)
typedef std::vector<long long> vi;
typedef std::pair<long long, long long> pi;
typedef long long ll;
#define endl '\n'
#define F first 
#define S second 
# define PI 3.14159265358979323846
# define print(x) cout<<x<<'\n'
using namespace std;
ll modu(ll a,ll b){
    return (b+(a%b)) % b;
}

ll root(ll x) {
	ll l = 0, r = 1e9 + 1;
	while (l < r - 1) {
		ll m = (l + r) / 2;
		if (m * m > x)
			r = m;
		else
			l = m;
	}
	return l;
}

int power(long long x, unsigned int y, ll p)
{
    unsigned long long res = 1;     // Initialize result
 
    x = x % p; // Update x if it is more than or
                // equal to p
  
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

const int N = 5;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}
const int maxN=2005;
vi adj[maxN];
ll arr[maxN];
ll valid_paths(int i,int u, int d,int p){
    if (arr[u]<arr[i] || (arr[i]==arr[u] && u<i) || arr[u]>arr[i]+d){
        return 0;
    }
    ll ans=1;
    for (int v:adj[u]){
        if (v==p) continue;
        ans*=(modu(valid_paths(i,v,d,u)+1,1e9+7));
        ans=modu(ans,1e9+7);
    }
    return ans;
}
void solve(){
    int n,d;
    cin>>d>>n;
    for (int i=1;i<n+1;i++){
        cin>>arr[i];
    }
    for (int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b),adj[b].pb(a);
    }
    ll ans=0;
    for (int i=1;i<n+1;i++){
        ans=modu(ans+valid_paths(i,i,d,-1),1e9+7);
    }
    print(ans);
}
void precompute(){
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(15);
    precompute();
    int t=1;
    while (t--){
        solve();
    }


}
