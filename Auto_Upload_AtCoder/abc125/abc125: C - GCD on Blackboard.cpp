#include <bits/stdc++.h>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<int,int> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<pi> pq;
#define endl '\n'
#define F first 
#define S second 
# define PI 3.14159265358979323846
# define print(x) cout<<x<<'\n'
using namespace std;
ll modu(ll a,ll b){
    return (b+(a%b)) % b;
}
ll power(ll x, ll y, ll p)
{
    long long res = 1;     
    x = x % p; 
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1) res=modu(res*x,p);
        y = y>>1; 
        x = modu((x*x),p);
    }
    return res;
}
void fileIO(string filename) {
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
int gcd(int a,int b){
    if (a>b){
        swap(a,b);
    }
    if (a==0) return b;
    return gcd(b%a,a);
}
const int maxN=1e5+5;
int gcdl[maxN];
int gcdr[maxN];
int arr[maxN];
void solve(){
    int n;
    cin>>n;
    FOR(n){
        cin>>arr[i];
        if (i==0) gcdl[i]=arr[i];
        else gcdl[i]=gcd(gcdl[i-1],arr[i]);
    }
    gcdr[n-1]=arr[n-1];
    for (int i=n-2;i>=0;i--){
        gcdr[i]=gcd(gcdr[i+1],arr[i]);
    }
    int ans=max(gcdl[n-2],gcdr[1]);
    for (int i=1;i<n-1;i++){
        ans=max(ans,gcd(gcdr[i+1],gcdl[i-1]));
    }
    print(ans);
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    precompute();
    int t=1;
    while (t--){
        solve();
    }
}
