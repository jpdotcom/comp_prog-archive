#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<long long> vi;
typedef std::pair<int,int> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<int> pq;
#define endl '\n'
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define MOD (int)(1e9+7)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
ll modu(ll a,ll b){
    return (b+(a%b)) % b;
}
ll power(ll a, ll b, ll p){
    ll ans=1;
    a%=p;  
    while(b){
        if(b&1)
            ans=(ans*a)%p;
        b/=2;
        a=(a*a)%p;
    }
    return ans;
}
void fileIO(string filename) {
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
const int maxN=50001;
pi arr[5][maxN];
int r[5][maxN];
bool sup(int a, int b){
    int v=0;
    FOR(5)
        v+=(r[i][a]<r[i][b]);
    return (v>=3);
}
void solve() {
    int n; cin>>n;
    FOR(n){
        for (int j=0;j<5;j++){
            int v; cin>>v;
            arr[j][i]=make_pair(v,i);
        }
    }
    FOR(5){
        sort(arr[i],arr[i]+n);
        for (int j=0;j<n;j++){
            r[i][arr[i][j].S]=j;
        }
    }
    int i=0,j=1;
    while (j<n){
        if (sup(i,j)) j++;
        else{
            i=j;
            j++;
        }
    }
    int ans=i;
    FOR(n){
        if (ans!=i && !sup(ans,i)){
            print(-1);
            return;
        }
    }
    print(ans+1);
}


void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    int i=0;
    cin>>t;
    while (t--){
        solve();
    }
     
}
