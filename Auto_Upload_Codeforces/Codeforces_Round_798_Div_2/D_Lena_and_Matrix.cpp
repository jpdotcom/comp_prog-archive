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
void solve(){
    int n,m;cin>>n>>m;
    int d1,d2,d3,d4;
    d1=d2=d3=d4=-1e9;
    FOR(n){
        for (int j=0;j<m;j++){
            char c;cin>>c;
            if (c=='B'){
                d1=max(d1,j+i+2);
                d2=max(d2,i-j);
                d3=max(d3,j-i);
                d4=max(d4,-1*(j+i+2));
            }
        }
    }
    int dist=1e9;
    int x=0,y=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            int temp_dist=0;
            if (d1-i-j>temp_dist){
                temp_dist=d1-i-j;
            }
            if (d2-i+j>temp_dist){
                temp_dist=d2-i+j;
            }
            if (d3-j+i>temp_dist){
                temp_dist=d3-j+i;
            }
            if (d4+i+j>temp_dist){
                temp_dist=d4+i+j;
            }
            if (temp_dist<dist){
                x=i;
                y=j;
                dist=temp_dist;
            }
        }
    }
    cout<<x<<' '<<y<<endl;
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
