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
const int maxN=500000;
int arr[maxN];
void solve()
{
    int a1,a2,k;
    cin>>n>>k;
    double avg=0;
    FOR(n){
        cin>>arr[i];
        avg+=arr[i];
    }

    sort(arr,arr+n);
    avg/=n;
    int l,r;
    l=arr[0];
    r=avg;
    while (l<=r){
        ll m=l+(r-l)/2;
        ll curr_val=arr[0];
        ll days=0;
        ll f=0;
        FOR(n){
            if (arr[i]>=m){
                days+=(m-curr_val)*f;
                break;
            }
            else{
                if (curr_val==arr[i]){
                    f++;
                }
                else{
                    days+=(arr[i]-curr_val)*f;
                    curr_val=arr[i];
                    f++;
                }
            }
        }
            if (days<=k){
                a1=m;
                l=m+1;
            }
            else{
                r=m-1;
            }
            
        
    }

    l=((int) avg == avg ? avg : avg+1);
    r=arr[n-1];
    while (l<=r){
        ll m=l+(r-l)/2;
        ll curr_val=arr[n-1];
        ll days=0;
        ll f=0;
        for (int i=n-1;i>-1;i--){
            if (arr[i]<=m){
                days+=(curr_val-m)*f;
                break;
            }
            else{
                if (curr_val==arr[i]){
                    f++;
                }
                else{
                    days+=(curr_val-arr[i])*f;
                    curr_val=arr[i];
                    f++;
                }
            }
        }
            if (days<=k){
                a2=m;
                r=m-1;
            }
            else{
                l=m+1;
            }
            
        
    }
    print(a2-a1);
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
