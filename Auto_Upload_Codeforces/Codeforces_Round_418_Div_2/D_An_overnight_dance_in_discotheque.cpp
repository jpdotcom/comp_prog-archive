#include <bits/stdc++.h>
#define FOR(a,b) for (int i=a;i<b;++i)
typedef std::pair<long long, long long> pi;
typedef long long ll;
#define F first 
#define S second 
# define PI 3.14159265358979323846
using namespace std;
ll modu(ll a,ll b){
    return (b+(a%b)) % b;}
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
    return res;}
const int N = 1e5;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}

const int maxN=1005;
vector<int>adj[maxN];
bool seen[maxN];
ll radius[maxN];
ll sum=0;
void dfs(int depth,int u, int p){
    if (depth==0 || depth==1){
        sum+=pow(radius[u],2);
    }
    else{
        ((depth%2==1) ? (sum+=pow(radius[u],2)) : sum-=pow(radius[u],2));
    }
    for (int v:adj[u]){
        if (v!=p){
            dfs(depth+1,v,u);
        }
    }
    return;
}
bool insideof(ll x1,ll y1,ll r1,ll x2,ll y2,ll r2){
    return (pow((x2-x1),2)+pow(y2-y1,2)<r1*r1) && (r1>r2);
}
void solve(){
    cin>>n;
    int arr[n][2];
    for (int i=0;i<n;i++){
        cin>>arr[i][0];
        cin>>arr[i][1];
        cin>>radius[i];
    }
    vector<int>roots;
    for (int i=0;i<n;i++){
        ll x1,y1,x2,y2,r1,r2;
        x1=arr[i][0],y1=arr[i][1],x2=-1,y2=-1,r2=-1,r1=radius[i];
        int v=-1;
        for (int j=0;j<n;j++){
            if (i==j){
                continue;
            }
            if (insideof(arr[j][0],arr[j][1],radius[j],x1,y1,r1)){
                if (v==-1){
                    x2=arr[j][0];
                    y2=arr[j][1];
                    r2=radius[j];
                    v=j;
                }
                else{
                    if (insideof(x2,y2,r2,arr[j][0],arr[j][1],radius[j])){
                        x2=arr[j][0];
                        y2=arr[j][1];
                        r2=radius[j];
                        v=j;
                    }
                }
            }
        }
        if (v!=-1){
            adj[v].push_back(i);
            adj[i].push_back(v);
        }
        else{
            roots.push_back(i);
        }
    }
    ll ans=0;
    while (roots.size()!=0){
        int u=roots.back();
        roots.pop_back();
        sum=0;
        dfs(0,u,-1);
        ans+=sum;
    }
    cout<<ans*PI;
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
