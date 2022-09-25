#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<long long, long long> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<int> pq;
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
vi p;
const int maxN=4e4+1;
int arr[maxN];
ll dp[maxN][505];
void solve(){
    int n;cin>>n;
    print(dp[n][(int)p.size()]);
}
void precompute(){

    for (int i=1;i<maxN;i++){
        string s= to_string(i);
        bool ok=true;
        for (int j=0;j<(int)s.size()/2;j++){
            if (s[j]!=s[(int)s.size()-1-j]) ok=false;
        }
        if (ok) p.pb(i);
    }
    FOR(505) dp[0][i]=1;
    for (int i=1;i<maxN;i++){
        for (int j=1;j<=(int)p.size();j++){
            dp[i][j]=0;
            if (i-p[j-1]>=0){
                dp[i][j]+=dp[i-p[j-1]][j];
            }
            dp[i][j]%=MOD;
            dp[i][j]+=dp[i][j-1];
            dp[i][j]%=MOD;
        }
    }
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
