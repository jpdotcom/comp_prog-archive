#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<int,int> pi;
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
int length;
vi o;
void out(int x1,int y1,int x2,int y2){
    if (x1!=x2){
        o.pb(x1);
        o.pb(y1);
        o.pb(x2);
        o.pb(y1);
    }
    if (y1!=y2){
        o.pb(x2);
        o.pb(y1);
        o.pb(x2);
        o.pb(y2);
    }
}
int get_dist(pi a,pi b){
    int x1=a.F,y1=a.S,x2=b.F,y2=b.S;
    return abs(x1-x2)+abs(y1-y2);
}
void solve(){
    int x[3];
    int y[3];
    pi arr[3];
    FOR(3){
        cin>>x[i]>>y[i];
        arr[i].F=x[i],arr[i].S=y[i];
    }
    sort(x,x+3),sort(y,y+3);
    out(arr[0].F,arr[0].S,x[1],y[1]);
    out(arr[1].F,arr[1].S,x[1],y[1]);
    out(arr[2].F,arr[2].S,x[1],y[1]);
    print(o.size()/4);
    length=0;
    for (int i=0;i<=o.size()-4;i+=4){
        for (int j=0;j<4;j++){
            cout<<o[i+j]<<' ';
        }
        cout<<endl;
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
    while (t--){
        solve();
    }
}
