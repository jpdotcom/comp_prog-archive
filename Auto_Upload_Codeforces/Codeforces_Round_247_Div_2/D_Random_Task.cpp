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
ll nChoosek( ll n, ll k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    ll result = n;
    for( ll i = 2; i <= k; ++i ) {
        result *=  (n-i+1);
        result /=  i;
    }
    return result;
}
ll b(ll X){
    return (ll)log2(X)+1;
}
ll F(ll X,ll k){
    ll n=b(X)+1;
    ll C[n][k+1];
    for (int i=0;i<n;i++){
        for (int j=0;j<=k;j++){
            C[i][j]=0;
            if (!i){
                if (!j) C[i][j]=1;
                else C[i][j]=0;
            }
            else{
                if ((X>>(i-1)) & 1){
                    C[i][j]+=nChoosek(i-1,j);
                    if (j) C[i][j]+=C[i-1][j-1];
                }
                else C[i][j]+=C[i-1][j];
            }
        }
    }
    return C[n-1][k];
}
void solve(){
    ll m,k;
    cin>>m>>k;
    ll l=1,r=1e18;
    while (l<=r){
        ll mid=l+(r-l)/2;
        ll a=F(2*mid,k)-F(mid,k);
        if (a==m){
            print(mid);
            return;
        }
        if (a>m) r=mid-1;
        else l=mid+1;
    }
    return;
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    precompute();
    //fileIO("paintbarn");
    int t=1;
    while (t--){
        solve();
    }
}
