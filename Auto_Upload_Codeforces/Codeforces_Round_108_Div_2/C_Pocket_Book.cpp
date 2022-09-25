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
int uni[105][105];
void solve(){
    int n,m;
    cin>>n>>m;
    string arr[n];
    FOR(n) cin>>arr[i];
    for (int i=0;i<m;i++){
        for (int j=i;j<m;j++){
            set<string>seen;
            for (int k=0;k<n;k++){
                string curr=arr[k].substr(i,j-i+1);
                if (seen.find(curr)==seen.end()){
                    seen.insert(curr);
                }
            }
            uni[i][j]=seen.size();
        }
    }
    ll ans=1;
    for (int i=0;i<m;i++){
        ans*=uni[i][i];
        ans=modu(ans,1e9+7);
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
    while (t--){
        solve();
    }
}
