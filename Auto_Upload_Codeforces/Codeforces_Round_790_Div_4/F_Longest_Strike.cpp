#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define MOD (int)1e9+7
#define iset tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
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
const int maxN=2e5+5;
map<int,int>cnt;
void solve(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    vi a;
    cnt.clear();
    FOR(n){
        cin>>arr[i];
        if (cnt.find(arr[i])==cnt.end()) cnt[arr[i]]=0;
        cnt[arr[i]]++;
    }
    sort(arr,arr+n);
    a.pb(arr[0]);
    for (int i=1;i<=n;i++){
        if (arr[i]!=arr[i-1]) a.pb(arr[i]);
    }
    int la=-1,ra=-1;
    int l=a[0],r=a[0]-1;
    int i=0,j=0;
    while (j<=a.size()){
        if (cnt[a[j]]>=k && a[j]==r+1){
            j++;
            r++;
            if (ra-la<=r-l){
                la=l,ra=r;
            }
        }
        else{
            if (i==j){
                i++;j=i;
                l=a[i],r=a[i]-1;
            }
            else{
                i++;l=a[i];
                if (i==j) r=a[i]-1;
            }
        }
    }
    if (la==-1) print(-1);
    else cout<<la<<' '<<ra<<endl;
}
void precompute(){
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(15);
    precompute();
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }
}
