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
void solve(){
    int n; cin>>n;
    int arr[n+1];
    int v=0;
    FOR(n+1){
        cin>>arr[i];
        v^=arr[i];
    }
    if ((n&1)==0){
        v=arr[0];
        for (int i=1;i<n+1;i++){
            cout<<(v^arr[i])<<' ';
        }
        cout<<endl;
        return;
    }
    bool foundv=0;
    for (int i=0;i<n+1;i++){
        if (v==arr[i] && !foundv) foundv=true;
        else cout<<(v^arr[i])<<' ';
    }
    cout<<endl;
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
