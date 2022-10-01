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
bool c(pi a1,pi a2){
    return a2.F-a2.S>a1.F-a1.S;
}
void solve(){
    int n;
    cin>>n;
    int a1,a2,a3;
    a1=a2=a3=0;
    FOR(n){
        int val;
        cin>>val;
        a1+=(modu(val,4)==1);
        a2+=(modu(val,4)==2);
        a3+=(modu(val,4)==3);
    }
    if (modu(a1*1+a2*2+a3*3,4)!=0){
        print(-1);
        return;
    }
    int ans=0;
    ans+=a2/2;
    a2=modu(a2,2);
    int m=min(a1,a3);
    ans+=m;
    a1-=m;
    a3-=m;
    if (a2==0){
        ans+=3*(a1+a3)/4;
    }
    else{
        ans+=(2+3*(a1+a3-2)/4);
    }
    print(ans);
}

void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(30);
    precompute();
    //fileIO("paintbarn");
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }
}
