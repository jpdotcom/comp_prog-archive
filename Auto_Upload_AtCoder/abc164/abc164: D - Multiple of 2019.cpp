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
int gcd(int a,int b){
    if (a>b){
        swap(a,b);
    }
    if (a==0) return b;
    return gcd(b%a,a);
}
const int maxN=1e6;
int mod[maxN];
int arr[maxN];
map<int,int>cnt;
void solve(){
    string s;
    cin>>s;
    int n=s.length();
    FOR(n){
        int val=s[i]-'0';
        arr[n-1-i]=val;
    }
    mod[0]=modu(arr[0],2019);
    cnt[mod[0]]=1;
    for (int i=1;i<n;i++){
        mod[i]=modu(mod[i-1]+arr[i]*power(10,i,2019),2019);
        if (cnt.find(mod[i])==cnt.end()) cnt[mod[i]]=0;
        cnt[mod[i]]++;
    }
    cnt[0]++;
    ll ans=0;
    for (int i=n-1;i>=0;i--){
        cnt[mod[i]]--;
        ans+=cnt[mod[i]];
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
    while (t--){
        solve();
    }
}
