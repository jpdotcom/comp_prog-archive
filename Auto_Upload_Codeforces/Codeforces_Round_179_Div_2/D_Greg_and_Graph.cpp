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
        if (y & 1)
        y = y>>1; 
        x = (x*x) % p;
    }
    return res;
}
const int maxN=505;
ll adj[maxN][maxN];
ll dp[maxN][maxN];
void solve(){
    int n;
    cin>>n;
    bool seen[n+1];
    ll INF=1e18;
    vector<ll> out;
    for (int i=0;i<maxN;i++){
        for (int j=0;j<maxN;j++){
            if (i!=j){
                dp[i][j]=INF;
            }
            else{
                dp[i][i]=0;
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin>>adj[i][j];
            dp[i][j]=adj[i][j];
        }
    }
    int arr[n];
    FOR(n){
        cin>>arr[i];
        seen[i+1]=false;
    }
    for (int x=n-1;x>=0;x--){
        int k=arr[x];
        seen[k]=true;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
        ll s=0;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (seen[i] && seen[j]){
                    s+=dp[i][j];
                }
            }
        }
        out.pb(s);
    }
    while (out.size()){
        ll ans=out.back();
        out.pop_back();
        cout<<ans<<' ';
    }
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
