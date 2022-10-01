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
    int a,b,n; cin>>a>>b>>n;
    int ans=0;
    for (int i=31;i>=0;i--){
        if (((a>>i)&1) != ((b>>i)&1)){
            int val=0;
            for (int j=i;j>=0;j--){
                if ((((a>>j)&1) != ((b>>j)&1)) && (val+(1<<j)<n)){
                    val+=1<<j;
                }
            }
            if (val<(1<<i)){
                print(-1);
                return;
            }
            else{
                ans++;
                a^=(val);
            }
        }
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
