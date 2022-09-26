#include <bits/stdc++.h>
#define pb push_back
#define FOR(b) for (int i=0;i<b;i++)
typedef std::vector<int> vi;
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
const int maxN=1e5+5;
ll p[maxN];
ll cnt[maxN];
ll edges[maxN][3];
double c;
vector<pi> adj[maxN];
long double get_sum(ll u,ll v,ll w){
    if (p[v]==u){
        return (w)/c*(cnt[v]*(n-cnt[v]));
    }
    else{
        return w/c*(cnt[u]*(n-cnt[u]));
    }

}
ll NCR(ll n, ll r)
{
    if (r == 0) return 1;

    /*
     Extra computation saving for large R,
     using property:
     N choose R = N choose (N-R)
    */
    if (r > n / 2) return NCR(n, n - r); 

    ll res = 1; 

    for (int k = 1; k <= r; ++k)
    {
        res *= n - k + 1;
        res /= k;
    }

    return res;
}
int dfs(int u,int parent){
    p[u]=parent;
    cnt[u]=1;
    for (pi x:adj[u]){
        int v=x.F;
        if (parent!=v){
        
            cnt[u]+=dfs(v,u);
        }
    }
    return cnt[u];
}
void solve(){
    cin>>n;

    FOR(n-1){
        ll a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
        edges[i][0]=a;
        edges[i][1]=b;
        edges[i][2]=c;
    }

    c=NCR(n,3);
    dfs(1,-1);
    long double s=0;
    for (int i=1;i<=n;i++){
        for (pi p:adj[i]){
            if (i<p.F){
            s+=get_sum(i,p.F,p.S);
            }
        }
    }
    int q;
    cin>>q;
    FOR(q){
        int j;
        int nw;
        cin>>j>>nw;
        j--;
        s-=get_sum(edges[j][0],edges[j][1],edges[j][2]);
        edges[j][2]=nw;
        s+=get_sum(edges[j][0],edges[j][1],edges[j][2]);
        print(s*(n-2));
    }
}
void precompute(){
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(30);
    precompute();
    int t=1;
    FOR(t){
        solve();
    }
}
