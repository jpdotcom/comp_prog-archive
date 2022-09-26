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

double l,v1,v2,k;
void solve(){
    cin>>n>>l>>v1>>v2>>k;
    double left=0;
    double right=l;
    int times=100;
    double ans=l/v1;
    while (left<=right && times--){
        double m= left+(right-left)/2;
        double t=m/v2;
        double curr_right=m;
        double curr_left=t*v1;
        for (int i=k+1;i<=n;i+=k){
            if (curr_left==l){
                break;
            }
            double add=(curr_right-curr_left)/(v1+v2);
            t+=add;
            curr_left+=v1*add;
            curr_left=min(curr_left, l);
            curr_right+=v1*add;
            curr_right=min(curr_right,l);
            double add2 =(curr_right-curr_left)/(v2-v1);
            t+=add2;
            curr_left+=v1*add2;
            curr_right+=v1*add2;
            curr_left=min(curr_left,l);
            curr_right=min(curr_right,l);
        }
        t+=(l-curr_right)/v1;
        if (ans>=t){
            ans=t;
        }
        if (curr_right!=l){
            left=m;
        }
        else{
            right=m;
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
    while (t--){
        solve();
    }


}
