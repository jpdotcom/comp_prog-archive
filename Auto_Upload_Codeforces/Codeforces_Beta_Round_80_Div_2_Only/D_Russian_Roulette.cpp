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
void solve(){
    ll n,k,p;
    cin>>n>>k>>p;
    FOR(p){
        ll j;
        cin>>j;
        if ((n&1)==1){
            if (k>0 && ((j==n) || ((j&1)==0 && k>=2 && j>=(n-1-2*(k-2))) || (j>=2*(n-k)+1 && (j&1)==1 && (k>(n+1)/2)))) cout<<'X';
            else cout<<'.';
        }
        else{
            if (k>0 && (((j&1)==0 && j>=(n-2*(k-1))) || (j>=(2*(n-k)) && (j&1)==1 && (k>=n/2+1)))) cout<<'X';
            else cout<<'.';
        }
        
    }
    return;
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
