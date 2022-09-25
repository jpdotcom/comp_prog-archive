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
const int maxN=1e6+1;
int prefix[maxN];
int arr[maxN];
bool seen[maxN];
void solve(){
    int n,c;
    cin>>n>>c;
    FOR(n){
        cin>>arr[i];
        seen[arr[i]]=true;
        prefix[arr[i]]++;
    }
    bool ok = true;
    for (int i=1;i<=c;i++) prefix[i]+=prefix[i-1];
    for (int i=1;i<=c;i++){
        for (int j=1;i*j<=c;j++){
            if (!seen[i] && seen[j]){
                int v1=i*j-1;
                int v2=min((i+1)*j-1,c);
                if (prefix[v2]-prefix[v1]>0){
                    ok=false;
                }
            }
        }
    }
    FOR(c+1){
        seen[i]=false;
        prefix[i]=0;
    }
    if (ok) print("Yes");
    else print("No");
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
