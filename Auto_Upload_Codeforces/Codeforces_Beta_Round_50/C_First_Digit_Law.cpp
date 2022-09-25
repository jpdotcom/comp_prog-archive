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
const int maxN=1005;
double dp[maxN][maxN];
ll intersect(ll a,ll b,ll c,ll d){
    return max((ll) 0,min(b,d)-max(a,c)+1);
}
void solve(){
    int k;
    cin>>n;
    double ones[n];
    ll arr[n][2];
    FOR(n){
        cin>>arr[i][0];
        cin>>arr[i][1];
    }
    FOR(n){
        ll a=arr[i][0];
        ll b=arr[i][1];
        ones[i]=0;
        for (int j=0;j<=18;j++){
            ones[i]+=intersect(a,b,pow(10,j),2*pow(10,j)-1)/(b-a+1.0);
        }
    }
    cin>>k;
    double ans=0;
    for (int i=0;i<=n;i++){
        for (int j=0;j<=n;j++){
            dp[i][j]=0.0;
            if (i==0 && j==0){
                dp[i][j]=1.0;
            }
            if (j>i){
                continue;
            }
            if (j!=0 && i!=0){
                dp[i][j]+=dp[i-1][j-1]*ones[i-1];
            }
            if (i!=0){
                dp[i][j]+= (1-ones[i-1])*dp[i-1][j];
            }
            if (i==n && k*n/100.0<=j){
                ans+=dp[i][j];
            }
        }
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
    FOR(t){
        solve();
    }
}
