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
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define MOD 1e9+7;
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
void solve(){
    int n;
    cin>>n;
    int arr[n];
    vi sarr(n);
    FOR(n){
        cin>>arr[i];
        sarr[i]=arr[i];
    }
    sort(sarr.begin(),sarr.end());
    int idx=n-1;
    for (int i=n-1;i>0;i-=2){
        int v1=sarr[idx];
        int v2=sarr[idx-1];
        if (arr[i]!=v1 || arr[i-1]!=v2){
            swap(v1,v2);
            if (arr[i]!=v1||arr[i-1]!=v2){
                print("NO");
                return;
            }
        }
        idx-=2;
    }
    print("YES");
}
void precompute(){
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(30);
    precompute();
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }
}
