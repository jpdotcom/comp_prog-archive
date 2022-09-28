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
const int maxN=200005;
int arr1[maxN];
int arr2[maxN];
void solve(){
    int n;
    cin>>n;
    FOR(n) cin>>arr1[i];
    FOR(n) cin>>arr2[i];
    vi mod1(n);
    vi mod2(n);
    int val=1;
    int tot=0;
    for (int k=0;k<30;k++){
        val*=2;
        FOR(n) mod1[i]=modu(arr1[i],val);
        FOR(n) mod2[i]=modu(arr2[i],val);
        sort(mod2.begin(),mod2.end());
        int ans=0;
        FOR(n){
            int a1=lower_bound(mod2.begin(),mod2.end(),val/2-mod1[i])-mod2.begin();
            int a2=upper_bound(mod2.begin(),mod2.end(),val-mod1[i]-1)-mod2.begin()-1;
            ans+=(a2>=a1 ? modu((a2-a1+1),2) : 0);
            int a3=lower_bound(mod2.begin(),mod2.end(),val+val/2-mod1[i])-mod2.begin();
            ans+=modu(n-a3,2);
        }
        if (modu(ans,2)) tot+=val/2;
    }
    print(tot);
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
