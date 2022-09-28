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
const int maxN=1e5+5;
ll arr[maxN];
ll T[maxN];
void solve(){
    int n;
    cin>>n;
    FOR(n){
        ll val;
        cin>>val;
        arr[i]=((ll)1)<<val;
        T[i]=val;
    }
    for (int i=1;i<n;i++){
        if (arr[i]<=arr[i-1]){
            ll k=(ll)((arr[i-1]-arr[i])/pow(2,T[i]+1) + 1);
            arr[i]+=k*pow(2,T[i]+1);
        }
    }
    print(arr[n-1]);
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
