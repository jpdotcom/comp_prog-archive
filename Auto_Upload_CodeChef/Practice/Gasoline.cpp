#include <bits/stdc++.h>
#define FOR(b) for (int i=0;i<b;i++)
#define endl '\n';
#define F first
#define S second 
#define mp make_pair
#define print(x) cout<<x<<'\n'
#define pb push_back 
typedef std::vector<long long> vi;
typedef std::pair<long long, long long> pi;
typedef long long ll;
using namespace std;
ll modu(ll a,ll b){
    return (b+(a%b)) % b;
}
ll power(long long x, ll y, ll p)
{
    if (y==0) return 1;
    ll val=power(x,y/2,p);
    if (y&1) return x*val % p * val % p;
    else return val*val % p;
}
const int maxN=2e5+1;
pi arr[maxN];
void solve(){
    int n;
    cin>>n;
    FOR(n) cin>>arr[i].S;
    FOR(n) cin>>arr[i].F;
    sort(arr,arr+n);
    int val=n;
    int curr=0;
    ll ans=0;
    while (val){
        if (arr[curr].S){
            arr[curr].S--;
            val--;
            ans+=(ll)arr[curr].F;
        }
        else{
            curr++;
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

