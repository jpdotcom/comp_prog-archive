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
int get_val(int v1,int v2){
    int times=max((int)ceil((2*v1-v2)/3.0),0);
    return times+ceil((v2-times)/2.0);
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
    int m1=sarr[0];
    int m2=sarr[1];
    int ans=ceil(m1/2.0)+ceil(m2/2.0);
    FOR(n-1){
        int v1=arr[i];
        int v2=arr[i+1];
        if (v1>v2) swap(v1,v2);
        ans=min(ans,get_val(v1,v2));
    }
    for (int i=1;i<n-1;i++){
        int v1=arr[i-1];
        int v2=arr[i+1];
        if (v1>v2) swap(v1,v2);
        int temp=0;
        temp+=v1;
        v2-=temp;
        if (v2!=0) temp+=ceil(v2/2.0);
        ans=min(ans,temp);
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
    int t=1;
    while (t--){
        solve();
    }
}
