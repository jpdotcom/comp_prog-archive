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
    double a,b,m;
    double vx,vy,vz;
    cin>>a>>b>>m>>vx>>vy>>vz;
    double x=a/2,y=m,z=0;
    double tt=0;
    while (true){
        pair<double,double> tx1=make_pair((a-x)/vx,1);
        pair<double,double> tx2=make_pair((-1*x)/vx,1);
        pair<double,double> tz1=make_pair((b-z)/vz,3);
        pair<double,double> tz2=make_pair((-1*z)/vz,3);
        pair<double,double> ty1=make_pair((-1*y)/vy,2);
        vector<pair<double,double>> a;
        a.pb(tx1),a.pb(tx2),a.pb(tz1),a.pb(tz2),a.pb(ty1);
        sort(a.begin(),a.end());
        double min_val=-1;
        double epi=1e-7;
        FOR((int)a.size()){
            if (a[i].F>epi && (abs(a[i].F-min_val)<=epi || min_val==-1)){
                tt+=a[i].F;
                if (min_val==-1){
                x=x+vx*a[i].F;
                y=y+vy*a[i].F;
                z=z+vz*a[i].F;
                min_val=a[i].F;
                }
                if (a[i].S==1) vx*=-1;
                else if (a[i].S==2){
                    cout<<x<<' '<<z<<endl;
                    return;
                }
                else vz*=-1;
            }
        }
    }
    
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    precompute();
    //fileIO("paintbarn");
    int t=1;
    while (t--){
        solve();
    }
}
