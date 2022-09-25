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
const int maxNN=1e6+5;
ll prefix[maxN];
ll p[maxN];
ll arr[maxN];
map<ll,ll> cnt;
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    cnt.clear();
    FOR(maxN){
        prefix[i]=0;
        p[i]=0;
        arr[i]=0;
    }
    FOR(n){
        arr[i+1]=s[i]-'0';
        prefix[i+1]=prefix[i]+arr[i+1];
    }
    FOR(n){
        p[i+1]=i+1-prefix[i+1];
        if (cnt.find(p[i+1]) == cnt.end()) cnt[p[i+1]]=0;
        cnt[p[i+1]]++;
    }
    ll ans=0;
    FOR(n){
        if (i!=0) cnt[p[i]]--;
        ll val=i+1-prefix[i]-1;
        ll c=((cnt.find(val)==cnt.end()) ? 0 : cnt[val]);
        ans+=c;
    }
    print(ans);
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    precompute();
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }
}
