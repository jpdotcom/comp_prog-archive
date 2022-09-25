#include <bits/stdc++.h>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
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

ll power(ll x, ll y, ll p)
{
    long long res = 1;     // Initialize result
 
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
double eval(double x,double y, double z, int a, int b,int c){
    return a*log2(x)+b*log2(y)+c*log2(z);
}
const int maxS=4e6+5;
int pb[maxS];
void solve()
{
    int m,x;
    cin>>n>>m;
    int arr1[n];
    int arr2[m];
    FOR(n){
        cin>>arr1[i];
    }
    FOR(m){
        cin>>arr2[i];
    }
    cin>>x;
    for (int i=0;i<n;i++){
        int s=0;
        for (int j=i;j<n;j++){
            s+=arr1[j];
            pb[s]=max(pb[s],j-i+1);
        }
    }
    for (int i=1;i<maxS;i++){
        pb[i]=max(pb[i],pb[i-1]);
    }
    int ans=0;
    for (int i=0;i<m;i++){
        int s=0;
        for (int j=i;j<m;j++){
            s+=arr2[j];
            ans=max(ans,(j-i+1)*(pb[min(x/s,maxS-1)]));
        }
    }
    print(ans);
}
                
            
void precompute(){
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(30);
    precompute();
    int t=1;
    while (t--){
        solve();
    }
}
