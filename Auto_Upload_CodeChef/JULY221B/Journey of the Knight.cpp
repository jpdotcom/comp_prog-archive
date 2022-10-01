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
const int maxN=10;
int seen[maxN][maxN];
void solve(){
    int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
    queue<pi> q;
    q.push(make_pair(x1,y1));
    FOR(maxN){
        for (int j=0;j<maxN;j++) seen[i][j]=1e9+7;
    }
    int dx[2][2]={{-1,1},{-2,2}};
    int dy[2][2]={{-2,2},{-1,1}};
    seen[x1][y1]=0;
    while (!q.empty()){
        pi u=q.front();
        q.pop();
        int x=u.F,y=u.S;
        for (int i=0;i<2;i++){
            for (int j=0;j<2;j++){
                for (int k=0;k<2;k++){
                int nx=x+dx[i][j];
                int ny=y+dy[i][k];
                if (nx>0 && nx<9 && ny>0 && ny<9 && seen[nx][ny]==1e9+7){
                    seen[nx][ny]=seen[x][y]+1;
                    q.push(make_pair(nx,ny));
                }
                }
            }
        }
    }
    if (seen[x2][y2]<=100 && (seen[x2][y2]&1)^1) print("YES");
    else print("NO");
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


