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
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; 
        x = (x*x) % p;
    }
    return res;
}
const int maxN=1e6+5;
ll tree[2*maxN];
int n;
ll dp[maxN][3];
ll arr[maxN];
vector<ll> sarr;
void clear(){
    FOR(2*maxN){
        tree[i]=0;
    }
}
void update(int i,ll val){
    i+=n;
    tree[i]=val;
    i/=2;
    while (i>=1){
        tree[i]=tree[2*i+1]+tree[2*i];
        i/=2;
    }
    return;
}
ll query(int a,int b){
    a+=n,b+=n;
    ll ans=0;
    while (a<=b){
        if (a&1){
            ans+=tree[a];
            a++;
        }
        if ((b&1)==0){
            ans+=tree[b];
            b--;
        }
        a/=2,b/=2;
    }
    return ans;
}
int get_idx(int i){
    return lower_bound(sarr.begin(),sarr.end(),i)-sarr.begin();
}
void solve(){
    cin>>n;
    FOR(n){
        cin>>arr[i];
        sarr.pb(arr[i]);
    }
    sort(sarr.begin(),sarr.end());
    FOR(n){
        dp[i][0]=(ll)1;
    }
    ll ans=0;
    for (int j=1;j<3;j++){
        for (int i=0;i<n;i++){
            int idx=get_idx(arr[i]);
            if (idx+1!=n) dp[i][j]+=query(idx+1,n-1);
            if (j==2) ans+=dp[i][j];
            update(idx,dp[i][j-1]);
        }
        clear();
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
