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
    int n;
    cin>>n;
    int v1=0,v2=0;
    FOR(n){
        int val;
        cin>>val;
        if (val==1) v1++;
        else v2++;
    }
    bool ok=false;
    for (int i=-1;i<=1;i+=2){
        for (int j=-1;j<=1;j+=2){
            vector<int>arr(n);
            arr[0]=i;
            arr[1]=j;
            int c1=0,c2=0;
            for (int k=2;k<n;k++){
                arr[k]=-1*arr[k-2];
            }
            for (int k=0;k<n;k++){
                if (arr[k]==1) c1++;
                else c2++;
            }
            if (c1==v1 && c2==v2){
                ok=true;
            }
        }
    }
    if (ok) print("YES");
    else print("NO");
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
