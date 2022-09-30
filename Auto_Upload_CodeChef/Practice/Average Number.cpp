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
bool c(pair<ll,ll> a1,pair<ll,ll> a2){
    return a1.S*a2.F>a1.F*a2.S;
}
void solve(){
    int s=0;
    double n,k,v;
    cin>>n>>k>>v;
    FOR(n){
        double val;
        cin>>val;
        s+=val;
    }
    double ans=((v*(n+k)-s)/k);
    if (ans!=(int)ans || ans<=0) print(-1);
    else print(ans);
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(30);
    precompute();
    //fileIO("paintbarn");
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }
}
