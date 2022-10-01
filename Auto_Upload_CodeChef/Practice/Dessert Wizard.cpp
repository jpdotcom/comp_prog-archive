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
const int maxN=10005;
ll r[maxN];
ll l[maxN];
ll a[maxN];
void solve(){
    int n;
    cin>>n;
    FOR(n) cin>>a[i];
    l[0]=a[0];
    for (int i=1;i<n;i++){
        l[i]=min(l[i-1]+a[i],a[i]);
    }
    r[n-1]=a[n-1];
    for (int i=n-2;i>=0;i--){
        r[i]=max(r[i+1]+a[i],a[i]);
    }
    for (int i=1;i<n;i++) l[i]=min(l[i],l[i-1]);
    for (int i=n-2;i>=0;i--) r[i]=max(r[i],r[i+1]);
    ll ans=-1*1e18;
    for (int i=1;i<n;i++){
        ans=max(ans,abs(r[i]-l[i-1]));
    }
    for (int i=1;i<n;i++){
        l[i]=max(l[i-1]+a[i],a[i]);
    }
    for (int i=n-2;i>=0;i--){
        r[i]=min(r[i+1]+a[i],a[i]);
    }
    for (int i=1;i<n;i++){
        ans=max(abs(l[i-1]-r[i]),ans);
    }
    print(ans);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(25);
    precompute();
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }
}

