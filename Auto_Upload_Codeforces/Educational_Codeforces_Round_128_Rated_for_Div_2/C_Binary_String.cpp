#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
const int maxN=2e5+5;
int arr[maxN];
int c0[maxN];
int c1[maxN];
void solve(){
    int n;
    string s; cin>>s;
    n=s.size();
    c0[0]=c1[0]=0;
    FOR((int) s.size()){
        arr[i]=s[i]-48;
        c0[i+1]=c0[i]+(arr[i]==0);
        c1[i+1]=c1[i]+(arr[i]==1);
    }
    int n1=0,n0=c0[n];
    int ans=n0;
    for (int i=n;i>=0;i--){
        if (i==0) ans=min(max(n0,n1),ans);
        else{
            int r=i-1;
            int l=0;
            int nn0=n0,nn1=n1;
            ans=min(max(nn0,nn1),ans);
            while (l<=r){
                int m=l+(r-l)/2;
                if (nn1+c1[m+1]<=nn0-c0[m+1]){
                    ans=min(nn0-c0[m+1],ans);
                    l=m+1;
                }
                else r=m-1;
            }
            n1+=(arr[i-1]==1);
            n0-=(arr[i-1]==0);
        }
    }
    print(ans);
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
