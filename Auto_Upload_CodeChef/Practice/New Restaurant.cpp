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
const ll maxN=1e6+5;
const ll mm=(ll)1e9+7;
ll fac[maxN];
ll dp[1005][1005];
ll inv(ll a){
    return power(a,mm-2,mm);
}
ll nCr(ll a,ll b){
    return fac[a]*inv(fac[b])%mm*inv(fac[a-b])%mm;
}
void solve(){
    ll n,m,k;
    cin>>n>>m>>k;
    ll ans=0;
    FOR(min(m,k)+1){
        ans=modu(ans+modu(nCr(m,i)*dp[n][i],mm),mm);
    }
    print(ans);
}
void precompute(){
    fac[0]=1;
    for (ll i=1;i<maxN;i++){
        fac[i]=modu(fac[i-1]*i,mm);
    }
    
    FOR(1005){
        for (ll j=0;j<1005;j++){
            if (i==0 && j==0) dp[i][j]=1;
            else if (i==0 && j!=0) dp[i][j]=0;
            else{
                dp[i][j]+=modu(j*dp[i-1][j],mm);
                if (j!=0) dp[i][j]+=modu(j*dp[i-1][j-1],mm);
                dp[i][j]=modu(dp[i][j],mm);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    precompute();
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }
}
