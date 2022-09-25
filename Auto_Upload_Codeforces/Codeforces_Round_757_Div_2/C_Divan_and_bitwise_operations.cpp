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
const int mxN=2e5+6;
int a[mxN];
ll c[mxN][30];
void solve(){
    int n,m; cin>>n>>m;
    FOR(n){
        for (int j=0;j<30;j++) c[i][j]=0;
    }
    FOR(m){
        int l,r,k; cin>>l>>r>>k;
        for (int j=0;j<30;j++){
            if (bit(k,j)){
                c[l-1][j]++;
                if (r<n) c[r][j]--;
            }
            else{
                c[l-1][j]-=2e5+10;
                if (r<n) c[r][j]+=2e5+10;
            }
        }
    }
    int ans=0;
    FOR(n){
        int val=0;
        for (int j=0;j<30;j++){
            if (i!=0) c[i][j]+=c[i-1][j];
            if (c[i][j]>0) val+=(1<<j);
        }
        a[i]=val;
        ans|=val;
    }
    print((ans*power(2,n-1,MOD))%MOD);

}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }
     
}
