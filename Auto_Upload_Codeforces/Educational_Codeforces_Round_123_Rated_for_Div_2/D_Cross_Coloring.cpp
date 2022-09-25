#include <bits/stdc++.h>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<long long, long long> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
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
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; 
        x = (x*x) % p;
    }
    return res;
}
const int N = 200005;  // limit for array size
int intersect(int a,int b,int c,int d){
    return max(0,min(b,d)-max(a,c)+1);
}

void solve()
{
    int n,m,k,q;
    cin>>n>>m>>k>>q;
    int cols[m];
    int rows[n];
    int qu[q][2];
    ll ans=1,mo=998244353;
    FOR(q){
        cin>>qu[i][0];
        cin>>qu[i][1];
    }
    FOR(n) rows[i]=-1;
    FOR(m) cols[i]=-1;
    int rows_cov=0;
    int cols_cov=0;
    for (int i=q-1;i>-1;i--){
        int a=qu[i][0],b=qu[i][1];
        a--,b--;
        if (cols_cov==m||rows_cov==n){
            break;
        }
        if (rows[a]<i || cols[b]<i){
            ans*=k;
            ans=modu(ans,mo);
        }
        if (rows[a]<i){
           rows_cov++;
           rows[a]=i;
        }
        if (cols[b]<i){
            cols_cov++;
            cols[b]=i;
        }
    }
    print(ans);
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    precompute();
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }
}
