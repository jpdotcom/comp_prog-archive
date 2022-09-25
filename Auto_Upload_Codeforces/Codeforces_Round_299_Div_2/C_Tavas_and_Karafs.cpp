#include <bits/stdc++.h>
#define FOR(b) for (int i=0;i<b;i++)
#define endl '\n';
#define F first
#define S second 
#define mp make_pair
#define print(x) cout<<x<<'\n'
#define pb push_back 
typedef std::vector<long long> vi;
typedef std::pair<long long, long long> pi;
typedef long long ll;
using namespace std;
ll modu(ll a,ll b){
    return (b+(a%b)) % b;
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
void precompute(){
}
ll get_sum(ll a,ll b,ll n){
    return (2*a+ (n-1) * b)*n/2;
}
void solve(){
    ll a,b,n;
    cin>>a>>b>>n;
    FOR(n){
        ll l,t,m;
        cin>>l>>t>>m;
        ll sl=(l==1 ? 0: get_sum(a,b,l-1));
        ll left=l,right=(t-a)/b+1;
        ll ans=-1;
        while (left<=right){
            ll mid=(left+(right-left)/2);
            if (get_sum(a,b,mid)-sl>t*m || (a+b*(mid-1) > t)){
                right=mid-1;
            }
            else{
                left=mid+1;
                ans=mid;
            }
        }
        print(ans);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(15);
    precompute();
    int t=1;
    while (t--){
        solve();
    }
}

