#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<long long, long long> pi;
typedef long long ll;
typedef std::priority_queue<int> pq;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((int)1e9+7)
using namespace std;
using namespace __gnu_pbds;
const int maxN=105;
int a[maxN];
int dp[maxN][maxN*2000];
void solve(){
    int n; cin>>n;
    int s=0;
    int idx=-1;
    FOR(n){
        cin>>a[i];
        s+=a[i];
        if (a[i]&1) idx=i;
    }
    if (s&1) print(0);
    else{
        dp[0][0]=1;
        for (int i=1;i<=n;i++){
            for (int j=0;j<=n*2000;j++){
                dp[i][j]=false;
                dp[i][j]|=dp[i-1][j];
                if (j>=a[i-1]) dp[i][j]|=dp[i-1][j-a[i-1]];
            }
        }
        if (dp[n][s/2]){
            int g=0;
            FOR(n) g=gcd(g,a[i]);
            FOR(n){
                if ((a[i]/g)&1){
                    cout<<1<<endl<<i+1;
                    return;
                }
            }
        }
        else cout<<0<<endl;
    }
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(15);
    precompute();
    int t=1;
    while (t--){
        solve();
    }
}


