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
const int maxN=2e5+1;
int dp[maxN][3][3];
void solve(){

    int n,m; cin>>n>>m;
    string s; cin>>s;
    FOR(n+1)
        for (int j=0;j<3;j++)
            for (int k=0;k<3;k++)
                dp[i][j][k]=0;
    FOR(n){
        int val=s[i]-'a';
        dp[i+1][(i+1)%3][val]++;
    }
    for (int i=1;i<=n;i++){
        for (int j=0;j<3;j++){
            for (int k=0;k<3;k++){
                dp[i][j][k]+=dp[i-1][j][k];
            }
        }
    }
    FOR(m){
        int a,b; cin>>a>>b;
        if (b-a+1==2) print((s[a-1]==s[b-1]));
        else if (b-a==1) print(0);
        else{
            int v=1e9+1;
            for (int j=0;j<3;j++){
                for (int k=0;k<3;k++){
                    int l=3-j-k;

                    if (j==k || j==l || k==l) continue;
                    v=min(v,b-a+1-dp[b][b%3][j]+dp[a-1][b%3][j]-dp[b][(b-1)%3][k]+dp[a-1][(b-1)%3][k]-dp[b][(b-2)%3][l]+dp[a-1][(b-2)%3][l]);
                }
            }
            print(v);
        }
    }
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    while (t--){
        solve();
    }
     
}
