#include <bits/stdc++.h>
#define FOR(b) for (int i=0;i<b;i++)
#define endl '\n';
#define F first
#define S second 
#define mp make_pair
#define print(x) cout<<x<<'\n'
#define pb push_back 
#define MOD (ll)1e9+7
typedef std::vector<long long> vi;
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
ll gcd(ll a,ll b){
    if (a>b) swap(a,b);
    if (a==0) return b;
    return gcd(b%a,a);
}
ll lcm(ll a,ll b){
    return (ll) a * (ll) b / gcd(a,b);
}
const int maxN=2e5+5;
pi dp[maxN][2];
int get_cost(int a,int b,int c){
    return (a!=c) + (b!=c);
}
void solve(){
    int n;
    string s;
    cin>>n>>s;
    int arr[n];
    FOR((int)s.size()) arr[i]=s[i]-48;
    dp[0][0]=make_pair(0,1);
    dp[0][1]=make_pair(0,1);
    for (int i=2;i<=n;i+=2){
        for (int j=0;j<2;j++){
            if (dp[i-2][j]<=dp[i-2][j^1]){
                dp[i][j]=dp[i-2][j];
            }
            else{
                dp[i][j]=dp[i-2][j^1];
                dp[i][j].S++;
            }
            dp[i][j].F+=get_cost(arr[i-2],arr[i-1],j);
        }
    }
    pi ans=min(dp[n][0],dp[n][1]);
    cout<<ans.F<<' '<<ans.S<<endl;
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
