#include <bits/stdc++.h>
#define FOR(b) for (int i=0;i<b;i++)
#define endl '\n';
#define F first
#define S second 
#define mp make_pair
#define print(x) cout<<x<<'\n'
#define pb push_back 
typedef std::vector<long long> vi;
typedef std::pair<long long, long long> pi;
typedef long long ll;
using namespace std;


ll modu(ll a,ll b){
    return (b+(a%b)) % b;
}

int power(long long x, unsigned int y, ll p)
{
    unsigned long long res = 1;     // Initialize result
 
    x = x % p; // Update x if it is more than or
                // equal to p
 
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;}
const int N=1e5;
int n;
ll gcd(ll a, ll b){
    if (a>b){
        swap(a,b);
    }
    if (a==0){
        return b;
    }
    return gcd(b%a,a);
}
ll l(ll a,ll b){
    return a*b/gcd(a,b);
}
void precompute(){
}

void solve()
{
    int m;
    cin>>n>>m;
    ll lcm=1;
    int mat[n][m];
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            int val;
            cin>>val;
            mat[i][j]=val;
            lcm=l(lcm,val);
        }
    }
    int s=0;
    for (int i=0;i<n;i++){
        s=(i&1);
        for (int j=0;j<m;j++){
            if (s){
                cout<<lcm+pow(mat[i][j],4)<<' ';
            }
            else cout<<lcm<<' ';
            s^=1;
        }
        print("");
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(15);
    precompute();
    int t=1;
    while (t--){
        solve();
    }
}

