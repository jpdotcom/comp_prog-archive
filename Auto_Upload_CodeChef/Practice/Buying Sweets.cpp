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
bool c(pi a1,pi a2){
    return a2.F-a2.S>a1.F-a1.S;
}
void solve(){
    int n,p;
    cin>>n>>p;
    pi arr[n];
    FOR(n) cin>>arr[i].F;
    FOR(n) cin>>arr[i].S;
    sort(arr,arr+n,c);
    int ans=0;
    FOR(n){
        int sub=(int)((double)(p-arr[i].F)/(arr[i].F-arr[i].S)+1);
        if (sub>0){
        ans+=sub;
        p-=sub*(arr[i].F-arr[i].S);
        }
    }
    print(ans);
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
