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
ll dp[30005][800];
int d;
int c[30005];
void solve(){
    cin>>n>>d;
    FOR(n){
        int val;
        cin>>val;
        c[val]++;
    }
    n=30000;
    for (int i=n;i>=0;i--){
        for (int j=0;j<800;j++){
            dp[i][j]=c[i];
            int main_dist=d-400+j;
            
            int dist1,dist2,dist3;
            dist1=main_dist-1;
            dist2=main_dist;
            dist3=main_dist+1;
                if (j!=0 && dist1+i<=n && dist1+i>i){
                    dp[i][j]=max(dp[i][j],c[i]+dp[dist1+i][j-1]);
                }
                if (dist2+i<=n && dist2+i>i){
                    dp[i][j]=max(dp[i][j],c[i]+dp[dist2+i][j]);
                }
                if (j!=799 && dist3+i<=n && dist3+i>i){
                    dp[i][j]=max(dp[i][j],c[i]+dp[dist3+i][j+1]);
                }
        }
    }
    print(dp[d][400]);
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
