#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<long long,long long> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
#define endl '\n'
#define MOD ((int)1e9+7)
using namespace std;
const int maxN=2e5+1;
int dp[32];
void solve(){
    int n,x; cin>>n>>x;
    int cntz=0;
    FOR(32){
        dp[i]=0;
        int b1=bit(n,i);
        int b2=bit(x,i);
        if (b2==0){
            if (b1==1){
                dp[i]+=1<<(cntz);
            }
        }
        cntz+=!(b2);
        if (i!=0) dp[i]+=dp[i-1];
        else dp[i]+=1;
    }
    print(dp[31]-1);
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
    while (t--) solve();
}
