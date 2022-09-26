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
string s1,s2;
bool eq(int a,int b,int c,int d){
    int idx=c;
    for (int i=a;i<=b;i++){
        if (s1[i]!=s2[idx])
            return false;
        idx++;
    }
    return true;
}

bool e(int a,int b,int c,int d){
    if (eq(a,b,c,d)){
        return true;
    }
    else if ((b-a+1)%2){
        return false;
    }
    else{
        int m1,m2;
        m1=(a+b)/2;
        m2=(c+d)/2;
        return (e(a,m1,c,m2) && e(m1+1,b,m2+1,d)) || (e(a,m1,m2+1,d) && e(m1+1,b,c,m2));
    }
}

void solve()
{
    cin>>s1>>s2;
    int n=s1.size();
    bool equal=e(0,n-1,0,n-1);
    if (equal){
        print("YES");
    }
    else
        print("NO");
    return ;
    
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
