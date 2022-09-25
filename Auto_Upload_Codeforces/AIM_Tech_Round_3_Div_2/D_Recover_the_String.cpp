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
ll find_num(int n){
    ll ans=-1;
    ll l=0;
    ll r=2*n;
    while (l<=r){
        ll m=l+(r-l)/2;
        if (m*(m-1)==2*n){
            ans=m;
            break;
        }
        else if (m*(m-1)>2*n)
            r=m-1;
        else
            l=m+1;
    }
    return ans;

}
void solve()
{
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll num_0=find_num(a);
    ll num_1=find_num(d);
    if (num_0 == -1 || num_1==-1){
        print("Impossible");
        return;
    }
    if (num_0==0){
        if (b!=0 || c!=0){
            num_0=1;
        }
    }
    if (num_1==0){
        if (b!=0 || c!=0){
            num_1=1;
        }
    }
    if (num_0+num_1==0){
        print("0");
    }
    ll comb=num_0*num_1;
    char arr[num_0+num_1];
    for (int i=0;i<num_0+num_1;i++){
        if (i<num_0)
            arr[i]='0';
        else
            arr[i]='1';
    }
    if ((b+c)!=comb){
        print("Impossible");
        return;
    }
    ll left_idx=0;
    ll right_idx=num_0;
    ll curr_b=comb;
    ll curr_c=0;
    while (curr_b!=b){
        if (curr_b-(right_idx-left_idx)>b){
            arr[left_idx]='1';
            arr[right_idx]='0';
            curr_b-=(right_idx-left_idx);
            curr_c+=right_idx-left_idx;
            left_idx++;
            right_idx++;
        }
        else{
            arr[right_idx]='0';
            arr[b+right_idx-curr_b]='1';
            break;
        }
    }
    for (char x:arr){
        cout<<x;
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
