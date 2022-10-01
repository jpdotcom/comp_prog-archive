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
void solve(){
    int n;
    cin>>n;
    ll cnt[n+1][33];
    ll cntz[n+1];
    vi arr(n);
    cntz[0]=0;
    FOR(n){
        cin>>arr[i];
        cntz[i+1]=0;
        if (arr[i]==0) cntz[i+1]=1;
        cntz[i+1]+=cntz[i];
    }
    int q;
    cin>>q;
    FOR(n+1){
        ll val=1;
        for (int j=0;j<33;j++){
            if (i==0){
                cnt[i][j]=0;
            }
            else cnt[i][j]=(arr[i-1]>=val)+cnt[i-1][j];
            val*=2;
        }
    }
    FOR(q){
        int l,r,x;
        cin>>l>>r>>x;
        if (x==0) print(r-l+1-(cntz[r]-cntz[l-1]));
        else{
            int b=(int)log2(x);
            print((r-l+1)-(cnt[r][b]-cnt[r][b+1]-cnt[l-1][b]+cnt[l-1][b+1]));
        }
    }
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
