#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(n) for(int i=0;i<(int)(n);i++)
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
#define INF (1e8)
#define endl '\n'
#define MOD ((int)1e9+7)
using namespace std;
const int maxN=1005;
int a[maxN][maxN];
int seen[maxN][maxN];
int n,m; 
int valid(int i, int j){
    return i>-1 && i<n && j>-1 && j<m;
}
int can(int i, int j){

    int p1=valid(i,j) && valid(i+1,j) && valid(i,j+1) && valid(i+1,j+1);
    if (!p1) return false;
    vector<int> vals;
    for (int d1=0;d1<2;d1++){
        for (int d2=0;d2<2;d2++){
            if (a[i+d1][j+d2]) vals.pb(a[i+d1][j+d2]);
        }
    }
    bool ok=vals.size();
    for (int i=1;i<vals.size();i++) ok&=(vals[i]==vals[i-1]);
    return (ok ? vals[0] : ok);
}
void solve(){
    cin>>n>>m;
    memset(seen,0,sizeof(seen));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    queue<vector<int>> q;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (can(i,j)){
                q.push(vector<int>{i,j,a[i][j]});
                seen[i][j]=1;
            }
        }
    }
    vector<vector<int>> out;
    while (q.size()){
        vector<int> v=q.front();
        q.pop();
        out.pb(v);
        for (int i=0;i<2;i++){
            for (int j=0;j<2;j++){
                a[v[0]+i][v[1]+j]=0;
            }
        }
        for (int i=-2;i<=2;i++){
            for (int j=-2;j<=2;j++){
                int val=can(v[0]+i,v[1]+j);
                if (val && !seen[v[0]+i][v[1]+j]){
                    q.push(vector<int>{v[0]+i,v[1]+j,val});
                    seen[v[0]+i][v[1]+j]=1;
                }
            }
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (a[i][j]){
                print(-1);
                return;
            }
        }
    }
    cout<<out.size()<<endl;
    for (int i=out.size()-1;~i;i--){
        cout<<++out[i][0]<<' '<<++out[i][1]<<' '<<out[i][2]<<endl;
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
    while (t--) solve();
}
