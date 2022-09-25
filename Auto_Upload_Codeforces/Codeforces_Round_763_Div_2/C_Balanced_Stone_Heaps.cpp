#include <bits/stdc++.h>
#define FOR(b) for (int i=0;i<b;i++)
#define endl '\n';
#define F first
#define S second 
#define mp make_pair
#define print(x) cout<<x<<'\n'
#define pb push_back 
#define MOD (ll)1e9+7
typedef std::vector<int> vi;
typedef std::pair<long long, long long> pi;
typedef long long ll;
using namespace std;
ll modu(ll a,ll b){
    return (b+(a%b)) % b;
}
ll power(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    if (x == 0) return 0; 
 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; 
        x = (x*x) % p;
    }
    return res;
}
const int maxN=2e5+1;
int arr[maxN];
bool check(vi &a,int m){
    int n=a.size();
    vi e(a.size());
    FOR(n) e[i]=a[i];
    for (int i=n-1;i>=2;i--){
        int d=min(e[i]/3,(a[i]-m)/3);
        if (d>0){
            a[i-1]+=d;
            a[i-2]+=2*d;
        }
    }
    FOR(n){
        if (a[i]<m) return false;
    }
    return true;
}
void solve(){
    int n; cin>>n;
    FOR(n) cin>>arr[i];
    int ans=0;
    int l=0,r=1e9+1;
    while (l<=r){
        int m=l+(r-l)/2;
        vi a(n);
        FOR(n) a[i]=arr[i];
        if (check(a,m)){
            l=m+1;
            ans=m;
        }
        else r=m-1;
    }
    print(ans);

}

void precompute(){
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
