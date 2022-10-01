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
const int maxN=8005;
ll dp[maxN][maxN];
const ll mm=1e9+7;
int a[8001];
void solve(){
    int n,k;
    cin>>n>>k;
    FOR(n){
        int val;
        cin>>val;
        a[val]++;
    }
    for (int i=0;i<=8000;i++){
        for (int j=0;j<=min(k,8000);j++){
            dp[i][j]=0;
            if (i==0 && j==0) dp[i][j]=1;
            else if (i==0) dp[i][j]=0;
            else{
                dp[i][j]+=modu(dp[i-1][j],mm);
                if (j!=0) dp[i][j]+=modu(a[i-1]*dp[i-1][j-1],mm);
                dp[i][j]=modu(dp[i][j],mm);
            }
        }
    }
    ll ans=0;
    FOR(min(k,8000)+1){
        ans+=dp[8000][i];
        ans=modu(ans,mm);
    }
    print(ans);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(25);
    precompute();
    int t=1;
    while (t--){
        solve();
    }
}

