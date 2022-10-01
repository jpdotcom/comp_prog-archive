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
const int maxN=2005;
pi arr[maxN];
double dist(double x,int n,double A,double B, double C){
    double y=-1*(C+A*x)/B;
    double ans=0;
    FOR(n){
        ans+=sqrt(pow(x-arr[i].F,2)+pow(y-arr[i].S,2));
    }
    return ans;
}
void solve(){
    int n;
    double A,B,C;
    cin>>n;
    cin>>A>>B>>C;
    FOR(n){
        int a,b;
        cin>>a>>b;
        arr[i].F=a,arr[i].S=b;
    }
    double l=-10000,r=10000;
    FOR(100){
        double c1=(2*l+r)/3;
        double c2=(l+2*r)/3;
        if (dist(c1,n,A,B,C)<dist(c2,n,A,B,C)) r=c2;
        else l=c1;
    }
    print(dist((l+r)/2,n,A,B,C));
}
void precompute(){
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(30);
    precompute();
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }
}
