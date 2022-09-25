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
const int maxN=2505;
ll dp[505][505][21];
int row[505][505];
int col[505][505];
int n,m;
void solve(){
    int l; cin>>n>>m>>l;
    for (int i=0;i<n;i++){
        for (int j=0;j<m-1;j++){
            int v; cin>>v;
            col[i][j]=v;
        }
    }
    for (int i=0;i<n-1;i++){
        for (int j=0;j<m;j++){
            int v;cin>>v;
            row[i][j]=v;
        }
    }
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            dp[i][j][0]=0;

    for (int k=1;k<21;k++){
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
                dp[i][j][k]=INF;
                if (i<n-1) dp[i][j][k]=min(dp[i][j][k],dp[i+1][j][k-1]+row[i][j]);
                if (i>0) dp[i][j][k]=min(dp[i][j][k],dp[i-1][j][k-1]+row[i-1][j]);
                if (j<m-1) dp[i][j][k]=min(dp[i][j][k],dp[i][j+1][k-1]+col[i][j]);
                if (j>0) dp[i][j][k]=min(dp[i][j][k],dp[i][j-1][k-1]+col[i][j-1]);
            }
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cout<<(l&1 ? - 1 : 2*dp[i][j][l/2])<<' ';
        }
        print("");
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


