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
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
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
const int maxN=1e6+5;
int col[maxN];
int row[maxN];
int ans[maxN];
int arr[maxN];
void solve(){
    int n,m;
    string s;
    cin>>n>>m;
    cin>>s;
    FOR(n*m) arr[i]=s[i]-48; 
    FOR(n*m) row[i]=col[i]=ans[i]=0;
    FOR(n*m){
        if (col[i%m]==0 && arr[i]==1){
            col[i%m]=1;
            ans[i]=1;
        }
        if (i!=0) ans[i]+=ans[i-1];
    }
    queue<int> q;
    int cnt1=0;
    FOR(m){
        q.push(arr[i]);
        cnt1+=arr[i];
        ans[i]+=(cnt1>0);
        row[i]=(cnt1>0);
    }
    for (int i=m;i<n*m;i++){
        int val=q.front();
        q.pop();
        cnt1-=val;
        q.push(arr[i]);
        cnt1+=arr[i];
        row[i]=(cnt1>0)+row[i-m];
        ans[i]+=row[i];
    }
    FOR(n*m) cout<<ans[i]<<' ';
    cout<<endl;
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
