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
const int maxN=1005;
int mi[maxN][maxN];
int ma[maxN][maxN];
int arr[maxN][maxN];
void solve(){
    int n,m;
    cin>>n>>m;
    FOR(maxN){
        ma[0][i]=ma[i][0]=-1e9;
        mi[0][i]=mi[i][0]=1e9;
    }
    FOR(n){
        for (int j=0;j<m;j++){
            cin>>arr[i][j];
            ma[i+1][j+1]=arr[i][j]+max(ma[i][j+1],ma[i+1][j]);
            mi[i+1][j+1]=arr[i][j]+min(mi[i][j+1],mi[i+1][j]);
            if (i==0 && j==0){
                ma[i+1][j+1]=mi[i+1][j+1]=arr[i][j];
            }
        }
    }
    if ((n+m-1) % 2 == 1){
        print("NO");
        return;
    }
    if (mi[n][m]<=0 && 0<=ma[n][m]) print("YES");
    else print("NO");

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
