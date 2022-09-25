#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<int,char> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<int> pq;
#define endl '\n'
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
const int maxN=2e5+1;
ll dp[maxN];
void solve(){
    int n,m; cin>>n>>m;
    ll MOD=m;
    FOR(n+1) dp[i]=0;
    dp[1]=1;
    ll s=1;
    for (int i=2;i<=n;i++){
        dp[i]+=s;
        dp[i]%=MOD;
        int v=2;
        while (v<=i){
            dp[i]+=dp[i/v]*(min(i/(i/v),i)-v+1);
            v=i/(i/v)+1;
            dp[i]%=MOD;
        }
        s+=dp[i];
        s%=MOD;
    }
    print(dp[n]);
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


