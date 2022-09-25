#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<long long,long long> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<int> pq;
#define endl '\n'
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define MOD (ll)(1e9+7)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
const int maxN=405;
int sum[maxN][maxN],f[maxN];
int get_s(int a,int b, int c, int d){
    return sum[c][d]-sum[a-1][d]-sum[c][b-1]+sum[a-1][b-1];
}
void solve(){
    int n,m; cin>>n>>m;
    int ans=1e9+7;
    sum[0][0]=0;
    for (int i=0;i<max(n,m)+1;i++){
        sum[0][i]=0;
        sum[i][0]=0;
    }
    FOR(n){
        string s; cin>>s;
        for (int j=0;j<m;j++){
            sum[i+1][j+1]=sum[i][j+1]+sum[i+1][j]-sum[i][j] + (s[j]=='1');
        }
    }
    
    for (int i=1;i<=n;i++){
        for (int j=i+4;j<=n;j++){
            for (int k=4;k<=m;k++){
                f[k]=get_s(i+1,1,j-1,k-1)+k-1-get_s(i,1,i,k-1)+k-1-get_s(j,1,j,k-1)+j-i-1-get_s(i+1,k,j-1,k);
            }
            for (int k=m-1;k>=4;k--){
                f[k]=min(f[k],f[k+1]);
            }
            for (int k=1;k<=m-3;k++){
                int c=f[k+3]-(get_s(i+1,1,j-1,k)+k-(get_s(i,1,i,k))+k-(get_s(j,1,j,k)))+j-i-1-get_s(i+1,k,j-1,k);
                ans=min(ans,c);
            }
        }
    }
    print(ans);
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


